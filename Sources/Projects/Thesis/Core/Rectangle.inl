
namespace Core
{
    template <typename Type>
    void Rectangle<Type>::SetPosition(Type X, Type Y)
    {
        mPosition.x = X;
        mPosition.y = Y;
    }
    template <typename Type>
    void Rectangle<Type>::Move(Type X, Type Y)
    {
        mPosition.x += X;
        mPosition.y += Y;
    }
    template <typename Type>
    Vector2<Type> const& Rectangle<Type>::GetPosition() const
    {
        return mPosition;
    }

    template <typename Type>
    void Rectangle<Type>::SetSize(Type X, Type Y)
    {
        mSize.x = X;
        mSize.y = Y;
    }
    template <typename Type>
    Vector2<Type> const& Rectangle<Type>::GetSize() const
    {
        return mSize;
    }

    template <typename Type>
    void Rectangle<Type>::SetOrigin(float X, float Y)
    {
        mOrigin.x = X;
        mOrigin.y = Y;
    }
    template <typename Type>
    Vector2f const& Rectangle<Type>::GetOrigin() const
    {
        return mOrigin;
    }

    template <typename Type>
    void Rectangle<Type>::SetAngle(float Angle)
    {
        mAngle = Angle;
    }
    template <typename Type>
    float Rectangle<Type>::GetAngle() const
    {
        return mAngle;
    }
}
