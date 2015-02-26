#include <iostream>

class A
{
	int i;
public:
	void print() { std::cout << "A" << i << std::endl; }
	A(int a) : i(a) {}
};
class B : public A
{
	int b;
public:
	void print() { std::cout << "B " << b << std::endl; }
	B(int a) :  A(b), b(a) {}
};

int main(int argc, char* argv[])
{
	B b(5);
	b.print();
	b.A::print();

	return 0;
}
