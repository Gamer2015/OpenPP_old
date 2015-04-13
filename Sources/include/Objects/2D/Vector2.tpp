namespace Openpp
{
namespace Objects
{
namespace Objects2D
{


/////
///// constructors
/////
template <typename T>
Vector2<T>::Vector2(OObject* const _pParent) :
	Vector2(0, 0, _pParent)
{}
template <typename T>
Vector2<T>::Vector2(T _x, T _y, OObject* const _pParent) :
	OObject(_pParent),
	x(_x, this),
	y(_y, this),
	angle(this)
{}
template <typename T>
Vector2<T>::Vector2(const Vector2<T>& _rcVector, OObject* const _pParent) :
	Vector2(_rcVector.x, _rcVector.y, _pParent)
{}


/////
///// setter
/////
template <typename T>
void Vector2<T>::set(T _x, T _y, bool _notifyParent)
{
	x.set(_x, false);
	y.set(_y, false);
	angle.set(atan2(y, x), false);

	if(_notifyParent == true)
		OObject::ChildChanged();
}
template <typename T>
void Vector2<T>::set(const Vector2<T>& _rcVector, bool _notifyParent)
{
	set(_rcVector.x, _rcVector.y, _notifyParent);
}
template <typename T>
void Vector2<T>::add(T _x, T _y, bool _notifyParent)
{
	x.add(_x, false);
	y.add(_y, false);
	angle.set(atan2(y, x), false);

	if(_notifyParent == true)
		OObject::ChildChanged();
}
template <typename T>
void Vector2<T>::add(const Vector2<T>& _rcVector, bool _notifyParent)
{
	add(_rcVector.x, _rcVector.y, _notifyParent);
}

/////
///// other methods
/////
template <typename T>
float Vector2<T>::length() const
{
	return sqrt(length2());
}
template <typename T>
float Vector2<T>::length2() const
{
	return x*x + y*y;
}
template <typename T>
Vector2<T> Vector2<T>::normalize() const
{
	float _length = length();
	return Vector2<T>(x / _length, y / _length);
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
	return Vector2<U>((U)x, (U)y);
}

///
/// arithmetic
///
template <typename T>
Vector2<T> Vector2<T>::operator-() const
{
	return Vector2<T>(-x, -y);
}
template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T> _rcVector) const
{
	return _rcVector += *this;
}
template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> _rcVector) const
{
	return _rcVector -= *this;
}
template <typename T>
template <typename FT>
Vector2<T> Vector2<T>::operator*(FT _factor) const
{
	return Vector2<T>(x * _factor,
					  y * _factor);
}
template <typename T>
Vector2<T> Vector2<T>::operator*(const Vector2<T> _rcVector) const
{
	return Vector2<T>(x * _rcVector.x - y * _rcVector.y,
					  x * _rcVector.y + y * _rcVector.x);
}
template <typename T>
template <typename D>
Vector2<T> Vector2<T>::operator/(D _divisor) const
{
	return Vector2<T>(x / _divisor,
					  y / _divisor);
}
template <typename T>
Vector2<T> Vector2<T>::operator/(const Vector2<T> _rcVector) const
{
	return Vector2<T>((x * _rcVector.x + y * _rcVector.y)/(_rcVector.length2()),
					  (y * _rcVector.x - x * _rcVector.y)/(_rcVector.length2()));
}

///
/// comparison
///
template <typename T>
bool Vector2<T>::operator==(const Vector2<T>& _rcVector) const
{
	return ((x == _rcVector.x)&&
			(y == _rcVector.y));
}
template <typename T>
bool Vector2<T>::operator!=(const Vector2<T>& _rcVector) const
{
	return (!(*this == _rcVector));
}
template <typename T>
bool Vector2<T>::operator>(const Vector2<T>& _rcVector) const
{
	return ((x > _rcVector.x)&&
			(y > _rcVector.y));
}
template <typename T>
bool Vector2<T>::operator<(const Vector2<T>& _rcVector) const
{
	return ((x < _rcVector.x) &&
			(y < _rcVector.y));
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

template <typename T>
void Vector2<T>::ChildChanged(int _childId)
{
	if(_childId == angle.id())
	{
		float _length = length();
		set(_length * cos(angle), _length * sin(angle));
	}

	OObject::ChildChanged();
}

} // Objects2D
} // Objects
} // Openpp
