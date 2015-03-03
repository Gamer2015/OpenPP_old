#include "String.hpp"
#include <vector>
#include <iostream>

namespace ST = std::Test;

int main(void)
{
	bool success = true;
	std::cout << "Testing: Sources/include/std\n" << std::endl;
	std::vector< bool (*)(std::string&) > functions;
	functions.push_back(&ST::StringTest);

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

	std::cout << "Summary:" << std::endl;
	for(int i = 0; i < Results.size(); ++i)
	{
		std::cout << Names[i];
		if(Results[i])
			std::cout << "success";
		else
			std::cout << "ERROR!";
		std::cout << std::endl;
	}
	return !(success);
}
