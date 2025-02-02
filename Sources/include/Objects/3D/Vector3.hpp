#ifndef OPENPP_OBJECTS_3D_VECTOR3_H_
#define OPENPP_OBJECTS_3D_VECTOR3_H_

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

#include "../OObject.hpp"
#include "../Properties/OType.hpp"

namespace OO = Openpp::Objects;
namespace LOP = OO::Properties;

#include <cmath>

namespace Openpp {
namespace Objects {

template <typename T>
class Vector3 : public OObject
{
public:
	/// constructors
	Vector3(OObject* const _pParent);
	Vector3(T _x, T _y, T _z, OObject* const _pParent);
	Vector3(const Vector3<T>& _rcVector, OObject* const _pParent);


	/// properties
	LOP::OType<T> x;
	LOP::OType<T> y;
	LOP::OType<T> z;


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


} // Objects
} // Openpp

#include "Vector3.tpp"

#endif // OPENPP_OBJECTS_3D_VECTOR3_H_
