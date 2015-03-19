#include "IntString.hpp"
#include <iostream>

///
/// constructors
///
IntString::IntString() : _number("0") { }
IntString::IntString(const char *number)
{
	int _length = strlen(number);
	if(_length == 0)
	{
		_number = "0";
		return;
	}
	else if(_length == 1 && number[0] == '-')
	{
		_number = "0";
		return;
	}

	while(*number == '0')
		++number;

	for( ; *number != 0; ++number)
	{
		if(isdigit(*number) || *number=='-')
			_number += *number;
	}

	if(_number == "" || _number == "-")
		_number = "0";
}
IntString::IntString(const std::string &number) : IntString(number.c_str()) {}
IntString::IntString(const IntString &number) : IntString(number.value()) {}

///
/// getter
///
std::string IntString::value() const { return _number; }

/////
///// operators
/////
///
/// arithmetic
///
std::string IntString::operator -() const
{
	if(_number[0] != '-')
		return std::string("-") + _number;
	else
		return std::string(&_number[1]);
}

std::string operator+(const IntString& _lhs, const IntString& _rhs)
{
	char sign1 = '+';
	char sign2 = '+';

	const char* val1 = _lhs.value().c_str();
	const char* val2 = _rhs.value().c_str();

	if(*val1 == '-')
	{
		++val1;
		sign1 = '-';
	}
	if(*val2 == '-')
	{
		++val2;
		sign2 = '-';
	}


	if( sign1 == sign2 )
	{
		std::string sign("");
		if(sign1 == '-')
			sign = "-";

		return (sign += IntString::add(val1, val2));
	}
	else
	{
		if(sign1 == '+')
		{
			return IntString::subtract(val1, val2);
		}
		else
		{
			return IntString::subtract(val2, val1);
		}
	}
}
std::string operator-(const IntString& _lhs, const IntString& _rhs)
{
	std::string result;

	char sign1 = '+';
	char sign2 = '+';

	const char* val1 = _lhs.value().c_str();
	const char* val2 = _rhs.value().c_str();

	if(*val1 == '-')
	{
		++val1;
		sign1 = '-';
	}
	if(*val2 == '-')
	{
		++val2;
		sign2 = '-';
	}

	if( sign1 == sign2 )
	{
		std::string sign("");
		if(sign1 == '-')
			sign = "-";

		result = (sign += IntString::subtract(val1, val2));
	}
	else
	{
		std::string sign("");
		if(sign1 == '-')
			sign = "-";
		result = (sign += IntString::add(val2, val1));
	}

	if(result[0] == result[1] && result[1] == '-')
		result.erase(0, 2);

	if(result == "-0")
		result = "0";

	return result;
}
std::string operator*(const IntString& _lhs, const IntString& _rhs)
{
	std::string result;

	char sign1 = '+';
	char sign2 = '+';

	const char* val1 = _lhs.value().c_str();
	const char* val2 = _rhs.value().c_str();

	if(*val1 == '-')
	{
		++val1;
		sign1 = '-';
	}
	if(*val2 == '-')
	{
		++val2;
		sign2 = '-';
	}

	if( sign1 == sign2 )
	{
		result = IntString::multiply(val1, val2);
	}
	else
	{
		result = (std::string("-") += IntString::multiply(val1, val2));
	}

	if(result[0] == result[1] && result[1] == '-')
		result.erase(0, 2);

	if(result == "-0")
		result = "0";

	return result;
}
std::string operator/(const IntString& _lhs, const IntString& _rhs)
{
	std::string result;

	char sign1 = '+';
	char sign2 = '+';

	const char* val1 = _lhs.value().c_str();
	const char* val2 = _rhs.value().c_str();

	if(*val1 == '-')
	{
		++val1;
		sign1 = '-';
	}
	if(*val2 == '-')
	{
		++val2;
		sign2 = '-';
	}

	if( sign1 == sign2 )
	{
		result = IntString::divide(val1, val2);
	}
	else
	{
		result = (std::string("-") += IntString::divide(val1, val2));
	}

	if(result[0] == result[1] && result[1] == '-')
		result.erase(0, 2);

	if(result == "-0")
		result = "0";

	return result;
}
std::string operator%(const IntString& _lhs, const IntString& _rhs)
{
	std::string result;

	char sign1 = '+';
	char sign2 = '+';

	const char* val1 = _lhs.value().c_str();
	const char* val2 = _rhs.value().c_str();

	if(*val1 == '-')
	{
		++val1;
		sign1 = '-';
	}
	if(*val2 == '-')
	{
		++val2;
		sign2 = '-';
	}

	if( sign1 == '+' )
	{
		result = IntString::modulo(val1, val2);
	}
	else
	{
		result = (std::string("-") += IntString::modulo(val1, val2));
	}

	if(result[0] == result[1] && result[1] == '-')
		result.erase(0, 2);

	if(result == "-0")
		result = "0";

	return result;

	return std::string("error");
}

