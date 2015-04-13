#include <iostream>
#include <functional>

class A
{
public:
	void print() const // in A
	{
		std::cout << "Hallo A" << std::endl;
	}
};
void print() // global
{
	std::cout << "Hallo" << std::endl;
}

class B
{
public:

	std::function<void()> func;
};
void Test1()
{
	A a;
	B b;
	b.func = std::bind(&A::print, a);
	b.func();

	b.func = std::bind(&print);
	b.func();
}

namespace n1
{

void test() { std::cout << "n1::Test" << std::endl; }

}
void Test2()
{
	void (*pTest)();
	pTest = n1::test;
	pTest();
}

int main(void)
{
	Test2();
	return 0;
}
