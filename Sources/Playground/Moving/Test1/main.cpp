#include <iostream>
#include <string>

void MySwap(std::string& str1, std::string& str2)
{
	size_t size = str1.size();
	const char* data = str1.data();

	str1.resize(str2.size());
	str1 = str2.data();

	str2.resize(size);
	str2 = data;
}

int main(void)
{
	std::string str1("Hallo ");
	std::string str2("Franz ");

	std::cout << str1 << str2 << std::endl;

	MySwap(str1, str2);

	std::cout << str1 << str2 << std::endl;

    return 0;
}
