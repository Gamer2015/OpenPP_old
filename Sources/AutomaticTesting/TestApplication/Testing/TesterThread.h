#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QString>
#include <vector>
#include <atomic>
#include "../Commands.h"


class TesterThread : public QThread
{
	Q_OBJECT

public:

signals:
	/// Tell the Gui about a Test
	void FoundTest(QString);

	/// Send the State of the Tested Test
	void Tested(int TestID, bool Result);


	/// Sends a Signal when the current process has finished
	void StartedScanning();

	/// Sends a Signal when the current process has finished
	void FinishedScanning();


	/// Tell the GUI that the Testing has start
	void StartedTesting();

	/// Sent a Signal when Testing is finished
	void FinishedTesting();


public slots:
	/// Get Commands from the GUI Thread
	void GetCommand(int Command, int begin=-1, int end=-1);

protected:
	/// Actual Thread Method, on bottom of the File
	void run();

private:
	/// Run Test
    void RunTest(int TestID);

    /// Run Tests that are marked as "state" (Success, Failed or untested)
    void RunTests();

    /// Run Tests that are marked as "state" (Success, Failed or untested)
    void ReadFile();

	/// Hidden implementation for Storing Test Data
	class Test
	{
	public:
		Test() : mPath(""), mSuccess(-1) { }

        void SetPath(std::string path) { mPath = path; }
		std::string GetPath() { return mPath; }

        void SetSuccess(int success) { mSuccess = success; }
		int GetSuccess() { return mSuccess; }
	private:
		std::string mPath;
		int mSuccess;
	};


	/// Get all Tests in Folder rRoot and it's subdirectories
    std::vector<Test> ScanTests(const std::string& rRoot);


	/// Check if the "NEW_COMMAND" flag is set
	bool NewCommand();


	QMutex mMutex;
	std::atomic<int> mCommand;
	int mBegin;
	int mEnd;

	std::vector<Test> mTests;
};

#endif // WORKERTHREAD_H
