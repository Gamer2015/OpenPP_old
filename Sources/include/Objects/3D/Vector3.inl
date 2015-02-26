#include "Vector3.hpp"

namespace Openpp
{
namespace Objects
{
namespace Objects3D
{


/////
///// constructors
/////
template <typename T>
Vector3<T>::Vector3(LObject* const _pParent) :
	LObject(_pParent),
	x(this),
	y(this),
	z(this)
{}
template <typename T>
Vector3<T>::Vector3(T _x, T _y, T _z, LObject* const _pParent) :
	LObject(_pParent),
	x(_x, this),
	y(_y, this),
	z(_z, this)
{}
template <typename T>
Vector3<T>::Vector3(const Vector3<T>& _rcVector, LObject* const _pParent) :
	Vector3(_rcVector.x(), _rcVector.y(), _rcVector.z(), _pParent)
{}


/////
///// setter
/////
template <typename T>
void Vector3<T>::set(T _x, T _y, T _z, bool _notifyParent)
{
	x.set(_x, false);
	y.set(_y, false);
	z.set(_z, false);

	if(_notifyParent == true)
		LObject::ChildChanged();
}
template <typename T>
void Vector3<T>::set(const Vector3<T>& _vector, bool _notifyParent)
{
	set(_rcVector.x(), _rcVector.y(), _rcVector.z(), _notifyParent);
}
template <typename T>
void Vector3<T>::add(T _x, T _y, T _z, bool _notifyParent)
{
	set(x() + _x, y() + _y, z() + _z, _notifyParent);
}
template <typename T>
void Vector3<T>::add(const Vector3<T>& _rcVector, bool _notifyParent)
{
	set(x() + _rcVector.x(), y() + _rcVector.y(), z() + _rcVector.z(), _notifyParent);
}


/////
///// operators
/////
///
/// assignment
///
template <typename T>
Vector3<T> Vector3<T>::operator=(const Vector3<T>& _rcVector)
{
	set(_rcVector);
	return *this;
}

///
/// conversion
///
template <typename T>
template <typename U>
Vector3<T>::operator Vector3<U>() const
{
	return Vector3<U>((U)x(), (U)y(), (U)z());
}

///
/// arithmetic
///
template <typename T>
Vector3<T> Vector3<T>::operator-() const
{
	return Vector3<T>(-x(), -y(), -z());
}
template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& _rcVector) const
{
	return Vector3<T>(x() + _rcVector.x(),
					  y() + _rcVector.y(),
					  z() + _rcVector.z());
}
template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& _rcVector) const
{
	return Vector3<T>(x() - _rcVector.x(),
					  y() - _rcVector.y(),
					  z() - _rcVector.z());
}
template <typename T>
template <typename FT>
Vector3<T> Vector3<T>::operator*(FT _factor) const
{
	return Vector3<T>(x() * _factor,
					  y() * _factor,
					  z() * _factor);
}
//template <typename T>
//Vector3<T> Vector3<T>::operator*(const Vector3<T>& _rcVector) const
//{
//	return Vector3<T>(x() * _rcVector.x() - y() * _rcVector.y(),
//					  x() * _rcVector.y() + y() * _rcVector.x());
//}
template <typename T>
template <typename D>
Vector3<T> Vector3<T>::operator/(D _divisor) const
{
	return Vector3<T>(x() / _divisor,
					  y() / _divisor,
					  z() / _divisor);
}
//template <typename T>
//Vector3<T> Vector3<T>::operator/(const Vector3<T>& _rcVector) const
//{
//	return Vector3<T>((x() * _rcVector.x() + y() * _rcVector.y())/(_rcVector.lengthSquared()),
//					  (y() * _rcVector.x() - x() * _rcVector.y())/(_rcVector.lengthSquared()));
//}

///
/// comparison
///
template <typename T>
bool Vector3<T>::operator==(const Vector3<T>& _rcVector) const
{
	return ((x() == _rcVector.x()) &&
			(y() == _rcVector.y()) &&
			(z() == _rcVector.z()));
}
template <typename T>
bool Vector3<T>::operator!=(const Vector3<T>& _rcVector) const
{
	return (!(*this == _rcVector));
}
template <typename T>
bool Vector3<T>::operator>(const Vector3<T>& _rcVector) const
{
	return ((x() > _rcVector.x()) &&
			(y() > _rcVector.y()) &&
			(z() > _rcVector.z()));
}
template <typename T>
bool Vector3<T>::operator<(const Vector3<T>& _rcVector) const
{
	return ((x() < _rcVector.x()) &&
			(y() < _rcVector.y()) &&
			(z() < _rcVector.z()));
}
template <typename T>
bool Vector3<T>::operator>=(const Vector3<T>& _rcVector) const
{
	return (!(*this < _rcVector));
}
template <typename T>
bool Vector3<T>::operator<=(const Vector3<T>& _rcVector) const
{
	return (!(*this > _rcVector));
}

///
/// compound assignment
///
template <typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& _rcVector)
{
	set(*this + _rcVector);
	return *this;
}
template <typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& _rcVector)
{
	set(*this - _rcVector);
	return *this;
}
template <typename T>
template <typename FT>
Vector3<T>& Vector3<T>::operator*=(FT _factor)
{
	set(*this * _factor);
	return *this;
}
//template <typename T>
//Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& _rcVector)
//{
//	set(*this * _rcVector);
//	return *this;
//}
template <typename T>
template <typename DT>
Vector3<T>& Vector3<T>::operator/=(DT _divisor)
{
	set(*this / _divisor);
	return *this;
}
//template <typename T>
//Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& _rcVector)
//{
//	set(*this / _rcVector);
//	return *this;
//}

} // Objects3D
} // Objects
} // Openpp
