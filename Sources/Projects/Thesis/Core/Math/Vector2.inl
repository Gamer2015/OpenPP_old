
//////////////////////////////////////////////////////////
///////////////// Other Methods //////////////////////////
//////////////////////////////////////////////////////////
// public

template <typename Type>
Type Vector2<Type>::dotProduct(const Vector2<Type>& v1, const Vector2<Type>& v2)
{
    return ((v1.x * v2.x) +
            (v1.y * v2.y));
}

//////////////////////////////////////////////////////////
///////////////// Constructors ///////////////////////////
//////////////////////////////////////////////////////////
// public

template <typename Type>
Vector2<Type>::Vector2() : x(0), y(0)
{

}
template <typename Type>
Vector2<Type>::Vector2(Type X, Type Y) : x(X), y(Y)
{

}
template <typename Type>
Vector2<Type>::Vector2(const Vector2<Type> &vector)
{
    *this = vector;
}

//////////////////////////////////////////////////////////
///////////////// Operators //////////////////////////////
//////////////////////////////////////////////////////////
// public

template <typename Type>
Vector2<Type> Vector2<Type>::operator-() const
{
    return Vector2<Type>(-x, -y);
}

template <typename Type>
bool Vector2<Type>::operator==(const Vector2<Type> &vector) const
{
    return ((x == vector.x)&&
            (y == vector.y));
}
template <typename Type>
bool Vector2<Type>::operator!=(const Vector2<Type> &vector) const
{
    return ( !(*this == vector));
}
template <typename Type>
bool Vector2<Type>::operator>(const Vector2<Type> &vector) const
{
    return ((x > vector.x)&&
            (y > vector.y));
}
template <typename Type>
bool Vector2<Type>::operator<(const Vector2<Type> &vector) const
{
    return ((x < vector.x) &&
            (y < vector.y));
}
template <typename Type>
bool Vector2<Type>::operator>=(const Vector2<Type> &vector) const
{
    return ((x >= vector.x)&&
            (y >= vector.y));
}
template <typename Type>
bool Vector2<Type>::operator<=(const Vector2<Type> &vector) const
{
    return ((x <= vector.x) &&
            (y <= vector.y));
}

template <typename Type>
Vector2<Type> Vector2<Type>::operator+(const Vector2<Type> &vector) const
{
    return Vector2<Type>(x + vector.x,
                         y + vector.y);
}
template <typename Type>
Vector2<Type> Vector2<Type>::operator-(const Vector2<Type> &vector) const
{
    return Vector2<Type>(x - vector.x,
                         y - vector.y);
}
template <typename Type>
Vector2<Type> Vector2<Type>::operator*(const Vector2<Type> &vector) const
{
    return Vector2<Type>(x * vector.x - y * vector.y,
                         x * vector.y + y * vector.x);
}
template <typename Type>
template <typename FactorType>
Vector2<Type> Vector2<Type>::operator*(FactorType factor) const
{
    return Vector2<Type>(x * factor,
                         y * factor);
}
template <typename Type>
Vector2<Type> Vector2<Type>::operator/(const Vector2<Type> &vector) const
{
    return Vector2<Type>((x * vector.x + y * vector.y)/(vector.x * vector.x + vector.y * vector.y),
                         (y * vector.x - x * vector.y)/(vector.x * vector.x + vector.y * vector.y));
}
//template <typename Type, typename DivisorType>
template <typename Type>
template <typename DivisorType>
Vector2<Type> Vector2<Type>::operator/(DivisorType divisor) const
{
    return Vector2<Type>(x / divisor,
                         y / divisor);
}

template <typename Type>
Vector2<Type>& Vector2<Type>::operator+=(const Vector2<Type> &vector)
{
    x += vector.x;
    y += vector.y;
    return *this;
}
template <typename Type>
Vector2<Type>& Vector2<Type>::operator-=(const Vector2<Type> &vector)
{
    x -= vector.x;
    y -= vector.y;
    return *this;
}
template <typename Type>
Vector2<Type>& Vector2<Type>::operator*=(const Vector2<Type> &vector)
{
    *this = *this * vector;
    return *this;
}
//template <typename Type, typename FactorType>
template <typename Type>
template <typename FactorType>
Vector2<Type>& Vector2<Type>::operator*=(FactorType factor)
{
    x *= factor;
    y *= factor;
    return *this;
}
template <typename Type>
Vector2<Type>& Vector2<Type>::operator/=(const Vector2<Type> &vector)
{
    *this = *this / vector;
    return *this;
}
//template <typename Type, typename DivisorType>
template <typename Type>
template <typename DivisorType>
Vector2<Type>& Vector2<Type>::operator/=(DivisorType divisor)
{
    x /= divisor;
    y /= divisor;
    return *this;
}

//////////////////////////////////////////////////////////
///////////////// Set Methods ////////////////////////////
//////////////////////////////////////////////////////////
// public

template <typename Type>
void Vector2<Type>::Set(Type X, Type Y)
{
    x = X;
    y = Y;
}
template <typename Type>
void Vector2<Type>::Add(Type X, Type Y)
{
    x += X;
    y += Y;
}

//////////////////////////////////////////////////////////
///////////////// Get Methods ////////////////////////////
//////////////////////////////////////////////////////////
// public

template <typename Type>
Vector2<Type> Vector2<Type>::normalized() const
{
    return Vector2(y, -x);
}
template <typename Type>
Vector2<Type> Vector2<Type>::unitVector() const
{
    return (*this / this->length());
}
template <typename Type>
double Vector2<Type>::length() const
{
    return sqrt(x*x + y*y);
}
template <typename Type>
Type Vector2<Type>::lengthSquared() const
{
    return x*x + y*y;
}
template <typename Type>
double Vector2<Type>::angle() const
{
    return atan2(y, x);
}
