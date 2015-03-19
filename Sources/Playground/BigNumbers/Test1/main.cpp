#include <iostream>
#include <cstring>
#include <Types/string>
#include "IntString.hpp"
#include <cmath>

/*
class IntString
{
public:
	IntString() : _number("0") {}
	IntString(const char* number)
	{
		int _length = strlen(number);
		if(_length == 0)
		{
			_number = "0";
			return;
		}
		else if(_length == 1 && number[0] == '-')
		{
			_number = "0";
			return;
		}

		while(*number == '0')
			++number;

		for( ; *number != 0; ++number)
		{
			if(isdigit(*number) || *number=='-')
				_number += *number;
		}
		if(_number == "" || _number == "-")
			_number = "0";
	}
	IntString(const std::string& number) : IntString(number.c_str()) {}
	IntString(const IntString& number) : IntString(number.value().c_str()) {}

	operator const char*() const { return _number.c_str(); }

	std::string value() const
	{
		return _number;
	}
	std::string operator-() const
	{
		if(_number[0] != '-')
			return std::string("-") + _number;
		else
			return std::string(&_number[1]);
	}

	friend std::string operator+(IntString str1, const IntString& str2); //works with 10.0 + s2
	friend std::string operator-(IntString str1, const IntString& str2); //works with 10.0 + s2
	friend std::string operator*(IntString str1, const IntString& str2); //works with 10.0 + s2
	friend std::string operator/(IntString str1, const IntString& str2); //works with 10.0 + s2
	friend std::string operator%(IntString str1, const IntString& str2); //works with 10.0 + s2

	std::string operator+=(const IntString& rhs); //works with 10.0 + s2
	std::string operator-=(const IntString& rhs); //works with 10.0 + s2
	std::string operator*=(const IntString& rhs); //works with 10.0 + s2
	std::string operator/=(const IntString& rhs); //works with 10.0 + s2
	std::string operator%=(const IntString& rhs); //works with 10.0 + s2

	friend bool operator==(const IntString& str1, const IntString& str2);
	friend bool operator!=(const IntString& str1, const IntString& str2);
	friend bool operator>(const IntString& str1, const IntString& str2);
	friend bool operator<(const IntString& str1, const IntString& str2);
	friend bool operator>=(const IntString& str1, const IntString& str2);
	friend bool operator<=(const IntString& str1, const IntString& str2);

protected:
	static std::string add(const IntString& str1, const IntString& str2)
	{
		std::string result;
		std::string val1 = str1.value();
		std::string val2 = str2.value();

		int value;
		int overflow = 0;

		int size1 = val1.size();
		int size2 = val2.size();

		while(size1 >= 0 || size2 > 0)
		{
			size1--;
			size2--;

			int v1 = 0;
			int v2 = 0;

			if(size1 >= 0)
				v1 = val1[size1] - '0';
			if(size2 >= 0)
				v2 = val2[size2] - '0';

			value = v1 + v2 + overflow;
			overflow = value / 10;
			value %= 10;

			result.insert(0, 1, value + '0');
		}

		if(overflow != 0)
			result.insert(0, 1, overflow + '0');

		size_t pos = result.find_first_not_of('0');
		if(pos < result.size())
			result = &result[pos];
		else
			result = "0";

		return result;
	}
	static std::string subtract(const IntString& str1, const IntString& str2)
	{
		std::string result;
		std::string val1 = str1.value();
		std::string val2 = str2.value();

		if(str2 > str1)
			return std::string("-") + subtract(str2, str1);

		int value;
		int overflow = 0;

		while(val1.size() > 0 || val2.size() > 0)
		{
			int v1 = 0;
			int v2 = 0;
			if(val1.size() > 0)
			{
				v1 = val1.back() - '0';
				val1.pop_back();
			}
			if(val2.size() > 0)
			{
				v2 = val2.back() - '0';
				val2.pop_back();
			}

			value = v1 - v2 - overflow;
			if(value < 0)
			{
				overflow = 1;
				value += 10;
			}
			else
				overflow = 0;

			result.insert(0, 1, value + '0');
		}

		if(overflow != 0)
		{
			result[0] = 10 - (result[0] -'0') + '0';
			result.insert(0, 1, '-');
		}

		size_t pos = result.find_first_not_of('0');
		if(pos < result.size())
			result = &result[pos];
		else
			result = "0";

		return result;
	}

private:
	std::string _number;
};

bool operator==(const IntString& str1, const IntString& str2)
{
	return (str1.value() == str2.value());
}
bool operator!=(const IntString& str1, const IntString& str2)
{
	return !(str1 == str2);
}
bool operator>(const IntString& str1, const IntString& str2)
{
	char sign1 = (str1.value()[0]=='-'?'-':'+');
	char sign2 = (str2.value()[0]=='-'?'-':'+');

	if(sign1 != sign2)
	{
		if(sign1 == '+')
			return true;
		else
			return false;
	}
	else
	{
		bool larger = false;
		if(str1.value().size() > str2.value().size())
		{
			larger = true;
		}
		else if(str1.value().size() < str2.value().size())
		{
			larger = false;
		}
		else
		{
			if(str1.value() == str2.value())
				return false;

			for(int i = 0; i < str1.value().size(); ++i)
			{
				if(str1.value()[i] > str2.value()[i])
				{
					larger = true;
					break;
				}
				else if(str1.value()[i] < str2.value()[i])
				{
					larger = false;
					break;
				}
			}
		}
		if(sign1 == '-')
			larger = !larger;

		return larger;
	}
}
bool operator<(const IntString& str1, const IntString& str2)
{
	char sign1 = (str1.value()[0]=='-'?'-':'+');
	char sign2 = (str2.value()[0]=='-'?'-':'+');

	if(sign1 != sign2)
	{
		return (sign1 != '+');
	}
	else
	{
		bool smaller;
		if(str1.value().size() > str2.value().size())
		{
			smaller = false;
		}
		else if(str1.value().size() < str2.value().size())
		{
			smaller = true;
		}
		else
		{
			if(str1.value() == str2.value())
				return false;

			for(int i = 0; i < str1.value().size(); ++i)
			{
				if(str1.value()[i] < str2.value()[i])
				{
					smaller = true;
					break;
				}
				else if(str1.value()[i] > str2.value()[i])
				{
					smaller = false;
					break;
				}
			}
		}
		if(sign1 == '-')
			smaller = !smaller;

		return smaller;
	}
}
bool operator>=(const IntString& str1, const IntString& str2)
{
	return !(str1<str2);
}
bool operator<=(const IntString& str1, const IntString& str2)
{
	return !(str1>str2);
}

std::string operator+(IntString str1, const IntString& str2)
{
	std::string val1 = str1.value();
	std::string val2 = str2.value();

	if(val1.length() == 0 || (val1.length() == 1 && val1[0] == '-'))
	{
		val1 = "0";
	}
	if(val2.length() == 0 || (val2.length() == 1 && val2[0] == '-'))
	{
		val2 = "0";
	}

	char sign1 = (val1[0]=='-'?'-':'+');
	char sign2 = (val2[0]=='-'?'-':'+');

	if(val1[0] == '-') val1 = &val1[1];
	if(val2[0] == '-') val2 = &val2[1];

	if( sign1 == sign2 )
	{
		std::string sign("");
		if(sign1 == '-')
			sign = "-";

		return (sign += IntString::add(val1, val2));
	}
	else
	{
		if(sign1 == '+')
		{
			return IntString::subtract(val1, val2);
		}
		else
		{
			return IntString::subtract(val2, val1);
		}
	}
}
std::string operator-(IntString str1, const IntString& str2)
{
	return operator+(str1, -str2);
}
std::string operator*(IntString str1, const IntString& str2)
{
	return std::string("0");
}
std::string operator/(IntString str1, const IntString& str2)
{
	return std::string("0");
}
*/

