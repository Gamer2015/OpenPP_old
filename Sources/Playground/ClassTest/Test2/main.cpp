#include <iostream>
#include <vector>

class A
{
public:
	A() : _parent(nullptr)
	{

	}
	A(A* parent) : _parent(parent)
	{

	}
	A(const A& other)
	{
		*this = other;
	}
	void print() const
	{
		std::cout << "parent address: " << _parent << std::endl;
	}

private:
	A* _parent;
};

int main(void)
{
	A a;
	a.print();

	A b(&a);
	b.print();

	A c(b);
	c.print();

    return 0;
}
