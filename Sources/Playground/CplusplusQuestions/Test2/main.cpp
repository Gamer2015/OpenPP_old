#include <iostream>

int main()
{
	char* Array = new char(3);

	Array[0] = 'G';
	Array[1] = 'g';
	Array[2] = 0;

	std::cout << *Array << std::endl;
	std::cout << Array[0] << std::endl;

	std::cout << *(Array+1) << std::endl;
	std::cout << Array[1] << std::endl;

	std::cout << Array << std::endl;

	return 0;
}
