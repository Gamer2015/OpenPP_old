#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <Utility/String.hpp>

namespace LUS = Librepp::Utility::String;

void CreateErrorMsg(std::string Error)
{
	std::cout << Error << std::endl;
}

//class EquationTree
//{
//public:
//	EquationTree(std::string Data)
//		: mLayerName(Data)
//	{
//	}

//	template <typename T>
//	EquationTree& operator[](std::vector<T> AccessedLayer)
//	{
//		T Layer = *AccessedLayer.begin();
//		AccessedLayer.erase(AccessedLayer.begin());

//		return mLayers[Layer][AccessedLayer];
//	}

//	void AddLayer(std::string Data)
//	{
//		mLayers.push_back(Data);
//	}

//private:
//	std::vector< EquationTree > mLayers;
//	std::string mLayerName;
//};

//void SplitToTerms(std::string String)
//{
//	EquationTree Equation;

//	std::vector<int> Depths;
//	Depths.push_back(0);

//	for(std::string::iterator StringIter = String.begin(); StringIter != String.end(); ++StringIter)
//	{
//		if(*StringIter == '(')
//		{
//			Depths.push_back();
//		}
//		else if(*StringIter == ')')
//		{
//			Depths.pop_back();
//			Depths.back()++;
//		}
//		Depths.back()++;
//	}
//}

template<typename T>
void print(const T &data)
{
	std::cout << data << std::endl;
}
int change(const std::string& rData)
{
	return std::stoi(rData);
}
char GetOperator(const std::string& rData)
{
	return rData[0];
}
void EraseOperator(std::string& rData)
{
	rData.erase(rData.begin());
}
bool IsEmpty(const std::string& rData)
{
	if(rData.length() == 0)
		return true;
	return false;
}

/*
std::string EquationSolver(std::string Equation)
{
	std::string Result;
	LTS::ReplaceChars(Equation, "{[]}", "(())");

	if(*Equation.begin() != '-')
		Equation.insert(Equation.begin(), '+');

	int OpenBracketCount = LTS::CountChar(Equation, '(');
	int CloseBracketCount = LTS::CountChar(Equation, ')');

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

	LTS::HaveBeforePattern(Equation, "(", "*");

	std::vector< std::string > Terms;
	Terms = LTS::SoftExplode(Equation, "+-");
	//LTV::EraseWhen(Terms, IsEmpty);

	//std::vector<char> operators = LTV::MakeVector(Terms, GetOperator);

	// LTV::ModifyAll(Terms, EraseOperator);

	//std::vector<int> numbers = LTV::MakeVector(Terms, change);

	for(int i = 0; i < numbers.size(); ++i)
	{
		if(operators[i] == '-')
			numbers[i] *= -1;
	}

	//LTV::CallOnEach(numbers, print);

	//int value = LTV::GetSum(numbers);

	return std::to_string(value);
}
*/

int main(int argc, char* argv[])
{
	return 0;
}
