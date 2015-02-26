#include "Vector2.hpp"

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{


/////
///// constructors
/////
template <typename T>
Vector2<T>::Vector2(LObject* const _pParent) :
	LObject(_pParent),
	x(this),
	y(this)
{}
template <typename T>
Vector2<T>::Vector2(T _x, T _y, LObject* const _pParent) :
	LObject(_pParent),
	x(_x, this),
	y(_y, this)
{}
template <typename T>
Vector2<T>::Vector2(const Vector2<T>& _rcVector, LObject* const _pParent) :
	Vector2(_rcVector.x(), _rcVector.y(), _pParent)
{}


/////
///// setter
/////
template <typename T>
void Vector2<T>::set(T _x, T _y, bool _notifyParent)
{
	x.set(_x, false);
	y.set(_y, false);

	if(_notifyParent == true)
		LObject::ChildChanged();
}
template <typename T>
void Vector2<T>::set(const Vector2<T>& _rcVector, bool _notifyParent)
{
	set(_rcVector.x(), _rcVector.y, _notifyParent);
}
template <typename T>
void Vector2<T>::add(T _x, T _y, bool _notifyParent)
{
	set(x + _x, y + _y, _notifyParent);
}
template <typename T>
void Vector2<T>::add(const Vector2<T>& _rcVector, bool _notifyParent)
{
	set(x + _rcVector.x, y + _rcVector.y, _notifyParent);
}

/////
///// operators
/////
///
/// assignment
///
template <typename T>
Vector2<T> Vector2<T>::operator=(const Vector2<T>& _rcVector)
{
	set(_rcVector);
	return *this;
}

///
/// conversion
///
template <typename T>
template <typename U>
Vector2<T>::operator Vector2<U>() const
{
	return Vector2<U>((U)x(), (U)y());
}

///
/// arithmetic
///
template <typename T>
Vector2<T> Vector2<T>::operator-() const
{
	return Vector2<T>(-x(), -y());
}
template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& _rcVector) const
{
	return Vector2<T>(x() + _rcVector.x(),
					  y() + _rcVector.y());
}
template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& _rcVector) const
{
	return Vector2<T>(x() - _rcVector.x(),
					  y() - _rcVector.y());
}
template <typename T>
template <typename FT>
Vector2<T> Vector2<T>::operator*(FT _factor) const
{
	return Vector2<T>(x() * _factor,
					  y() * _factor);
}
template <typename T>
Vector2<T> Vector2<T>::operator*(const Vector2<T>& _rcVector) const
{
	return Vector2<T>(x() * _rcVector.x() - y() * _rcVector.y(),
					  x() * _rcVector.y() + y() * _rcVector.x());
}
template <typename T>
template <typename D>
Vector2<T> Vector2<T>::operator/(D _divisor) const
{
	return Vector2<T>(x() / _divisor,
					  y() / _divisor);
}
template <typename T>
Vector2<T> Vector2<T>::operator/(const Vector2<T>& _rcVector) const
{
	return Vector2<T>((x() * _rcVector.x() + y() * _rcVector.y())/(_rcVector.lengthSquared()),
					  (y() * _rcVector.x() - x() * _rcVector.y())/(_rcVector.lengthSquared()));
}

///
/// comparison
///
template <typename T>
bool Vector2<T>::operator==(const Vector2<T>& _rcVector) const
{
	return ((x() == _rcVector.x())&&
			(y() == _rcVector.y()));
}
template <typename T>
bool Vector2<T>::operator!=(const Vector2<T>& _rcVector) const
{
	return (!(*this == _rcVector));
}
template <typename T>
bool Vector2<T>::operator>(const Vector2<T>& _rcVector) const
{
	return ((x() > _rcVector.x())&&
			(y() > _rcVector.y()));
}
template <typename T>
bool Vector2<T>::operator<(const Vector2<T>& _rcVector) const
{
	return ((x() < _rcVector.x()) &&
			(y() < _rcVector.y()));
}
template <typename T>
bool Vector2<T>::operator>=(const Vector2<T>& _rcVector) const
{
	return (!(*this < _rcVector));
}
template <typename T>
bool Vector2<T>::operator<=(const Vector2<T>& _rcVector) const
{
	return (!(*this > _rcVector));
}


///
/// compound assignment
///
template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& _rcVector)
{
	add(_rcVector);
	return *this;
}
template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& _rcVector)
{
	add(-_rcVector);
	return *this;
}
template <typename T>
template <typename FT>
Vector2<T>& Vector2<T>::operator*=(FT _factor)
{
	set(*this * _factor);
	return *this;
}
template <typename T>
Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& _rcVector)
{
	set(*this * _rcVector);
	return *this;
}
template <typename T>
template <typename DT>
Vector2<T>& Vector2<T>::operator/=(DT _divisor)
{
	set(*this / _divisor);
	return *this;
}
template <typename T>
Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& _rcVector)
{
	set(*this / _rcVector);
	return *this;
}

} // Objects2D
} // Objects
} // Librepp
