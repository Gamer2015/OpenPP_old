#include <iostream>

int main(void)
{
	int array[30000] = { 200, 400, 600 };
	array[6001] = 6;
	array[12001] = 12;
	array[18001] = 18;
	array[24001] = 24;
	array[29999] = 999;

	int** pointer = new int*[5];
	for(int i = 0; i < 5; ++i)
		pointer[i] = &array[6000*i];

	std::cout << pointer[0][2] << ' ' << pointer[1][1] << ' ' << pointer[2][1] << ' ' << pointer[3][1] << ' ' << pointer[4][1] << ' ' << pointer[4][5999] << std::endl;

	int NewArray[5][6000];
	memcpy(&NewArray, &array, sizeof(NewArray));

	std::cout << NewArray[0][2] << ' ' << NewArray[1][1] << ' ' << NewArray[2][1] << ' ' << NewArray[3][1] << ' ' << NewArray[4][1] << ' ' << NewArray[4][5999] << std::endl;

	pointer[4][6000] = 255;

	std::cout << array[0] << std::endl;
	std::cout << NewArray[0][29999] << std::endl;

    return 0;
}
