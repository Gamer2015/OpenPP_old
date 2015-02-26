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
	_mValue(_rcType())
{}
template <typename T>
OType<T>::OType(const OType<T>&& _rrcType, OObject* const _pParent) noexcept :
	OObject(_pParent),
	_mValue(std::move(_rrcType()))
{}


/////
///// modify data
/////
template <typename T>
template <typename U>
void OType<T>::set(const U& _rcValue, bool _notifyParent)
{
	_mValue = _rcValue;

	if(_notifyParent == true)
		ChildChanged();
}
template <typename T>
template <typename U>
void OType<T>::set(const OType<U>& _rcType, bool _notifyParent)
{
	set(_rcType(), _notifyParent);
}

/////
///// get data
/////
template <typename T>
T OType<T>::operator()() const
{
	return _mValue;
}
template <typename T>
T OType<T>::operator-() const
{
	return -(*this)();
}
template <typename T>
T OType<T>::operator+() const
{
	return (*this)();
}


/////
///// conversion
/////
template <typename T>
template <typename U>
OType<T>::operator OType<U>() const
{
return OType<U>((U)(*this)());
}
template <typename T>
template <typename U>
OType<T>::operator U() const
{
return (U)(*this)();
}

/////
///// operators
/////
///
/// streams
///
template <typename T>
std::ostream& operator<<(std::ostream& _rOutputStream, const OType<T>& _rcType)
{
	_rOutputStream << _rcType();
	return _rOutputStream;
}

///
/// arithmetic
///
template <typename T>
template <typename U>
T OType<T>::operator=(const OType<U>& _rcType)
{
	set(_rcType);
	return (*this);
}
template <typename T>
template <typename U>
T OType<T>::operator=(const U& _rcValue)
{
	set(_rcValue);
	return (*this);
}
template <typename T>
T OType<T>::operator=(const OType<T>& _rcType)
{
	set(_rcType);
	return (*this);
}
template <typename T>
T OType<T>::operator=(const T& _rcValue)
{
	set(_rcValue);
	return (*this);
}

template <typename T, typename U>
T operator+(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() + _rcRightType();
}
template <typename T, typename U>
T operator+(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() + _rcValue;
}
template <typename T, typename U>
T operator+(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue + _rcRightType();
}

template <typename T, typename U>
T operator-(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() - _rcRightType();
}
template <typename T, typename U>
T operator-(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() - _rcValue;
}
template <typename T, typename U>
T operator-(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue - _rcRightType();
}

template <typename T, typename U>
T operator*(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() * _rcRightType();
}
template <typename T, typename U>
T operator*(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() * _rcValue;
}
template <typename T, typename U>
T operator*(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue * _rcRightType();
}

template <typename T, typename U>
T operator/(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() / _rcRightType();
}
template <typename T, typename U>
T operator/(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() / _rcValue;
}
template <typename T, typename U>
T operator/(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue / _rcRightType();
}

template <typename T, typename U>
T operator%(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() % _rcRightType();
}
template <typename T, typename U>
T operator%(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() % _rcValue;
}
template <typename T, typename U>
T operator%(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue % _rcRightType();
}

template <typename T>
T operator++(OType<T>& _rcType)
{
	_rcType.set(_rcType() + 1);
	return _rcType;
}
template <typename T>
T operator++(OType<T>& _rcType, int)
{
	T result(_rcType());
	++_rcType;
	return result;
}
template <typename T>
T operator--(OType<T>& _rcType)
{
	_rcType.set(_rcType() - 1);
	return _rcType;
}
template <typename T>
T operator--(OType<T>& _rcType, int)
{
	T result(_rcType());
	--_rcType;
	return result;
}

///
/// comparison
///
template <typename T, typename U>
bool operator==(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() == _rcRightType();
}
template <typename T, typename U>
bool operator==(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() == _rcValue;
}
template <typename T, typename U>
bool operator==(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue == _rcRightType();
}

