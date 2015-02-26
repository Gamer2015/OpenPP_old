#include <iostream>


class A
{
	int v;
public:
	A(int a) { v = a; std::cout << "Construct A " << v << std::endl; }
	int operator()() const { return v; }
};
class B
{
	int v;
public:
	B(int b) { v = b; std::cout << "Construct B " << v << std::endl; }
	int operator()() const { return v; }
};
class C
{
	int v;
public:
	C(int c) { v = c; std::cout << "Construct C " << v << std::endl; }
	int operator()() const { return v; }
};

class D
{
public:
	D() :  b(2), a(b()), c(a()) {}

private:
	A a;
	B b;
	C c;
};

int main(void)
{
	D d;

    return 0;
}