std::string IntString::operator+=(const IntString& _rhs)
{
	*this = *this + _rhs;
	return this->value();
}
std::string IntString::operator-=(const IntString& _rhs)
{
	*this = *this - _rhs;
	return this->value();
}
std::string IntString::operator*=(const IntString& _rhs)
{
	*this = *this * _rhs;
	return this->value();
}
std::string IntString::operator/=(const IntString& _rhs)
{
	*this = *this / _rhs;
	return this->value();
}
std::string IntString::operator%=(const IntString& _rhs)
{
	*this = *this % _rhs;
	return this->value();
}

///
/// rational
///
bool operator==(const IntString& _lhs, const IntString& _rhs)
{
	return (_lhs.value() == _rhs.value());
}
bool operator!=(const IntString& _lhs, const IntString& _rhs)
{
	return !(_lhs == _rhs);
}
bool operator>(const IntString& _lhs, const IntString& _rhs)
{
	char sign1 = (_lhs.value()[0]=='-'?'-':'+');
	char sign2 = (_rhs.value()[0]=='-'?'-':'+');

	if(sign1 != sign2)
	{
		if(sign1 == '+')
			return true;
		else
			return false;
	}
	else
	{
		bool larger = false;
		if(_lhs.value().size() > _rhs.value().size())
		{
			larger = true;
		}
		else if(_lhs.value().size() < _rhs.value().size())
		{
			larger = false;
		}
		else
		{
			if(_lhs == _rhs)
				return false;

			for(int i = 0; i < _lhs.value().size(); ++i)
			{
				if(_lhs.value()[i] > _rhs.value()[i])
				{
					larger = true;
					break;
				}
				else if(_lhs.value()[i] < _rhs.value()[i])
				{
					larger = false;
					break;
				}
			}
		}
		if(sign1 == '-')
			larger = !larger;

		return larger;
	}
}
bool operator<(const IntString& _lhs, const IntString& _rhs)
{
	return !(_lhs > _rhs || _lhs == _rhs);
}
bool operator>=(const IntString& _lhs, const IntString& _rhs)
{
	return !(_lhs < _rhs);
}
bool operator<=(const IntString& _lhs, const IntString& _rhs)
{
	return !(_lhs > _rhs);
}

///
/// conversion
///
IntString::operator const char *() const
{
	return _number.c_str();
}

