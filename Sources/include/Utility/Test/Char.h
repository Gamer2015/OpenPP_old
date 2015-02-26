#ifndef LIBREPP_INCLUDE_UTILITY_TEST_CHAR_H_
#define LIBREPP_INCLUDE_UTILITY_TEST_CHAR_H_

#include "../Char.h"
#include <iostream>
#include <string>
#include <vector>

namespace LUC = Librepp::Utility::Char;

namespace Librepp
{
namespace Utility
{
namespace Char
{
namespace Test
{

bool IsCapitalTest()
{
	std::cout << "IsCapitalTest: ";

	bool success = LUC::IsCapital('A') && !(LUC::IsCapital('z'));

	if(success)
	{
		std::cout << true << std::endl;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
	return success;
}

bool IsSmallTest()
{
	std::cout << "IsSmallTest: ";

	bool success = !(LUC::IsSmall('A')) && (LUC::IsSmall('z'));

	if(success)
	{
		std::cout << true << std::endl;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
	return success;
}

bool IsLetterTest()
{
	std::cout << "IsLetterTest: ";

	bool success = LUC::IsLetter('A') && !(LUC::IsLetter('('));

	if(success)
	{
		std::cout << true << std::endl;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
	return success;
}

bool IsNumberTest()
{
	std::cout << "IsNumberTest: ";

	bool success = LUC::IsNumber('6') && !(LUC::IsNumber('z'));

	if(success)
	{
		std::cout << success << std::endl;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
	return success;
}

bool Test(std::string& rString)
{
	rString = "Sources/include/Utility/Char.h";
	bool success = true;
	std::cout << "Testing: " << rString << std::endl;
	std::vector< bool (*)() > functions;

	functions.push_back(&IsCapitalTest);
	functions.push_back(&IsSmallTest);
	functions.push_back(&IsLetterTest);
	functions.push_back(&IsNumberTest);

	for(int i = 0; i < functions.size(); i++)
	{
		success = success & functions[i]();
	}
	return success;
}

} // Test
} // Char
} // Utility
} // Librepp

#endif // LIBREPP_INCLUDE_UTILITY_TEST_CHAR_H_
