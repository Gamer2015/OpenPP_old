#ifndef OPENPP_STD_STRING_TPP_
#define OPENPP_STD_STRING_TPP_

#include <string>

namespace std
{

/// for arithmetic types that are not chars
/// Note: for floating point numbers there are allways exactly 6 decimal places
template < class T,
		   class = typename std::enable_if<std::is_arithmetic<T>::value &&
										   !(std::is_same<char, T>::value)>::type>
std::string operator +(const string& _rcLeftString, const T& _rcRightValue)
{
	return _rcLeftString + to_string(_rcRightValue);
}

/// for arithmetic types that are not chars
/// Note: for floating point numbers there are allways exactly 6 decimal places
template < class T,
		   class = typename std::enable_if<std::is_arithmetic<T>::value &&
										  !(std::is_same<char, T>::value)>::type>
std::string operator +(const T& _rcLeftValue, const string& _rcRightString)
{
	return to_string(_rcLeftValue) + _rcRightString;
}

} // std

#endif // OPENPP_STD_STRING_TPP_
