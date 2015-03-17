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

	int Ints[2][2] = { {1, 2}, {3, 4} };

	Ints[1][1] = 10;
	Ints[0][3] = 15;

	std::cout << Ints[1][1] << std::endl;

	std::cout << *((int*)(&Ints)) << std::endl;
	std::cout << &Ints[0] << std::endl;
	std::cout << &Ints[1] << std::endl;
	for(int i = 0; i < 2; ++i)
		std::cout << &Ints[0][i] << std::endl;
	for(int i = 0; i < 2; ++i)
		std::cout << &Ints[1][i] << std::endl;

	int** pInts = new int*[2];
	pInts[0] = new int[2];
	pInts[1] = new int[2];

	pInts[1][1] = 10;
	pInts[0][3] = 15; // this block is NOT [1][1] because the addresses of the 3 pointers also have to be stored somewhere.

	std::cout << pInts[1][1] << std::endl; // wuhuu 10!

	std::cout << &pInts << std::endl;
	std::cout << &pInts[0] << std::endl;
	std::cout << &pInts[1] << std::endl;
	for(int i = 0; i < 2; ++i)
		std::cout << &pInts[0][i] << std::endl;
	for(int i = 0; i < 2; ++i)
		std::cout << &pInts[1][i] << std::endl;

	int array2[4][4];
	array2[3][3] = 16;
	std::cout << ((int*)&array2)[15] << std::endl;
	std::cout << (array2[0][15] == array2[3][3]) << std::endl;

	int value = *((array + 3 * sizeof(array[0])) + 3);
	std::cout << (value == array2[3][3]) << std::endl;
	std::cout << (value == array2[0][3*sizeof(array[0]) + 3]) << std::endl;

    return 0;
}
