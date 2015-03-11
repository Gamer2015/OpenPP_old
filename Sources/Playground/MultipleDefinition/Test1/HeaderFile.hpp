#ifndef OPENPP_PLAYGROUND_MULTIPLE_DEFINITION_TEST_HEADER_FILE_HPP_
#define OPENPP_PLAYGROUND_MULTIPLE_DEFINITION_TEST_HEADER_FILE_HPP_

#include <iostream>


class TestClass
{
public:
	TestClass() : member(5) {}
	void print()
	{
		std::cout << member;
	}

private:
	int member;
};

#endif // OPENPP_PLAYGROUND_MULTIPLE_DEFINITION_TEST_HEADER_FILE_HPP_
