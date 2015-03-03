#include <exception>
#include <iostream>
#include <string>
#include <cstdint>
#include <std/string>

int main()
{
	std::string hi ("Hallo1");
	std::string hi2 ("Hallo2");

	int number = 32;
	double someDouble = 53.4353256346454;
	char h = 'h';

	std::cout << hi + number << std::endl;
	std::cout << (hi + hi2) << std::endl;
	std::cout << (hi + someDouble) << std::endl;
	std::cout << (hi + h) << '\n' << std::endl;

	std::cout << number + hi<< std::endl;
	std::cout << (hi2 + hi) << std::endl;
	std::cout << (someDouble + hi) << std::endl;
	std::cout << (h + hi) << std::endl;

	return EXIT_SUCCESS;
}
