#ifndef OPENPP_INCLUDE_UTILITY_TEST_STRING_H_
#define OPENPP_INCLUDE_UTILITY_TEST_STRING_H_

#include "../String.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace LUS = Openpp::Utility::String;

namespace Openpp
{
namespace Utility
{
namespace Test
{

bool Result(const std::vector<std::string>& Compare, const std::vector<std::string>& Result)
{
	bool success = (Compare == Result);

	if(success == false)
	{
		std::cout << "ERROR\nPattern: " << LUS::Implode(Compare) << '\n'
						 << "Results: " << LUS::Implode(Result) << std::endl;
	}
	else
	{
		std::cout << success << std::endl;
	}
	return success;
}
bool Result(const std::string& Compare, const std::string& Result)
{
	bool success = !(Compare.compare(Result));

	if(success == false)
	{
		std::cout << "ERROR\nPattern: " << Compare << '\n'
			  << "Results: " << Result << std::endl;
	}
	else
	{
		std::cout << success << std::endl;
	}
	return success;
}
bool Result(int Compare, int Result)
{
	bool success = Compare == Result;

	if(success == false)
	{
		std::cout << "ERROR\nPattern: " << Compare << '\n'
			  << "Results: " << Result << std::endl;
	}
	else
	{
		std::cout << success << std::endl;
	}
	return success;
}

bool SplitTest()
{
	std::cout << "SplitTest: ";

	std::vector<std::string> CompareVector;
	CompareVector.push_back("Hal..");
	CompareVector.push_back("lo,..");
	CompareVector.push_back(" wi..");
	CompareVector.push_back("e g..");
	CompareVector.push_back("eht..");
	CompareVector.push_back(" es..");
	CompareVector.push_back(" di..");
	CompareVector.push_back("r?..");

	std::vector<std::string> ResultVector;
	ResultVector = LUS::Split("Hallo, wie geht es dir?", 3, "..");

	return Result(CompareVector, ResultVector);
}
bool ExplodeTest()
{
	std::cout << "ExplodeTest: ";

	std::vector<std::string> CompareVector;
	CompareVector.push_back("Hallo");
	CompareVector.push_back("");
	CompareVector.push_back("wie");
	CompareVector.push_back("geht");
	CompareVector.push_back("es");
	CompareVector.push_back("dir?");

	std::vector<std::string> ResultVector;
	ResultVector = LUS::Explode("Hallo, wie geht es dir?", ", ");

	return Result(CompareVector, ResultVector);
}
bool SoftExplodeTest()
{
	std::cout << "SoftExplodeTest: ";

	std::vector<std::string> CompareVector;
	CompareVector.push_back("Hallo");
	CompareVector.push_back(",");
	CompareVector.push_back(" wie");
	CompareVector.push_back(" geht");
	CompareVector.push_back(" es");
	CompareVector.push_back(" dir?");

	std::vector<std::string> ResultVector;
	ResultVector = LUS::SoftExplode("Hallo, wie geht es dir?", ", ");

	return Result(CompareVector, ResultVector);
}
bool ImplodeTest()
{
	std::cout << "ImplodeTest: ";

	std::string CompareString("Hallo wie geht es dir?");

	std::vector<std::string> String;
	String.push_back("Hallo");
	String.push_back("wie");
	String.push_back("geht");
	String.push_back("es");
	String.push_back("dir?");

	std::string ResultString;
	ResultString = LUS::Implode(String, " ");

	return Result(CompareString, ResultString);
}

bool RepeatTest()
{
	std::cout << "RepeatTest: ";
	bool success = true;

	std::string CompareString("Hallo Hallo Hallo ");

	std::string ResultString;
	ResultString = LUS::Repeat("Hallo ", 3);

	return Result(CompareString, ResultString);
}

bool TrimTest()
{
	std::cout << "TrimTest: ";

	std::string CompareString("Hallo,");

	std::string ResultString("&\"Hallo, !");
	LUS::Trim(ResultString, "&\" !");

	return Result(CompareString, ResultString);
}

bool ReverseTest()
{
	std::cout << "ReverseTest: ";

	std::string CompareString("Hallo");

	std::string ResultString;
	ResultString = LUS::Reverse("ollaH");

	return Result(CompareString, ResultString);
}

bool InsertBeforePatternTest()
{
	std::cout << "InsertBeforePatternTest: ";

	std::string CompareString("*(2*(5)");

	std::string ResultString("(2(5)");
	LUS::InsertBeforePattern(ResultString, "(", "*");

	return Result(CompareString, ResultString);
}
bool HaveBeforePatternTest()
{
	std::cout << "HaveBeforePatternTest: ";

	std::string CompareString("*(2*(5)");

	std::string ResultString("*(2(5)");
	LUS::HaveBeforePattern(ResultString, "(", "*");

	return Result(CompareString, ResultString);
}
bool HaveCharsBeforePatternTest()
{
	std::cout << "HaveCharsBeforePatternTest: ";

	std::string CompareString("*(*(+(*(-(/(");

	std::string ResultString("(*(+((-(/(");
	LUS::HaveCharsBeforePattern(ResultString, "(", "*/-+", '*');

	return Result(CompareString, ResultString);
}

bool ReplaceCharTest()
{
	std::cout << "ReplaceCharTest: ";

	std::string CompareString("Hallao");

	std::string ResultString("Hillio");
	LUS::ReplaceChar(ResultString, 'i', 'a');

	return Result(CompareString, ResultString);
}
bool ReplaceCharsTest()
{
	std::cout << "ReplaceCharsTest: ";

	std::string CompareString("This is a Test");

	std::string ResultString("Thas as i Test");
	LUS::ReplaceChars(ResultString, "ai", "ia");

	return Result(CompareString, ResultString);
}
bool ReplacePatternTest()
{
	std::cout << "ReplacePatternTest: ";

	std::string CompareString("Ts is a Test");

	std::string ResultString("This hiis a hiTest");
	LUS::ReplacePattern(ResultString, "hi", "");

	return Result(CompareString, ResultString);
}

bool CountCharTest()
{
	std::cout << "CharCountTest: ";

	int CompareCount = 2;

	std::string String("&\"Hallo, !");

	unsigned int ResultCount;
	ResultCount = LUS::CountChar(String, 'l');

	return Result(CompareCount, ResultCount);
}

bool EndsWithTest()
{
	std::cout << "EndsWithTest: ";

	bool success = LUS::EndsWith("HalloHallo", "lo");

	if(success)
		std::cout << success << std::endl;
	else
		std::cout << "ERROR" << std::endl;
	return success;
}
bool StartsWithTest()
{
	std::cout << "StartsWithTest: ";

	std::string String("HalloHallo");

	bool success = LUS::StartsWith(String, "Hal");

	if(success)
		std::cout << success << std::endl;
	else
		std::cout << "ERROR" << std::endl;
	return success;
}
bool HasPatternAtPositionTest()
{
	std::cout << "HasPatternAtPositionTest: ";

	bool success = LUS::HasPatternAtPosition("HalloHallo", "loH", 3);

	if(success)
		std::cout << success << std::endl;
	else
		std::cout << "ERROR" << std::endl;
	return success;
}

bool Test(std::string& rString)
{
	rString = "Sources/include/Utility/String.hpp";
	bool success = true;

	std::cout << "Testing: " << rString << std::endl;
	std::vector< bool (*)() > functions;

	functions.push_back(&SplitTest);
	functions.push_back(&ExplodeTest);
	functions.push_back(&SoftExplodeTest);
	functions.push_back(&ImplodeTest);
	functions.push_back(&RepeatTest);
	functions.push_back(&TrimTest);
	functions.push_back(&ReverseTest);
	functions.push_back(&InsertBeforePatternTest);
	functions.push_back(&HaveBeforePatternTest);
	functions.push_back(&HaveCharsBeforePatternTest);
	functions.push_back(&ReplaceCharTest);
	functions.push_back(&ReplaceCharsTest);
	functions.push_back(&ReplacePatternTest);
	functions.push_back(&CountCharTest);
	functions.push_back(&EndsWithTest);
	functions.push_back(&StartsWithTest);
	functions.push_back(&HasPatternAtPositionTest);

	for(int i = 0; i < functions.size(); i++)
	{
		success = success & functions[i]();
	}
	return success;
}

} // Test
} // String
} // Utility
} // Openpp

#endif // OPENPP_INCLUDE_UTILITY_TEST_STRING_H_
