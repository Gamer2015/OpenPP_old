namespace Openpp {
namespace Objects {
namespace Properties {

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
OType<T>::OType(const OType<T>& _rcType, OObject* const _pParent) noexcept :
    OObject(_pParent),
    _mValue((T)_rcType)
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

	return _mValue;
}

template <typename T>
T OType<T>::add(const T& _rcValue, bool _notifyParent)
{
	_mValue += _rcValue;

	if(_notifyParent == true)
		ChildChanged();

	return _mValue;
}
template <typename T>
T OType<T>::subtract(const T& _rcValue, bool _notifyParent)
{
	_mValue -= _rcValue;

	if(_notifyParent == true)
		ChildChanged();

	return _mValue;
}
template <typename T>
T OType<T>::multiply(const T& _rcValue, bool _notifyParent)
{
	_mValue *= _rcValue;

	if(_notifyParent == true)
		ChildChanged();

	return _mValue;
}
template <typename T>
T OType<T>::divide(const T& _rcValue, bool _notifyParent)
{
	_mValue /= _rcValue;

	if(_notifyParent == true)
		ChildChanged();

	return _mValue;
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
template <typename T>
T OType<T>::operator=(const OType<T>& _rcType)
{
	return set(_rcType);
}

///
/// stream
///
template <typename T>
std::ostream& operator<<(std::ostream& cout, const OType<T>& _rcType)
{
    cout << (T)_rcType;
    return cout;
}

///
/// arithmetic
///
template <typename T>
T operator++(OType<T>& _rcType)
{
    return _rcType.add(1);
}
template <typename T>
T operator++(OType<T>& _rcType, int)
{
    return _rcType.add(1) - 1;
}
template <typename T>
T operator--(OType<T>& _rcType)
{
    return _rcType.subtract(1);
}
template <typename T>
T operator--(OType<T>& _rcType, int)
{
    return _rcType.subtract(1) + 1;
}

///
/// compound assignment
///
template <typename T, typename U>
OType<T>& operator+=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType.add(_rcValue);
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator-=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType.subtract(_rcValue);
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator*=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType.multiply(_rcValue);
	return _rcLeftType;
}
template <typename T, typename U>
OType<T>& operator/=(OType<T>& _rcLeftType, const U& _rcValue)
{
	_rcLeftType.divide(_rcValue);
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
