#include "TesterThread.h"
#include <iostream>
#include <stdlib.h>
#include <boost/filesystem.hpp>
#include <Utility/String.hpp>

namespace LU = Openpp::Utility;
namespace BF = boost::filesystem;

enum TestState
{
	FAILED = 0,
	SUCCESS = 1,
	UNTESTED = -1
};

void TesterThread::GetCommand(int Command, int begin, int end)
{
	mMutex.lock();

	if(begin == -1 && end == -1)
	{
		mBegin = 0;
		mEnd = mTests.size() - 1;

		mCommand = Command;
	}
	else
	{
		begin -= 1;
		end -= 1;

		if(end < mTests.size() && begin >= 0 && begin <= end)
		{
			mBegin = begin;
			mEnd = end;

			mCommand = Command;
		}
		else
			mCommand = NO_COMMAND;
	}

	mCommand |= NEW_COMMAND;

	start();

	mMutex.unlock();
}
bool TesterThread::NewCommand()
{
	return(mCommand & NEW_COMMAND);
}

void TesterThread::RunTest(int TestID)
{
	std::cout << "Running Test " << TestID+1 << std::endl;
    mTests[TestID].SetSuccess(system(mTests[TestID].GetPath().c_str())==EXIT_SUCCESS);
    emit Tested(TestID, mTests[TestID].GetSuccess());
	std::cout << "Running Test " << TestID+1 << " finished: " << (mTests[TestID].GetSuccess()?"success":"failure") << std::endl;
}
void TesterThread::RunTests()
{
    if(NewCommand() == true)
        return;

    mMutex.lock();
	int end = mEnd;
	mMutex.unlock();

	bool TestedSomething;
	do
	{
		if(NewCommand() == true)
			return;

		mMutex.lock();
		int index = mBegin;
		mMutex.unlock();

		TestedSomething = false;
		for(index; index <= end; ++index)
		{
			if(NewCommand() == true)
				return;

			if(((mCommand & TEST_SUCCESSFUL_TESTS) && (mTests[index].GetSuccess() == SUCCESS)) ||
				((mCommand & TEST_FAILED_TESTS) && (mTests[index].GetSuccess() == FAILED)) ||
				((mCommand & TEST_UNTESTED_TESTS) && (mTests[index].GetSuccess() == UNTESTED))	)
			{
				RunTest(index);

				TestedSomething = true;
			}
		}
		if(TestedSomething == false)
			return;
	}
	while(mCommand & TEST_FOREVER);
}

void TesterThread::ReadFile()
{
    std::ifstream TestsFile("Tests.txt");

    Test mDummyTest;
    std::string line;

    if(TestsFile.is_open())
    {
        while(std::getline(TestsFile, line))
        {
            mDummyTest.SetPath(line);

            mTests.push_back(mDummyTest);
            emit FoundTest(mDummyTest.GetPath().c_str());
        }
    }
}

std::vector<TesterThread::Test> TesterThread::ScanTests(const std::string& rRoot)
{
	std::vector<Test> Tests;
	std::vector<Test> FolderTests;
	Test mDummyTest;

    if(NewCommand() == true)
		return Tests;

	// list all files in current directory.
	//You could put any file path in here, e.g. "/home/me/mwah" to list that directory
	BF::path p (rRoot);
    BF::directory_iterator end_itr;

    // cycle through the directory
    for (BF::directory_iterator itr(p); itr !=end_itr; ++itr)
    {
        if(NewCommand() == true)
            return Tests;

        /// If it is a Directory
		if(BF::is_directory(itr->path()) && !(LU::EndsWith(itr->path().string(), "3rdParty")))
        {
            FolderTests = ScanTests(itr->path().string()); /// recursivly search all Folders for Tests

            Tests.insert(Tests.end(), FolderTests.begin(), FolderTests.end());
        }
        /// If it is a regular File
        else if(BF::is_regular_file(itr->path()))
        {
			if(LU::EndsWith(itr->path().string(), "Test.exe"))
            {
                mDummyTest.SetPath(itr->path().string());

                Tests.push_back(mDummyTest);
                emit FoundTest(mDummyTest.GetPath().c_str());
            }
        }
    }

	return Tests;
}

void TesterThread::run()
{
	while(mCommand & NEW_COMMAND)
	{
		mCommand &= ~NEW_COMMAND;

		if(mCommand & SCANNING)
		{
			mCommand &= ~SCANNING;

			emit StartedScanning();

#if defined(_WIN16)||defined(_WIN32)||defined(_WIN64) // i hate Windows Backslashes ...
			mTests = ScanTests("..\\..\\Sources");
#else
			mTests = ScanTests("../../Sources");
#endif

            /// Save the found Tests in a File to prevent the need from scanning every time
            std::ofstream TestsFile("Tests.txt", std::ios_base::trunc);
            for(int i = 0; i < mTests.size(); ++i)
                TestsFile << mTests[i].GetPath() << '\n';
            TestsFile.close();

            emit FinishedScanning();
        }
		else if(mCommand == READ_FILE)
		{
            ReadFile();
        }

		else if(mCommand & TESTING)
		{
			mCommand &= ~TESTING;

            emit StartedTesting();

            RunTests();

            emit FinishedTesting();
		}
	}
}
