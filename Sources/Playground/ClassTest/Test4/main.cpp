#include <iostream>
#include <vector>

class A;

class B
{
public:
	B(const A& a) { a.b.print(); }
	void print() const {std::cout << "hi" << std::endl;}
};

class A
{
	B b;
public:
	A() : b(*this) {}
};

int main()
{
	A a;


	return 0;
}
