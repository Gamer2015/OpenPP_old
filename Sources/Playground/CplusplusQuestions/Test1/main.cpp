#include <exception>
#include <iostream>
#include <string>

int main()
{
	int NumberOfInputs = 20;
	int Number;
	char Letters[21];
	Letters[20] = 0; // End of String character

	for(int i = 0; i < NumberOfInputs; ++i)
	{
		std::cout << "Input " << i + 1 << ": ";
		try
		{
			if(std::cin >> Number)
			{
				if(Number < 1 || Number > 26)
					throw std::exception();
				else
					Letters[i] = (char)(Number + 64);
			}
			else
				throw std::exception();
		}
		catch(...)
		{
			Letters[i] = '#';

			std::cin.clear();
			fflush(stdin);
		}
	}
	std::cout << Letters;

	return 0;
}
