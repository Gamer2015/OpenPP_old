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


int main(void)
{
	A a;
	B b;
	b.func = std::bind(&A::print, a);
	b.func();

	b.func = std::bind(&print);
	b.func();

    return 0;
}
