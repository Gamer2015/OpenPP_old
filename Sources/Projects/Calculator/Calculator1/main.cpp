#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <Utility/String.hpp>
#include <Container/Tree.h>

namespace LUS = Openpp::Utility::String;
namespace LC = Openpp::Container;

void CreateErrorMsg(std::string Error)
{
	std::cout << Error << std::endl;
}

std::string EquationSolver(std::string Equation)
{
	std::string Result;
	LUS::ReplaceChars(Equation, "{[]}", "(())");

	if(*Equation.begin() != '-')
		Equation.insert(Equation.begin(), '+');

	int OpenBracketCount = LUS::CountChar(Equation, '(');
	int CloseBracketCount = LUS::CountChar(Equation, ')');

	if(OpenBracketCount != CloseBracketCount)
	{
		std::string ErrorMsg;

		ErrorMsg = "Syntax Error: ";

		if(OpenBracketCount > CloseBracketCount)
			ErrorMsg += "More ')' needed";
		else
			ErrorMsg += "Missing ')'";

		ErrorMsg += ".";
		std::cout << ErrorMsg;
		CreateErrorMsg(ErrorMsg);
	}

	LUS::HaveCharsBeforePattern(Equation, "(", "*/+-", '*');

	std::vector< std::string > Terms;
	Terms = LUS::SoftExplode(Equation, "()");


	return LUS::Implode(Terms, "  ");
}
namespace std
{
	std::string to_string(const std::string& str)
	{
		return str;
	}
}

template <typename I, typename T>
void PrintTree(LC::Tree<I, T> tree, std::string prefix)
{
	prefix += "/";
	std::cout << prefix << tree.value() << std::endl;

	for(typename LC::Tree<I, T>::iterator iter = tree.begin(); iter != tree.end(); ++iter)
	{
		std::string tmp = prefix;
		tmp += std::to_string(iter->first);
		PrintTree(iter->second, tmp);
	}
}

int main(int argc, char* argv[])
{
	unsigned char a = 244;
	std::cout << (int)a << std::endl;
	typedef std::string key;
	typedef std::string value;

	LC::Tree<key, value> tree("100");
	tree["0"] = "5";
	tree["0"]["1"] = "10";
	tree["1"] = "15";
	tree["1"]["0"] = "20";
	tree["1"]["0"]["0"] = "25";

	std::map<key, LC::Tree<key, value>> map;
	map = tree;
	tree["2"] = tree.value();
	tree["2"] = map;

	PrintTree(tree, "");
	std::cout << std::endl;

	LC::Tree<int, int> tree2(100);
	tree2[0] = 5;
	tree2[0][0] = 32;

	PrintTree(tree2, "");

	return 0;
}
