#include <iostream>
#include <cstring>
#include <Types/string>
#include <cmath>
#include <cstdint>

bool prime (uint64_t number)
{
	if(number < 2)
		return false;

	uint64_t max = sqrt(number);

	for (uint64_t i = 2; i <= max; ++i) // no need to go further than sqrt(number)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	unsigned int maxi = 500;
	for(unsigned int i = 2; i < maxi; ++i)
	{
		uint64_t number = i;

		bool mult7 = (number % 7) == 0;
		bool mult6 = ((number - 9) % 6) == 0;
		bool mult5 = (number % 5) == 0;
		bool mult2 = (number % 2) == 0;
		int rest100 = number % 100;

		if(!mult2 && !mult5 && !mult6 && !mult7)
		{
			if(!prime(number))
				std::cout << "no prime: at i = " << i << " (" << number << ")" << std::endl;
		}
	}
    return 0;
}
