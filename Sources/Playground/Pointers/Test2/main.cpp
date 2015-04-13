#include <iostream>

class Int
{
public:
	Int() : data() {}
	Int(int var) : data(var) {}

	operator int() const
	{
		return data;
	}
	Int operator=(const Int& rhs)
	{
		data = rhs.data;
		return *this;
	}

private:
	int data;
};

int main(void)
{
	const Int& x = Int(3);
	std::cout << x << std::endl;

    return 0;
}