bool addTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	std::string r1 = test1 + test2;
	std::string result = std::to_string(num1+num2);

	if(r1 != result)
	{
		std::cout << num1 << " + " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool subtractTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	std::string r1 = test1 - test2;
	std::string result = std::to_string(num1-num2);

	if(r1 != result)
	{
		std::cout << num1 << " - " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool multiplyTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	std::string r1 = test1 * test2;
	std::string result = std::to_string(num1*num2);

	if(r1 != result)
	{
		std::cout << num1 << " * " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool divideTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	std::string r1 = test1 / test2;
	std::string result = std::to_string(num1/num2);

	if(r1 != result)
	{
		std::cout << num1 << " / " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool moduloTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	std::string r1 = test1 % test2;
	std::string result = std::to_string(num1%num2);

	if(r1 != result)
	{
		std::cout << num1 << " % " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}

bool equalsTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	bool r1 = test1 == test2;
	bool result = num1 == num2;

	if(r1 != result)
	{
		std::cout << num1 << " == " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool notEqualsTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	bool r1 = test1 != test2;
	bool result = num1 != num2;

	if(r1 != result)
	{
		std::cout << num1 << " != " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool largerTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	bool r1 = test1 > test2;
	bool result = num1 > num2;

	if(r1 != result)
	{
		std::cout << num1 << " > " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool smalerTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	bool r1 = test1 < test2;
	bool result = num1 < num2;

	if(r1 != result)
	{
		std::cout << num1 << " < " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool largerEqualsTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	bool r1 = test1 >= test2;
	bool result = num1 >= num2;

	if(r1 != result)
	{
		std::cout << num1 << " >= " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}
bool smalerEqualsTest(int num1, int num2)
{
	IntString test1 = std::to_string(num1);
	IntString test2 = std::to_string(num2);

	bool r1 = test1 <= test2;
	bool result = num1 <= num2;

	if(r1 != result)
	{
		std::cout << num1 << " <= " << num2 << " failed: \n"
				  << "r1: " << r1 << '\n'
				  << "result: " << result << std::endl;
		return false;
	}
}

void Test()
{
	std::cout << "IntString Test:" << std::endl;

	bool add = true;
	bool subtract = true;
	bool multiply = true;
	bool divide = true;
	bool modulo = true;
	for(int i = -50; i <= 50; ++i)
	{
		for(int j = -50; j <= 50; ++j)
		{
			add &= addTest(i, j);
			subtract &= subtractTest(i, j);
			multiply &= multiplyTest(i, j);

			if(j != 0)
			{
				divide &= divideTest(i, j);
				modulo &= moduloTest(i, j);
			}
		}
	}
	std::cout << "operator+: " << (add==true?"success":"failed") << std::endl;
	std::cout << "operator-: " << (subtract==true?"success":"failed") << std::endl;
	std::cout << "operator*: " << (multiply==true?"success":"failed") << std::endl;
	std::cout << "operator/: " << (divide==true?"success":"failed") << std::endl;
	std::cout << "operator%: " << (modulo==true?"success":"failed") << std::endl;

	IntString s1("32498345693275692372458927390568357068934756083720597859608347569879");
	IntString s2("3249834569327569237245892739056835706893475608372059785960834756987932498345693275692372458927390568357068934756083720597859608347569879");
	std::cout << "big mult test: \n(" << s1 << ") \n* (" << s2 << ") = \n" << (s1 * s2) << std::endl;

	s1 = "105614247279965074229926307584958582349257760486954273992109223138459122846095301377575463826351183002009638321809810277129889571038848680667036225017268331645632753334161861457442049407343899684788074641";
	IntString s3 = s1/s2;
	std::cout << "big div test: \n(" << s1 << ") \n/ (" << s2 << ") = \n" << s3 << "\n" << (s3 == IntString("32498345693275692372458927390568357068934756083720597859608347569879")?"success":"failed") <<std::endl;
}
bool isDivisable(IntString number, IntString divisor)
{
	return number % divisor == "0";
}
bool isPrime (IntString number)
{
	if(number < IntString("2"))
		return false;

	IntString max = number / "2";

	for (IntString i = "2"; i <= max; i += "1") // no need to go further than sqrt(number)
	{
		if (isDivisable( number, i ))
		{
			return false;
		}
	}
	return true;
}

bool isDivisable(int number, int divisor)
{
	return number % divisor == 0;
}
bool isPrime (int number)
{
	if(number < 2)
		return false;

	int max = sqrt(number);

	for (int i = 2; i <= max; ++i) // no need to go further than sqrt(number)
	{
		if (isDivisable( number, i ))
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	int maxi = 1000000000;
	for(int i = 0; i < maxi; i+=1)
	{
		if(isPrime(i))
		{
			std::cout << i << std::endl;
		}
	}
    return 0;
}
