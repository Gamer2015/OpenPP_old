#include <iostream>
#include <types/string>
#include <vector>

namespace OT = Openpp::Types;

int main(void)
{
	OT::String str("; Hallo ;");

	std::cout << str << std::endl;
	std::cout << str.trim(" ;") << std::endl;
	std::cout << str.trimEnd(" ;") << std::endl;
	std::cout << str.trimStart(" ;") << std::endl;
	std::cout << str.reverse() << std::endl;
	std::cout << str.startsWith("; Hall") << std::endl;
	std::cout << str.endsWith("llo ;") << std::endl;

	std::cout << (str.repeat(2))  << std::endl;
	std::cout << str.toupper()  << std::endl;
	std::cout << str.tolower()  << std::endl;
	std::cout << str.contains("llo")  << std::endl;

	OT::String str2("AA;BB;CC DD;EE");
	std::vector<OT::String> vstr = str2.split(" ;");
	for(std::vector<OT::String>::iterator _iter = vstr.begin(); _iter != vstr.end(); ++_iter)
		std::cout << *_iter << std::endl;

	vstr = str2.split(4);
	for(std::vector<OT::String>::iterator _iter = vstr.begin(); _iter != vstr.end(); ++_iter)
		std::cout << *_iter << std::endl;

	return 0;
}
