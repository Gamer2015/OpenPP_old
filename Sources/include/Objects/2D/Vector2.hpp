#ifndef OPENPP_OBJECTS_2D_VECTOR2_H_
#define OPENPP_OBJECTS_2D_VECTOR2_H_

/******************************************
 *  Usage: 2D vector property for LObjects
 *  Date: 20th of February 2015
 *  Author: Stefan Kreiner
 * _______________________________________________
 *
 * Notes:
 *  - Not Tested
 *
 * Warnings:
 *  - Do not set _notifyParent to false unless you know what you are doing
 *  - Use set(x, y) instead of vector.x = x; vector.y = y; for better performance
 *    (the Parent will be updated only once unstead of twice)
 *
 *******************************************/

#include "../OObject.hpp"
#include "../Properties/OType.tpp"
#include <cmath>

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
class Vector2 : public OObject
{
public:
	/// constructors
	Vector2(OObject* const _pParent = nullptr);
	Vector2(T _x, T _y, OObject* const _pParent = nullptr);
	Vector2(const Vector2<T>& _rcVector, OObject* const _pParent = nullptr);


	/// properties
	Objects::Properties::OType<T> x;
	Objects::Properties::OType<T> y;
	Objects::Properties::OType<float> angle;

	/// setter
	void set(T _x, T _y, bool _notifyParent=true);
	void set(const Vector2<T>& _rcVector, bool _notifyParent=true);

	void add(T _x, T _y, bool _notifyParent=true);
	void add(const Vector2<T>& _rcVector, bool _notifyParent=true);
	void subtract(T _x, T _y, bool _notifyParent=true);
	void subtract(const Vector2<T>& _rcVector, bool _notifyParent=true);
	void multiply(T _x, T _y, bool _notifyParent=true);
	void multiply(const Vector2<T>& _rcVector, bool _notifyParent=true);
	void divide(T _x, T _y, bool _notifyParent=true);
	void divide(const Vector2<T>& _rcVector, bool _notifyParent=true);


	/// other methods
	float length() const;
	float length2() const; // length squared
	Vector2<T> normalize() const;


	///// operators
	/// assignment
	Vector2<T> operator=(const Vector2<T>& _rcVector);

	/// conversion
	template <typename U>
	operator Vector2<U>() const;

	/// arithmetic
	Vector2<T> operator-() const;
	Vector2<T> operator+(const Vector2<T> _rcVector) const;
	Vector2<T> operator-(const Vector2<T> _rcVector) const;
	template <typename FT>
	Vector2<T> operator*(FT _factor) const;
	Vector2<T> operator*(const Vector2<T> _rcVector) const;
	template <typename DT>
	Vector2<T> operator/(DT _divisor) const;
	Vector2<T> operator/(const Vector2<T> _rcVector) const;

	/// comparison
	bool operator==(const Vector2<T>& _rcVector) const;
	bool operator!=(const Vector2<T>& _rcVector) const;
	bool operator>(const Vector2<T>& _rcVector) const;
	bool operator<(const Vector2<T>& _rcVector) const;
	bool operator>=(const Vector2<T>& _rcVector) const;
	bool operator<=(const Vector2<T>& _rcVector) const;

	/// compound assignment
	Vector2<T> &operator+=(const Vector2<T>& _rcVector);
	Vector2<T> &operator-=(const Vector2<T>& _rcVector);
	template <typename FT>
	Vector2<T> &operator*=(FT factor);
	Vector2<T> &operator*=(const Vector2<T>& _rcVector);
	template <typename DT>
	Vector2<T> &operator/=(DT divisor);
	Vector2<T> &operator/=(const Vector2<T>& _rcVector);

protected:
	virtual void ChildChanged(int _childId);
};

} // Objects2D
} // Objects
} // Openpp

#include "Vector2.tpp"

#endif // OPENPP_OBJECTS_2D_VECTOR2_H_
