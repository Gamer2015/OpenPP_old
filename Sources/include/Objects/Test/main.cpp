#include "OObject.hpp"
#include <vector>
#include <iostream>

namespace OT = Openpp::Test;

int main(void)
{
	bool success = true;
	std::cout << "Testing: Sources/include/Objects" << std::endl;
	std::vector< bool (*)(std::string&) > functions;
	functions.push_back(&OT::Test);

	std::vector<std::string> Names;
	std::string Name;
	std::vector< bool > Results;

	for(int i = 0; i < functions.size(); i++)
	{
		Results.push_back(functions[i](Name));
		Names.push_back(Name);
		success = Results.back() && success;

		std::cout << std::endl;
	}

	std::cout << "Summary:" << std::endl;
	for(int i = 0; i < Results.size(); ++i)
	{
		std::cout << Names[i] << ": " << Results[i] << std::endl;
	}
	return !(success);
}
