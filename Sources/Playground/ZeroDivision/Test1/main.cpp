#include <iostream>
#include <stdexcept>

template <typename T>
T div_throw_zero(T _divident, T _divisor, const char* const _file = 0, int _line = 0)
{
	if(_divisor == 0)
		throw std::overflow_error(std::string("zero_division in File ") + _file + " in line " + std::to_string(_line).c_str());

	return (_divident/_divisor);
}
#ifndef save_div
	#define save_div(_v1, _v2) div_throw_zero(_v1, _v2, __FILE__, __LINE__)
#else
	#error "save_div previously defined!"
#endif

int main ()
{
	float a = 20;
	float b = 0.000000001;
	int c;
	std::cout << (c = save_div(a, b)) << std::endl;

	return 0;
}
