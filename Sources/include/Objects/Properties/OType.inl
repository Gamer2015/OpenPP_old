#include "OType.hpp"

namespace Openpp
{
namespace Objects
{
namespace Properties
{

/////
///// constructors
/////
template <typename T>
OType<T>::OType(OObject* const _pParent) noexcept :
	OObject(_pParent),
	_mValue()
{}
template <typename T>
OType<T>::OType(const T& _rcValue, OObject* const _pParent) noexcept :
    OObject(_pParent),
    _mValue(_rcValue)
{}
template <typename T>
OType<T>::OType(const T&& _rrcValue, OObject* const _pParent) noexcept :
    OObject(_pParent),
    _mValue(std::move(_rrcValue))
{}
template <typename T>
OType<T>::OType(const OType<T>& _rcType, OObject* const _pParent) noexcept :
    OObject(_pParent),
    _mValue((T)_rcType)
{}
template <typename T>
OType<T>::OType(const OType<T>&& _rrcType, OObject* const _pParent) noexcept :
    OObject(_pParent),
    _mValue(std::move((T)_rrcType))
{}


/////
///// modify data
/////
template <typename T>
T OType<T>::set(const T& _rcValue, bool _notifyParent)
{
	_mValue = _rcValue;

	if(_notifyParent == true)
		ChildChanged();

    return *this;
}


/////
///// operators
/////
///
/// conversion
///
template <typename T>
OType<T>::operator T() const
{
    return _mValue;
}

///
/// assignment
///
template <typename T>
T OType<T>::operator=(const T& _rcValue)
{
    return set(_rcValue);
}

///
/// arithmetic
///
template <typename T>
T operator++(OType<T>& _rcType)
{
    _rcType.set(_rcType + 1);
	return _rcType;
}
template <typename T>
T operator++(OType<T>& _rcType, int)
{
    T result(_rcType);
	++_rcType;
	return result;
}
template <typename T>
T operator--(OType<T>& _rcType)
{
    _rcType.set(_rcType - 1);
	return _rcType;
}
template <typename T>
T operator--(OType<T>& _rcType, int)
{
    T result(_rcType);
	--_rcType;
	return result;
}

///
/// compound assignment
///
template <typename T, typename U>
OType<T>& operator+=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType + _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator-=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType - _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator*=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType * _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator/=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType / _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator%=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType % _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator&=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType & _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator|=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType | _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator^=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType ^ _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator<<=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType << _rcValue;
    return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator>>=(OType<T>& _rcLeftType, const U& _rcValue)
{
    _rcLeftType = _rcLeftType >> _rcValue;
    return _rcLeftType;
}


} // Properties
} // Objects
} // Openpp
