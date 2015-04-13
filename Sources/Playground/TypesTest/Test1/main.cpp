#include <iostream>
#include <typeinfo>

class A
{};
class B
{};
class C
{};

class Vector2
{

};

int main(void)
{
	A a;
	B b;
	C c;

	Vector2 v;

	std::cout << "A: " << typeid(a).name() << "\n"
			  << "B: " << typeid(b).name() << "\n"
			  << "C: " << typeid(c).name() << "\n"
			  << "C: " << typeid(v).name() << std::endl;

	std::cout << "A: " << typeid(A).name() << "\n"
			  << "B: " << typeid(B).name() << "\n"
			  << "C: " << typeid(C).name() << "\n"
			  << "C: " << typeid(Vector2).name() << std::endl;

    return 0;
}
