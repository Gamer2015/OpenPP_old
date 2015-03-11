#include <iostream>

class A
{
public:
	void pub()
	{
		std::cout << "A" << std::endl;
	}
};
class B : private A
{
public:
	using A::pub;
};

int main(void)
{
	B b;
	b.pub();

	return 0;
}
