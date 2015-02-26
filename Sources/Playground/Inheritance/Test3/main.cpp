#include <iostream>
#include <Timer/Timer.h>

template <typename T>
class OType
{

private:
	T _mValue;

public:
	LType() : _mValue()
	{
	}
	LType(const T& _rcValue) noexcept:
		_mValue(_rcValue)
	{
	}
	LType(const T&& _rcValue) noexcept :
		_mValue(std::move(_rcValue))
	{
	}
	LType(const OType<T>& _rcType) noexcept :
		_mValue(_rcType._mValue)
	{
	}
	LType(const OType<T>&& _rrcType) noexcept :
		 _mValue(std::move(_rrcType._mValue))
	{
	}
	~LType()
	{
	}

	T operator()()const
	{
		return _mValue;
	}

	T operator=(const OType<T>& _rcType)
	{
		std::cout << "op1" << std::endl;
		return _mValue = _rcType();
	}

	template <typename U>
	operator U() const
	{
		return (U)_mValue;
	}
	template <typename U>
	operator OType<U>() const
	{
		return (U)_mValue;
	}
};

int main(int argc, char* argv[])
{
	OType<float> somefloat = 15.3;
	OType<float> somefloat2 = 23.3;
	const int count = 10000;


	Timer t1;
	Timer t;
	t1.start();
	for(int i = 0; i < count; i++)
	{
		t.start();
		t.stop();
	}
	t1.stop();


	Timer t2;
	t2.start();
	for(int i = 0; i < count; i++)
		OType<float> someFloat = 22.5;
	t2.stop();

	Timer t3;
	t3.start();
	for(int i = 0; i < count; i++)
		OType<float> someOtherFloat = std::move_if_noexcept(somefloat);
	t3.stop();

	Timer t4;
	t4.start();
	for(int i = 0; i < count; i++)
		OType<float> someOtherFloat = somefloat;
	t4.stop();

	Timer t5;
	t5.start();
	for(int i = 0; i < count; i++)
		OType<float> someOtherFloat = (float)somefloat;
	t5.stop();

	Timer t6;
	t6.start();
	for(int i = 0; i < count; i++)
		somefloat = 20.5;
	t6.stop();

	Timer t7;
	t7.start();
	for(int i = 0; i < count; i++)
		somefloat = somefloat2;
	t7.stop();

	std::cout << "\n\n" << std::endl;

	std::cout << "Timer: " << t1.getElapsedTimeInMicroSec() << std::endl;
	OType<float> someFloat = 22.5;
	std::cout << "Move 1: " << t2.getElapsedTimeInMicroSec() << '\n' << std::endl;
	OType<float> someOtherMotherfuckingrandomFloat = std::move_if_noexcept(somefloat);
	std::cout << "Move 2: " << t3.getElapsedTimeInMicroSec() << '\n' << std::endl;
	OType<float> someherFloat = somefloat;
	std::cout << "Copy 2: " << t4.getElapsedTimeInMicroSec() << '\n' << std::endl;
	OType<float> someOherFloat = (float)somefloat;
	std::cout << "Move 1: " << t5.getElapsedTimeInMicroSec() << '\n' << std::endl;

	somefloat = 20.5;
	std::cout << "op2: " << t6.getElapsedTimeInMicroSec() << '\n' << std::endl;
	somefloat = somefloat2;
	std::cout << "op1: " << t7.getElapsedTimeInMicroSec() << '\n' << std::endl;

	int a = someFloat;
	std::cout << a << std::endl;

	std::cout << (float)someFloat << std::endl;

	return 0;
}