template <typename T, typename U>
bool operator!=(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() != _rcRightType();
}
template <typename T, typename U>
bool operator!=(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() != _rcValue;
}
template <typename T, typename U>
bool operator!=(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue != _rcRightType();
}

template <typename T, typename U>
bool operator<(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() < _rcRightType();
}
template <typename T, typename U>
bool operator<(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() < _rcValue;
}
template <typename T, typename U>
bool operator<(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue < _rcRightType();
}

template <typename T, typename U>
bool operator>(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() > _rcRightType();
}
template <typename T, typename U>
bool operator>(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() > _rcValue;
}
template <typename T, typename U>
bool operator>(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue > _rcRightType();
}

template <typename T, typename U>
bool operator<=(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() <= _rcRightType();
}
template <typename T, typename U>
bool operator<=(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() <= _rcValue;
}
template <typename T, typename U>
bool operator<=(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue <= _rcRightType();
}

template <typename T, typename U>
bool operator>=(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() >= _rcRightType();
}
template <typename T, typename U>
bool operator>=(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() >= _rcValue;
}
template <typename T, typename U>
bool operator>=(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue >= _rcRightType();
}

///
/// logic
///
template <typename T>
bool operator!(const OType<T>& _rcType)
{
	return !(_rcType());
}

template <typename T, typename U>
bool operator&&(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() && _rcRightType();
}
template <typename T, typename U>
bool operator&&(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() && _rcValue;
}
template <typename T, typename U>
bool operator&&(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue && _rcRightType();
}

template <typename T, typename U>
bool operator||(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() || _rcRightType();
}
template <typename T, typename U>
bool operator||(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() || _rcValue;
}
template <typename T, typename U>
bool operator||(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue || _rcRightType();
}

///
/// bit operations
///
template <typename T>
T operator~(const OType<T>& _rcType)
{
	return ~(_rcType());
}

template <typename T, typename U>
T operator&(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() & _rcRightType();
}
template <typename T, typename U>
T operator&(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() & _rcValue;
}
template <typename T, typename U>
T operator&(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue & _rcRightType();
}

template <typename T, typename U>
T operator|(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() | _rcRightType();
}
template <typename T, typename U>
T operator|(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() | _rcValue;
}
template <typename T, typename U>
T operator|(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue | _rcRightType();
}

template <typename T, typename U>
T operator^(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() ^ _rcRightType();
}
template <typename T, typename U>
T operator^(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() ^ _rcValue;
}
template <typename T, typename U>
T operator^(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue ^ _rcRightType();
}

template <typename T, typename U>
T operator<<(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() << _rcRightType();
}
template <typename T, typename U>
T operator<<(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() << _rcValue;
}
template <typename T, typename U>
T operator<<(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue << _rcRightType();
}

template <typename T, typename U>
T operator>>(const OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	return _rcLeftType() >> _rcRightType();
}
template <typename T, typename U>
T operator>>(const OType<T>& _rcLeftType, const U& _rcValue)
{
	return _rcLeftType() >> _rcValue;
}
template <typename T, typename U>
T operator>>(const T& _rcValue, const OType<U>& _rcRightType)
{
	return _rcValue >> _rcRightType();
}

///
/// compound assignment
///
template <typename T, typename U>
OType<T>& operator+=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() + _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator+=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() + _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator-=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() - _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator-=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() - _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator*=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() * _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator*=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() * _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator/=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() / _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator/=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() / _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator%=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() % _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator%=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() % _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator&=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() & _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator&=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() & _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator|=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() | _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator|=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() | _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator^=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() ^ _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator^=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() ^ _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator<<=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() << _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator<<=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() << _rcValue;
	return _rcLeftType;
}

template <typename T, typename U>
OType<T>& operator>>=(OType<T>& _rcLeftType, const OType<U>& _rcRightType)
{
	_rcLeftType = _rcLeftType() >> _rcRightType();
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator>>=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType = _rcLeftType() >> _rcValue;
	return _rcLeftType;
}


} // Properties
} // Objects
} // Openpp
