#ifndef OPENPP_TYPES_INTSTRING_HPP_
#define OPENPP_TYPES_INTSTRING_HPP_

#include <cstring>
#include <string>

class IntString
{
public:
	IntString();
	IntString(const char* number);
	IntString(const std::string& number);
	IntString(const IntString& number);


	std::string value() const;
	std::string operator-() const;

	friend std::string operator+(const IntString& _lhs, const IntString& _rhs); //works with 10.0 + s2
	friend std::string operator-(const IntString& _lhs, const IntString& _rhs); //works with 10.0 + s2
	friend std::string operator*(const IntString& _lhs, const IntString& _rhs); //works with 10.0 + s2
	friend std::string operator/(const IntString& _lhs, const IntString& _rhs); //works with 10.0 + s2
	friend std::string operator%(const IntString& _lhs, const IntString& _rhs); //works with 10.0 + s2

	std::string operator+=(const IntString& _rhs); //works with 10.0 + s2
	std::string operator-=(const IntString& _rhs); //works with 10.0 + s2
	std::string operator*=(const IntString& _rhs); //works with 10.0 + s2
	std::string operator/=(const IntString& _rhs); //works with 10.0 + s2
	std::string operator%=(const IntString& _rhs); //works with 10.0 + s2

	friend bool operator==(const IntString& _lhs, const IntString& _rhs);
	friend bool operator!=(const IntString& _lhs, const IntString& _rhs);
	friend bool operator>(const IntString& _lhs, const IntString& _rhs);
	friend bool operator<(const IntString& _lhs, const IntString& _rhs);
	friend bool operator>=(const IntString& _lhs, const IntString& _rhs);
	friend bool operator<=(const IntString& _lhs, const IntString& _rhs);

	operator const char*() const;

protected:
	static std::string add(const char* _lhs, const char* _rhs);
	static std::string subtract(const char* _lhs, const char* _rhs);
	static std::string multiply(const char* _lhs, const char* _rhs);
	static std::string divide(const char* _lhs, const char* _rhs);
	static std::string modulo(const char* _lhs, const char* _rhs);

private:
	std::string _number;
};

#endif // OPENPP_TYPES_INTSTRING_HPP_
