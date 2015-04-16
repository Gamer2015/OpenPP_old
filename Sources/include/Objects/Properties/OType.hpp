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
#include <string>
#include <iostream>
#include <stdexcept>

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
    OType(const OType<T>&, OObject* const _pParent=nullptr) noexcept;


	///// template type
	typedef T size_type;


	///// modify data
	T set(const T&, bool _notifyParent=true);

	T add(const T&, bool _notifyParent=true);
	T subtract(const T&, bool _notifyParent=true);
	T multiply(const T&, bool _notifyParent=true);
	T divide(const T&, bool _notifyParent=true);


    ///// operators
    /// conversation
    operator T() const;

    /// assignment
    T operator=(const T& _rcValue);
    T operator=(const OType<T>& _rcType);

private:
	T _mValue;
};

/////
///// operators
/////
///
/// stream
///
template <typename T> std::ostream& operator<<(std::ostream& cout, const OType<T>& _rcType);

///
/// arithmetic
///
template <typename T> T operator++(OType<T>&);
template <typename T> T operator++(OType<T>&, int);
template <typename T> T operator--(OType<T>&);
template <typename T> T operator--(OType<T>&, int);

///
/// compound assignment
///
template <typename T, typename U> OType<T>& operator+=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator-=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator*=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator/=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator%=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator&=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator|=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator^=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator<<=(OType<T>&, const U&);
template <typename T, typename U> OType<T>& operator>>=(OType<T>&, const U&);

} // Properties
} // Objects
} // Openpp

#include "OType.tpp"

#endif // OPENPP_OBJECTS_PROPERTIES_OType_H_
