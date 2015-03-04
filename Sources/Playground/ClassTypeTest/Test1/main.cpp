#include <iostream>

template <typename T>
class Type
{
public:
    Type() : _mData() {}
    Type(T a) : _mData(a) {}

    operator T() {return _mData;}

private:
    T _mData;
};

int main(void)
{
    Type<float> i(20);
    i = 25;
    i = 25.4;
    i = 25.3 + i;

    i = 20;

    std::cout << (i == 20.0) << std::endl;

    return 0;
}
