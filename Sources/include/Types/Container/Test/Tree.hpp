#ifndef OPENPP_INCLUDE_UTILITY_TEST_STRING_H_
#define OPENPP_INCLUDE_UTILITY_TEST_STRING_H_

#include "../Tree.hpp"
#include "../../../Objects/Properties/OType.tpp"
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
    std::cout << prefix << tree << std::endl;

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
    size += sizeof(tree);

	for(typename Tree<_id, _data>::const_iterator iter = tree.begin(); iter != tree.end(); ++iter)
	{
		size += GetSize(iter->second);
	}
	return size;
}

class SomeObject
{
public:
    SomeObject() : name(), position() {}
    SomeObject(std::string _name, std::string _position) : name(_name), position(_position)
    {}
    void print() { std::cout << name << ' ' << position << std::endl; }
    std::string name;
    std::string position;
};

bool IteratorTest(std::string& rString)
{
	rString = "IteratorTest";
	std::cout << rString << std::endl;
    bool success = true;

    Openpp::Objects::Properties::OType<std::string> sf("Hallo");
    std::cout << sf << std::endl;
/*
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
*/
    Tree<std::string, SomeObject> tree2;
    tree2->name = "Manager";
    tree2["branch1"]["Leaf1"] = SomeObject("Manager", "Herbert");
    tree2["branch1"]["Leaf1"].get().print();
    tree2["branch1"]["Leaf2"]->name = "John";
    tree2["branch1"]["Leaf3"]->position = "Christian";
    tree2["branch1"]["Leaf3"]->print();
    tree2["branch2"]["Leaf1"]->name = "Stefan";
    tree2["branch2"]["Leaf2"]->name = "Martin";
    tree2["branch2"]["Leaf3"]->name = "Daniel";
    tree2["branch3"]["Leaf1"]->name = "David";
    tree2["branch3"]["Leaf2"]->name = "Marco";
    tree2["branch3"]["Leaf3"]->name = "Deen";
    tree2["super"]["mega"]["large"]["branch"]["Leaf1"]->position = "Deen";

    Tree<std::string, SomeObject> tree3;
    tree3 = SomeObject("Manager", "Bert");
    tree3->print();

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
