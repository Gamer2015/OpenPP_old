#ifndef LIBREPP_OBJECTS_2D_VECTOR2_H_
#define LIBREPP_OBJECTS_2D_VECTOR2_H_

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

#include "../LObject.hpp"
#include "../Properties/LType.hpp"

namespace LOP = Librepp::Objects::Properties;

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
class Vector2 : public LObject
{
public:
	/// constructors
	Vector2(LObject* const _pParent = nullptr);
	Vector2(T _x, T _y, LObject* const _pParent = nullptr);
	Vector2(const Vector2<T>& _rcVector, LObject* const _pParent = nullptr);


	/// properties
	LOP::LType<T> x;
	LOP::LType<T> y;


	/// setter
	void set(T _x, T _y, bool _notifyParent=true);
	void set(const Vector2<T>& _rcVector, bool _notifyParent=true);

	void add(T _x, T _y, bool _notifyParent=true);
	void add(const Vector2<T>& _rcVector, bool _notifyParent=true);


	///// operators
	/// assignment
	Vector2<T> operator=(const Vector2<T>& _rcVector);

	/// conversion
	template <typename U>
	operator Vector2<U>() const;

	/// arithmetic
	Vector2<T> operator-() const;
	Vector2<T> operator+(const Vector2<T>& _rcVector) const;
	Vector2<T> operator-(const Vector2<T>& _rcVector) const;
	template <typename FT>
	Vector2<T> operator*(FT _factor) const;
	Vector2<T> operator*(const Vector2<T>& _rcVector) const;
	template <typename DT>
	Vector2<T> operator/(DT _divisor) const;
	Vector2<T> operator/(const Vector2<T>& _rcVector) const;

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
};

} // Objects2D
} // Objects
} // Librepp

#include "Vector2.inl"

#endif // LIBREPP_OBJECTS_2D_VECTOR2_H_
