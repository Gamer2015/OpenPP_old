#ifndef Openpp_OBJECTS_PROPERTIES_LTYPE_HPP_
#define Openpp_OBJECTS_PROPERTIES_LTYPE_HPP_

/********************************************\
 * usage: type property for primitive types in LObjects
 * date: 20th of February 2015
 * author: Stefan Kreiner
 * _______________________________________________
 *
 * Notes:
 *  - not tested
 *  - intended for primitive types
 *
\********************************************/

#include "../LObject.hpp"
#include <utility>

namespace Openpp
{
namespace Objects
{
namespace Properties
{

template <typename T>
class LType : public LObject
{
public:
	///// constructors
	LType(LObject* const _pParent=nullptr) noexcept;
	LType(const T&, LObject* const _pParent=nullptr) noexcept;
	LType(const T&&, LObject* const _pParent=nullptr) noexcept;
	LType(const LType<T>& _rcType, LObject* const _pParent=nullptr) noexcept;
	LType(const LType<T>&& _rrcType, LObject* const _pParent=nullptr) noexcept;


	///// template type
	typedef T size_type;


	///// modify data
	template <typename U>
	void set(const U&, bool _notifyParent=true);
	template <typename U>
	void set(const LType<U>&, bool _notifyParent=true);

	///// get data
	T operator()() const;
	T operator-() const;
	T operator+() const;


	///// conversation
	template <typename U>
	operator LType<U>() const;
	template <typename U>
	operator U() const;


	///// operators
	/// assignment
	template <typename U>
	T operator=(const LType<U>& _rcType);
	T operator=(const LType<T>& _rcType);

	template <typename U>
	T operator=(const U&);
	T operator=(const T&);

private:
	T _mValue;
};

/////
///// operators
/////
///
/// streams
///
template <typename T> std::ostream& operator<<(std::ostream&, const LType<T>&);

///
/// arithmetic
///
template <typename T, typename U> T operator+(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator+(const LType<T>&, const U&);
template <typename T, typename U> T operator+(const T&, const LType<U>&);

template <typename T, typename U> T operator-(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator-(const LType<T>&, const U&);
template <typename T, typename U> T operator-(const T&, const LType<U>&);

template <typename T, typename U> T operator*(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator*(const LType<T>&, const U&);
template <typename T, typename U> T operator*(const T&, const LType<U>&);

template <typename T, typename U> T operator/(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator/(const LType<T>&, const U&);
template <typename T, typename U> T operator/(const T&, const LType<U>&);

template <typename T, typename U> T operator%(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator%(const LType<T>&, const U&);
template <typename T, typename U> T operator%(const T&, const LType<U>&);

template <typename T> T operator++(LType<T>&);
template <typename T> T operator++(LType<T>&, int);
template <typename T> T operator--(LType<T>&);
template <typename T> T operator--(LType<T>&, int);

///
/// comparison
///
template <typename T, typename U> bool operator==(const LType<T>&, const LType<U>&);
template <typename T, typename U> bool operator==(const LType<T>&, const U&);
template <typename T, typename U> bool operator==(const T&, const LType<U>&);

template <typename T, typename U> bool operator!=(const LType<T>&, const LType<U>&);
template <typename T, typename U> bool operator!=(const LType<T>&, const U&);
template <typename T, typename U> bool operator!=(const T&, const LType<U>&);

template <typename T, typename U> bool operator<(const LType<T>&, const LType<U>&);
template <typename T, typename U> bool operator<(const LType<T>&, const U&);
template <typename T, typename U> bool operator<(const T&, const LType<U>&);

template <typename T, typename U> bool operator>(const LType<T>&, const LType<U>&);
template <typename T, typename U> bool operator>(const LType<T>&, const U&);
template <typename T, typename U> bool operator>(const T&, const LType<U>&);

template <typename T, typename U> bool operator<=(const LType<T>&, const LType<U>&);
template <typename T, typename U> bool operator<=(const LType<T>&, const U&);
template <typename T, typename U> bool operator<=(const T&, const LType<U>&);

template <typename T, typename U> bool operator>=(const LType<T>&, const LType<U>&);
template <typename T, typename U> bool operator>=(const LType<T>&, const U&);
template <typename T, typename U> bool operator>=(const T&, const LType<U>&);

///
/// logic
///
template <typename T> bool operator!(const LType<T>&);

template <typename T, typename U> bool operator&&(const LType<T>&, const LType<U>&);
template <typename T, typename U> bool operator&&(const LType<T>&, const U&);
template <typename T, typename U> bool operator&&(const T&, const LType<U>&);

template <typename T, typename U> bool operator||(const LType<T>&, const LType<U>&);
template <typename T, typename U> bool operator||(const LType<T>&, const U&);
template <typename T, typename U> bool operator||(const T&, const LType<U>&);

///
/// bit operations
///
template <typename T> T operator~(const LType<T>&);

template <typename T, typename U> T operator&(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator&(const LType<T>&, const U&);
template <typename T, typename U> T operator&(const T&, const LType<U>&);

template <typename T, typename U> T operator|(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator|(const LType<T>&, const U&);
template <typename T, typename U> T operator|(const T&, const LType<U>&);

template <typename T, typename U> T operator^(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator^(const LType<T>&, const U&);
template <typename T, typename U> T operator^(const T&, const LType<U>&);

template <typename T, typename U> T operator<<(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator<<(const LType<T>&, const U&);
template <typename T, typename U> T operator<<(const T&, const LType<U>&);

template <typename T, typename U> T operator>>(const LType<T>&, const LType<U>&);
template <typename T, typename U> T operator>>(const LType<T>&, const U&);
template <typename T, typename U> T operator>>(const T&, const LType<U>&);

///
/// compound assignment
///
template <typename T, typename U> LType<T>& operator+=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator+=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator-=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator-=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator*=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator*=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator/=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator/=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator%=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator%=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator&=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator&=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator|=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator|=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator^=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator^=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator<<=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator<<=(LType<T>&, const U&);

template <typename T, typename U> LType<T>& operator>>=(LType<T>&, const LType<U>&);
template <typename T, typename U> LType<T>& operator>>=(LType<T>&, const U&);

} // Properties
} // Objects
} // Openpp

#include "LType.inl"

#endif // Openpp_OBJECTS_PROPERTIES_LTYPE_H_
