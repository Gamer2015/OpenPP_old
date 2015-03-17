#ifndef OPENPP_INCLUDE_UTILITY_TEST_STRING_H_
#define OPENPP_INCLUDE_UTILITY_TEST_STRING_H_

#include "../Tree.hpp"
#include <iostream>
#include <std/string>
#include <vector>

namespace Openpp
{
namespace Types
{
namespace Container
{
namespace Test
{

template <typename _id, typename _data>
void PrintTree(const Tree<_id, _data>& tree, std::string prefix = "")
{
	prefix += "/";
	std::cout << prefix << tree.value() << std::endl;

	for(typename Tree<_id, _data>::const_iterator iter = tree.begin(); iter != tree.end(); ++iter)
	{
		std::string tmp = prefix;
		tmp += std::to_string(iter->first);
		PrintTree(iter->second, tmp);
	}
}

template <typename _id, typename _data>
unsigned int GetSize(const Tree<_id, _data>& tree)
{
	unsigned int size = sizeof(tree);
	size += sizeof(tree.value());

	for(typename Tree<_id, _data>::const_iterator iter = tree.begin(); iter != tree.end(); ++iter)
	{
		size += GetSize(iter->second);
	}
	return size;
}


bool IteratorTest(std::string& rString)
{
	rString = "IteratorTest";
	std::cout << rString << std::endl;
	bool success = true;

	Tree<std::string, std::string> tree;
	tree = "Manager";
	tree["branch1"]["Leaf1"] = "Herbert";
	tree["branch1"]["Leaf2"] = "John";
	tree["branch1"]["Leaf3"] = "Christian";
	tree["branch2"]["Leaf1"] = "Stefan";
	tree["branch2"]["Leaf2"] = "Martin";
	tree["branch2"]["Leaf3"] = "Daniel";
	tree["branch3"]["Leaf1"] = "David";
	tree["branch3"]["Leaf2"] = "Marco";
	tree["branch3"]["Leaf3"] = "Deen";
	tree["super"]["mega"]["large"]["branch"]["Leaf1"] = "Deen";

	PrintTree(tree);
	std::cout << "tree size: " << GetSize(tree) << std::endl;

	Tree<std::string, std::string> tree2;
	tree2 = "Manager";
	tree2["branch1"]["Leaf1"] = "Herbert";
	tree2["branch1"]["Leaf2"] = "John";
	tree2["branch1"]["Leaf3"] = "Christian";
	tree2["branch2"]["Leaf1"] = "Stefan";
	tree2["branch2"]["Leaf2"] = "Martin";
	tree2["branch2"]["Leaf3"] = "Daniel";
	tree2["branch3"]["Leaf1"] = "David";
	tree2["branch3"]["Leaf2"] = "Marco";
	tree2["branch3"]["Leaf3"] = "Deen";
	tree2["super"]["mega"]["large"]["branch"]["Leaf1"] = "Deen";

	PrintTree(tree2);
	std::cout << "tree size: " << GetSize(tree2) << std::endl;

	return true;
}

bool TreeTest(std::string& rString)
{
	rString = "Sources/Types/Container/Tree.hpp";
	std::cout << rString << std::endl;
	bool success = true;
	std::vector< bool (*)(std::string&) > functions;
	functions.push_back(&IteratorTest);

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

} // Test
} // String
} // Utility
} // Openpp

#endif // OPENPP_INCLUDE_UTILITY_TEST_STRING_H_
