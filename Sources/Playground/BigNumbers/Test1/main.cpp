#include <iostream>
#include <cstring>
#include <Types/string>
#include "IntString.hpp"
#include <cmath>
#include <cstdint>

#include <Timer/Timer.hpp>


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

template <int _bytes>
class Int
{
    char ints[_bytes];
};

std::vector<int> primes;
bool isDivisable(int number, int divisor)
{
    return !(number %= divisor);
}
bool isPrime (int number)
{
    int max = sqrt(number);

    for(int i = 0; i < primes.size() && primes[i] <= max; ++i)
    {
        if (isDivisable( number, primes[i]))
        {
            return false;
        }
    }
    return true;
}
void PrintPrimes(int max)
{
    primes.push_back(2);
    for(int i = 3; i < max; i += 2)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
        }
    }
    std::cout << "primes found: " << primes.size() << std::endl;
    std::cout << "largest prime: " << primes.back() << std::endl;
}


int main(void)
{
    int Tests = 1;
    int max = 99999999;
    Timer t1;
    t1.start();
    for(int i = 0; i < Tests; ++i)
        PrintPrimes(max);
    t1.stop();
    std::cout << "time: " << t1.getElapsedTime()/Tests << " sec/Tests" << std::endl;
    primes.clear();

    return 0;
}
