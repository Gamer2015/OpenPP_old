#ifndef ___VECTOR_2D__H___
#define ___VECTOR_2D__H___

/******************************************
 *  MADE BY: Stefan Kreiner
 *  DATE: 30th November 2015
 *  USAGE: Datatype for OS-Independent Development
 * _______________________________________________
 *
 * Notes:
 *  - Not Tested
 *
 */

#include <cmath>

template <typename Type>
class Vector2
{
    /// Constructors
public:
    Vector2();
    Vector2(Type X, Type Y);
    Vector2(const Vector2<Type> &Vector);

    /// Static Methods
public:
    static Type dotProduct(const Vector2<Type>& v1, const Vector2<Type>& v2);

    /// Operators
public:
    Vector2<Type> operator-() const;

    /// Comparison Operators
    bool operator==(const Vector2<Type> &Vector) const;
    bool operator!=(const Vector2<Type> &Vector) const;

    bool operator>(const Vector2<Type> &Vector) const;
    bool operator<(const Vector2<Type> &Vector) const;
    bool operator>=(const Vector2<Type> &Vector) const;
    bool operator<=(const Vector2<Type> &Vector) const;

    /// Calculation Operators
    Vector2<Type> operator+(const Vector2<Type> &Vector) const;
    Vector2<Type> operator-(const Vector2<Type> &Vector) const;
    Vector2<Type> operator*(const Vector2<Type> &Vector) const;
    template <typename FactorType>
    Vector2<Type> operator*(FactorType factor) const;
    Vector2<Type> operator/(const Vector2<Type> &Vector) const;
    template <typename DivisorType>
    Vector2<Type> operator/(DivisorType divisor) const;

    Vector2<Type> &operator+=(const Vector2<Type> &Vector);
    Vector2<Type> &operator-=(const Vector2<Type> &Vector);
    Vector2<Type> &operator*=(const Vector2<Type> &Vector);
    template <typename FactorType>
    Vector2<Type> &operator*=(FactorType factor);
    Vector2<Type> &operator/=(const Vector2<Type> &Vector);
    template <typename DivisorType>
    Vector2<Type> &operator/=(DivisorType divisor);

    /// SET-Methods
public:
    void Set(Type X, Type Y);
    void Add(Type X, Type Y);

    /// GET-Methods
public:
    Vector2<Type> normalized() const;
    Vector2<Type> unitVector() const;
    double length() const;
    Type lengthSquared() const;
    double angle() const; // in Rad

    /// Members
public:
    Type x;
    Type y;
};

typedef Vector2<unsigned int> Vector2u;
typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

#include "Vector2.inl"

#endif // ___VECTOR_2D__H___