///
/// protected
///
std::string IntString::add(const char* _lhs, const char* _rhs)
{
	std::string result;

	int value;
	int overflow = 0;

	int size1 = strlen(_lhs);
	int size2 = strlen(_rhs);

	while(size1 >= 0 || size2 > 0)
	{
		size1--;
		size2--;

		int v1 = 0;
		int v2 = 0;

		if(size1 >= 0)
			v1 = _lhs[size1] - '0';
		if(size2 >= 0)
			v2 = _rhs[size2] - '0';

		value = v1 + v2 + overflow;
		overflow = value / 10;
		value %= 10;

		result.insert(0, 1, value + '0');
	}

	if(overflow != 0)
		result.insert(0, 1, overflow + '0');

	size_t pos = result.find_first_not_of('0');
	if(pos < result.size())
		result = &result[pos];
	else
		result = "0";

	return result;
}
std::string IntString::subtract(const char* _lhs, const char* _rhs)
{
	IntString temp1(_lhs);
	IntString temp2(_rhs);

	if(temp2 > temp1)
	{
		return std::string("-") + IntString::subtract(_rhs, _lhs);
	}

	std::string result;

	int value;
	int overflow = 0;

	int size1 = strlen(_lhs);
	int size2 = strlen(_rhs);

	while(size1 > 0 || size2 > 0)
	{
		size1--;
		size2--;

		int v1 = 0;
		int v2 = 0;

		if(size1 >= 0)
			v1 = _lhs[size1] - '0';
		if(size2 >= 0)
			v2 = _rhs[size2] - '0';

		value = v1 - v2 - overflow;
		if(value < 0)
		{
			overflow = 1;
			value += 10;
		}
		else
			overflow = 0;

		result.insert(0, 1, value + '0');
	}

	if(overflow != 0)
	{
		result[0] = 10 - (result[0] -'0') + '0';
		result.insert(0, 1, '-');
	}

	size_t pos = result.find_first_not_of('0');
	if(pos < result.size())
		result = &result[pos];
	else
		result = "0";

	return result;
}
std::string IntString::multiply(const char* _lhs, const char* _rhs)
{
	IntString result("0");

	int size1 = strlen(_lhs);
	int size2 = strlen(_rhs);

	int value;
	int overflow = 0;

	for(int i = size1 - 1; i >= 0; --i)
	{
		int v1 = _lhs[i] - '0';

		IntString temp;
		temp._number = std::string(size1 - i - 1, '0');

		for(int j = size2 - 1; j >= 0; --j)
		{
			int v2 = _rhs[j] - '0';

			value = v1 * v2 + overflow;
			overflow = value / 10;
			value %= 10;

			temp._number.insert(0, 1, value + '0');
		}
		if(overflow)
			temp._number.insert(0, 1, overflow + '0');
		overflow = 0;

		result += temp;
	}

	if(overflow > 0)
		result._number.insert(0, 1, overflow + '0');

	return result.value();
}
std::string IntString::divide(const char* _lhs, const char* _rhs)
{
	IntString result("0");
	IntString divident(_lhs);
	IntString divisor(_rhs);

	if(divisor == IntString("0"))
		return std::string("error");

	if(divident < divisor)
		return result.value();

	int size1 = strlen(_lhs);
	int size2 = strlen(_rhs);

	divident = std::string("");
	divident._number.erase(0, 1);

	for(int i = 0; i < size1; ++i)
	{
		result *= "10";

		size_t pos = result.value().find_first_not_of('0');
		if(pos < result.value().size())
			result._number = &result._number[pos];
		else
			result = "0";

		divident._number.push_back(_lhs[i]);

		pos = divident.value().find_first_not_of('0');
		if(pos < divident.value().size())
			divident._number = &divident._number[pos];
		else
			divident = "0";

		while(divident >= divisor)
		{
			divident -= divisor;
			result += "1";
		}
	}
	return result.value();
}
std::string IntString::modulo(const char* _lhs, const char* _rhs)
{
	IntString result("0");
	IntString divident("");
	IntString divisor(_rhs);

	if(divisor == IntString("0"))
		return std::string("error");

	int size1 = strlen(_lhs);
	int size2 = strlen(_rhs);

	divident._number.erase(0, 1);

	for(int i = 0; i < size1; ++i)
	{
		size_t pos = result.value().find_first_not_of('0');
		if(pos < result.value().size())
			result._number = &result._number[pos];
		else
			result = "0";

		divident._number.push_back(_lhs[i]);

		pos = divident.value().find_first_not_of('0');
		if(pos < divident.value().size())
			divident._number = &divident._number[pos];
		else
			divident = "0";

		while(divident >= divisor)
		{
			divident -= divisor;
		}
	}
	return divident.value();
}

