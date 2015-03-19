#include <iostream>
#include <cmath>
#include <vector>

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
std::vector<int> getPrimeFactors(int number)
{
	int max = sqrt(number);
	std::vector<int> primes;

	for(int i = 2; i <= max; ++i) // loop through same numbers as isPrime to get prime factors
	{
		if(isPrime(number)) // check if the number is a prime Factor
		{
			primes.push_back(number); // add element to container
			break; // break for-loop
		}

		if(isPrime(i)) // if it is a prime
		{
			if(isDivisable(number, i)) // and divisable, then it is a prime factor of number
			{
				number /= i;
				primes.push_back(i); // add element to container

				i--; // check same factor again
			}
		}
	}
	return primes;
}

int main(void)
{
	for(int i = 0; i <= 1000; ++i)
	{
		std::cout << i;
		if(isPrime(i))
		{
			std::cout << " -> is a Prime." << std::endl;
		}
		else
		{
			std::vector<int> factors;
			factors = getPrimeFactors(i);

// do the printing work
			int sum = 0;

			std::cout << ": ";
			for(int i = 0; i < factors.size(); ++i)
			{
				std::cout << factors[i] << ' '; // print the factors
				sum += factors[i]; // add the factors up
			}
			std::cout << " = " << sum << " -> ";

			if(isPrime(sum))
				std::cout << "sum of factors is a Prime";
			else
				std::cout << "sum of factors is not a Prime";

			std::cout << std::endl;
		}
	}
}
/*#include <iostream>
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

	for(int i = 0; i <= 1000; ++i)
	{
		std::cout << "prime factos of " << i << ": ";

		int sum = PrimeFactorSum(i);
		bool prime = isPrime(sum);

		std::cout << " = " << sum << ": ";
		if(!prime)
			std::cout << " not ";
		std::cout << " a Prime" << std::endl;
	}

	return 0;
}*/
