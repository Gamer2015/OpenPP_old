#ifndef OPENPP_OBJECTS_PROPERTIES_OTYPE_HPP_
#define OPENPP_OBJECTS_PROPERTIES_OTYPE_HPP_

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

#include "../OObject.hpp"
#include <utility>
#include <iostream>

namespace Openpp
{
namespace Objects
{
namespace Properties
{

template <typename T>
class OType : public OObject
{
public:
	///// constructors
    OType(OObject* const _pParent=nullptr) noexcept;
    OType(const T&, OObject* const _pParent=nullptr) noexcept;
    OType(const T&&, OObject* const _pParent=nullptr) noexcept;
    OType(const OType<T>& _rcType, OObject* const _pParent=nullptr) noexcept;
    OType(const OType<T>&& _rrcType, OObject* const _pParent=nullptr) noexcept;


	///// template type
	typedef T size_type;


	///// modify data
	template <typename U>
	void set(const U&, bool _notifyParent=true);
	template <typename U>
    void set(const OType<U>&, bool _notifyParent=true);

	///// get data
	T operator()() const;
	T operator-() const;
	T operator+() const;


	///// conversation
	template <typename U>
    operator OType<U>() const;
	template <typename U>
	operator U() const;


	///// operators
	/// assignment
	template <typename U>
    T operator=(const OType<U>& _rcType);
    T operator=(const OType<T>& _rcType);

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
template <typename T> std::ostream& operator<<(std::ostream&, const OType<T>&);

///
/// arithmetic
///
template <typename T, typename U> T operator+(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator+(const OType<T>&, const U&);
template <typename T, typename U> T operator+(const T&, const OType<U>&);

template <typename T, typename U> T operator-(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator-(const OType<T>&, const U&);
template <typename T, typename U> T operator-(const T&, const OType<U>&);

template <typename T, typename U> T operator*(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator*(const OType<T>&, const U&);
template <typename T, typename U> T operator*(const T&, const OType<U>&);

template <typename T, typename U> T operator/(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator/(const OType<T>&, const U&);
template <typename T, typename U> T operator/(const T&, const OType<U>&);

template <typename T, typename U> T operator%(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator%(const OType<T>&, const U&);
template <typename T, typename U> T operator%(const T&, const OType<U>&);

template <typename T> T operator++(OType<T>&);
template <typename T> T operator++(OType<T>&, int);
template <typename T> T operator--(OType<T>&);
template <typename T> T operator--(OType<T>&, int);

///
/// comparison
///
template <typename T, typename U> bool operator==(const OType<T>&, const OType<U>&);
template <typename T, typename U> bool operator==(const OType<T>&, const U&);
template <typename T, typename U> bool operator==(const T&, const OType<U>&);

template <typename T, typename U> bool operator!=(const OType<T>&, const OType<U>&);
template <typename T, typename U> bool operator!=(const OType<T>&, const U&);
template <typename T, typename U> bool operator!=(const T&, const OType<U>&);

template <typename T, typename U> bool operator<(const OType<T>&, const OType<U>&);
template <typename T, typename U> bool operator<(const OType<T>&, const U&);
template <typename T, typename U> bool operator<(const T&, const OType<U>&);

template <typename T, typename U> bool operator>(const OType<T>&, const OType<U>&);
template <typename T, typename U> bool operator>(const OType<T>&, const U&);
template <typename T, typename U> bool operator>(const T&, const OType<U>&);

template <typename T, typename U> bool operator<=(const OType<T>&, const OType<U>&);
template <typename T, typename U> bool operator<=(const OType<T>&, const U&);
template <typename T, typename U> bool operator<=(const T&, const OType<U>&);

template <typename T, typename U> bool operator>=(const OType<T>&, const OType<U>&);
template <typename T, typename U> bool operator>=(const OType<T>&, const U&);
template <typename T, typename U> bool operator>=(const T&, const OType<U>&);

///
/// logic
///
template <typename T> bool operator!(const OType<T>&);

template <typename T, typename U> bool operator&&(const OType<T>&, const OType<U>&);
template <typename T, typename U> bool operator&&(const OType<T>&, const U&);
template <typename T, typename U> bool operator&&(const T&, const OType<U>&);

template <typename T, typename U> bool operator||(const OType<T>&, const OType<U>&);
template <typename T, typename U> bool operator||(const OType<T>&, const U&);
template <typename T, typename U> bool operator||(const T&, const OType<U>&);

///
/// bit operations
///
template <typename T> T operator~(const OType<T>&);

template <typename T, typename U> T operator&(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator&(const OType<T>&, const U&);
template <typename T, typename U> T operator&(const T&, const OType<U>&);

template <typename T, typename U> T operator|(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator|(const OType<T>&, const U&);
template <typename T, typename U> T operator|(const T&, const OType<U>&);

template <typename T, typename U> T operator^(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator^(const OType<T>&, const U&);
template <typename T, typename U> T operator^(const T&, const OType<U>&);

template <typename T, typename U> T operator<<(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator<<(const OType<T>&, const U&);
template <typename T, typename U> T operator<<(const T&, const OType<U>&);

template <typename T, typename U> T operator>>(const OType<T>&, const OType<U>&);
template <typename T, typename U> T operator>>(const OType<T>&, const U&);
template <typename T, typename U> T operator>>(const T&, const OType<U>&);

///
/// compound assignment
///
template <typename T, typename U> OType<T>& operator+=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator+=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator-=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator-=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator*=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator*=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator/=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator/=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator%=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator%=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator&=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator&=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator|=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator|=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator^=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator^=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator<<=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator<<=(OType<T>&, const U&);

template <typename T, typename U> OType<T>& operator>>=(OType<T>&, const OType<U>&);
template <typename T, typename U> OType<T>& operator>>=(OType<T>&, const U&);

} // Properties
} // Objects
} // Openpp

#include "OType.inl"

#endif // OPENPP_OBJECTS_PROPERTIES_OType_H_
