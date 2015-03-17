#include <iostream>
#include <cmath>

bool isDivisible (int number, int divisor)
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
		if (isDivisible( number, i ))
		{
			return false;
		}
	}
	return true;
}

bool isPrime2 (int number)
{
	for (int i = sqrt((double)number); i < number; i++)
		{
			if (isDivisible(number, i))
			{
				return false;
			}
		}
		return true;
}
int PrimeFactorSum (int number)
{
	int sum = 0;
	bool factorFound = false;

	for (int i = 2; i <= number; ++i) // number may also be a prime
	{
		if ( isDivisible( number, i ) )
		{
			if(factorFound)
				std::cout << "+"; // ugly output

			std::cout << i; // ugly output
			sum += i;                   // add the sum
			number /= i;               // decrease the number
			i--;                             // same factor may occure more than once;
			factorFound = true;
		}
	}
	if(sum==0)
		std::cout << "0";

	return sum;
}

bool PrimeTest(int _max_number)
{
	for(int i = 0; i < _max_number; ++i)
	{
		if(isPrime2(i) != isPrime(i))
			return false;
	}
	return true;
}

void PrintPrimes(int _max_number)
{
	std::cout << "Primes{ ";
	for(int i = 0; i < _max_number; ++i)
	{
		if(isPrime(i))
			std::cout << i << ',';
	}
	std::cout << "}" << std::endl;
}
void PrintPrimes2(int _max_number)
{
	std::cout << "Primes2{ ";
	for(int i = 0; i < _max_number; ++i)
	{
		if(isPrime2(i))
			std::cout << i << ',';
	}
	std::cout << "}" << std::endl;
}

int main()
{
	PrintPrimes(20);
	PrintPrimes2(20);
	std::cout << (PrimeTest(20)?"success":"failed") << std::endl;


//	for(int i = 0; i < 1000; ++i)
//	{
//		std::cout << "prime factos of " << i << ": ";

//		int sum = PrimeFactorSum(i);
//		bool prime = isPrime(sum);

//		std::cout << " = " << sum << ": ";
//		if(!prime)
//			std::cout << " not ";
//		std::cout << " a Prime" << std::endl;
//	}

	return 0;
}
