#ifndef OPENPP_STD_TEST_STRING_HPP_
#define OPENPP_STD_TEST_STRING_HPP_

#include "../String.tpp"
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace std
{
namespace Test
{

bool Test(const std::string& rPlanned, const std::string rResult)
{
	if(rPlanned == rResult)
	{
		std::cout << "success" << std::endl;
		return true;
	}
	else
	{
		std::cout << "ERROR!" << "\n\tplanned: " << rPlanned << "\n\tresult : " << rResult << std::endl;
		return false;
	}
}

bool StringPlusValueTest(std::string& rString)
{
	rString = "StringPlusValueTest: ";
	std::cout << rString << std::endl;
	bool success = true;

	std::string str("Value = ");
	std::string result;

	std::cout << "uint8_t Test: ";
	uint8_t u8 = 8;
	result = str + "8";
	success &= Test(result, str + u8);

	std::cout << "uint16_t Test: ";
	uint16_t u16 = 16;
	result = str + "16";
	success &= Test(result, str + u16);

	std::cout << "uint32_t Test: ";
	uint32_t u32 = 32;
	result = str + "32";
	success &= Test(result, str + u32);

	std::cout << "uint64_t Test: ";
	uint64_t u64 = 64;
	result = str + "64";
	success &= Test(result, str + u64);


	std::cout << "int8_t Test: ";
	int8_t i8 = -8;
	result = str + "-8";
	success &= Test(result, str + i8);

	std::cout << "int16_t Test: ";
	int16_t i16 = -16;
	result = str + "-16";
	success &= Test(result, str + i16);

	std::cout << "int32_t Test: ";
	int32_t i32 = -32;
	result = str + "-32";
	success &= Test(result, str + i32);

	std::cout << "int64_t Test: ";
	int64_t i64 = -64;
	result = str + "-64";
	success &= Test(result, str + i64);


	std::cout << "float Test: ";
	float f = 0.18634;
	result = str + "0.186340";
	success &= Test(result, str + f);

	std::cout << "double Test: ";
	double d = 1.18634;
	result = str + "1.186340";
	success &= Test(result, str + d);

	std::cout << "long double Test: ";
	long double ld = 2.18634;
	result = str + "2.186340";
	success &= Test(result, str + ld);

	return success;
}
bool ValuePlusStringTest(std::string& rString)
{
	rString = "ValuePlusStringTest: ";
	std::cout << rString << std::endl;
	bool success = true;

	std::string str(" = Value");
	std::string result;

	std::cout << "uint8_t Test: ";
	uint8_t u8 = 8;
	result = "8" + str;
	success &= Test(result, u8 + str);

	std::cout << "uint16_t Test: ";
	uint16_t u16 = 16;
	result = "16" + str;
	success &= Test(result, u16 + str);

	std::cout << "uint32_t Test: ";
	uint32_t u32 = 32;
	result = "32" + str;
	success &= Test(result, u32 + str);

	std::cout << "uint64_t Test: ";
	uint64_t u64 = 64;
	result = "64" + str;
	success &= Test(result, u64 + str);


	std::cout << "int8_t Test: ";
	int8_t i8 = -8;
	result = "-8" + str;
	success &= Test(result, i8 + str);

	std::cout << "int16_t Test: ";
	int16_t i16 = -16;
	result = "-16" + str;
	success &= Test(result, i16 + str);

	std::cout << "int32_t Test: ";
	int32_t i32 = -32;
	result = "-32" + str;
	success &= Test(result, i32 + str);

	std::cout << "int64_t Test: ";
	int64_t i64 = -64;
	result = "-64" + str;
	success &= Test(result, i64 + str);


	std::cout << "float Test: ";
	float f = 0.18634;
	result = "0.186340" + str;
	success &= Test(result, f + str);

	std::cout << "double Test: ";
	double d = 1.186346;
	result = "1.186346" + str;
	success &= Test(result, d + str);

	std::cout << "long double Test: ";
	long double ld = 2.18634;
	result = "2.186340" + str;
	success &= Test(result, ld + str);

	return success;
}

bool StringTest(std::string& rString)
{
	rString = "Sources/include/std/String.tpp: ";
	bool success = true;

	std::cout << "Testing: " << rString << std::endl;
	std::vector< bool (*)(std::string&) > functions;
	functions.push_back(&StringPlusValueTest);
	functions.push_back(&ValuePlusStringTest);

	std::vector<std::string> Names;
	std::string Name;
	std::vector< bool > Results;

	for(int i = 0; i < functions.size(); i++)
	{
		Results.push_back(functions[i](Name));
		Names.push_back(Name);
		success &= Results.back();

		std::cout << std::endl;
	}

	std::cout << "Function Summary:" << std::endl;
	for(int i = 0; i < Results.size(); ++i)
	{
		std::cout << Names[i];
		if(Results[i])
			std::cout << "success";
		else
			std::cout << "ERROR!";
		std::cout << std::endl;
	}
	return success;
}

} // Test
} // std

#endif // OPENPP_STD_TEST_STRING_HPP_
