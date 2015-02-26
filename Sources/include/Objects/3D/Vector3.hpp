#ifndef LIBREPP_OBJECTS_3D_VECTOR3_H_
#define LIBREPP_OBJECTS_3D_VECTOR3_H_

/******************************************
 *  Usage: 3D vector property for LObjects
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
 * To-Do:
 *  - add some operators
 *
 *******************************************/

#include <Objects/LObject.hpp>
#include <Objects/Properties/LType.hpp>

namespace LO = Librepp::Objects;
namespace LOP = LO::Properties;

#include <cmath>

namespace Librepp
{
namespace Objects
{
namespace Objects3D
{

template <typename T>
class Vector3 : public LObject
{
public:
	/// constructors
	Vector3(LObject* const _pParent);
	Vector3(T _x, T _y, T _z, LObject* const _pParent);
	Vector3(const Vector3<T>& _rcVector, LObject* const _pParent);


	/// properties
	LOP::LType<T> x;
	LOP::LType<T> y;
	LOP::LType<T> z;


	/// setter
	void set(T _x, T _y, T _z, bool _notifyParent=true);
	void set(const Vector3<T>& _rcVector, bool _notifyParent=true);
	void add(T _x, T _y, T _z, bool _notifyParent=true);
	void add(const Vector3<T>& _rcVector, bool _notifyParent=true);


	///// operators
	/// assignment
	Vector3<T> operator=(const Vector3<T>& _rcVector);

	/// conversion
	template <typename U>
	operator Vector3<U>() const;

	/// arithmetic
	Vector3<T> operator-() const;
	Vector3<T> operator+(const Vector3<T>& _rcVector) const;
	Vector3<T> operator-(const Vector3<T>& _rcVector) const;
	template <typename FT>
	Vector3<T> operator*(FT _factor) const;
	//Vector3<T> operator*(const Vector3<T>& _rcVector) const;
	template <typename DT>
	Vector3<T> operator/(DT _divisor) const;
	//Vector3<T> operator/(const Vector3<T>& _rcVector) const;

	/// comparison
	bool operator==(const Vector3<T>& _rcVector) const;
	bool operator!=(const Vector3<T>& _rcVector) const;
	bool operator>(const Vector3<T>& _rcVector) const;
	bool operator<(const Vector3<T>& _rcVector) const;
	bool operator>=(const Vector3<T>& _rcVector) const;
	bool operator<=(const Vector3<T>& _rcVector) const;

	/// compound assignment
	Vector3<T> &operator+=(const Vector3<T>& _rcVector);
	Vector3<T> &operator-=(const Vector3<T>& _rcVector);
	template <typename FT>
	Vector3<T> &operator*=(FT factor);
	//Vector3<T> &operator*=(const Vector3<T>& _rcVector);
	template <typename DT>
	Vector3<T> &operator/=(DT divisor);
	//Vector3<T> &operator/=(const Vector3<T>& _rcVector);
};

} // Objects3D
} // Objects
} // Librepp

#include "Vector3.inl"

#endif // LIBREPP_OBJECTS_3D_VECTOR3_H_
