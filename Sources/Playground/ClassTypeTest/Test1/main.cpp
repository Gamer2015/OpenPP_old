#include <iostream>

template <typename T>
class Type
{
public:
	Type() : _mData() {}
	Type(T a) : _mData(a) {}

	operator T() {return _mData;}
	operator const char* const() { return _mData.c_str();}

private:
	T _mData;
};

class Text
{
public:
	Text() : _mData() {}
	Text(std::string a) : _mData(a) {}

	operator std::string() {return _mData;}
	operator const char* const() { return _mData.c_str();}

private:
	std::string _mData;
};

int main(void)
{
	Text i("Hi");
	std::string text = i;

	std::cout << text << std::endl;

    return 0;
}
