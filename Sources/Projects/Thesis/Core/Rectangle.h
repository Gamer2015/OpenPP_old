#ifndef ___RECTANGLE__H___
#define ___RECTANGLE__H___

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Texture Class for Games in C++ with SDL
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  -
 *
\********************************************/

#include "Math/Vector2.h"

namespace Core
{
    template <typename Type>
    class Rectangle
    {
    public:
        /// Set the Position of the Button
        void SetPosition(Type X, Type Y);

        /// Move the Button
        void Move(Type X, Type Y);

        /// Get the Position of the Button
        Vector2<Type> const& GetPosition() const;


        /// Sets the Size of the Button
        void SetSize(Type X, Type Y);

        /// Get the Size of the Button
        Vector2<Type> const& GetSize() const;


        /// Set the Origin of the Button
        void SetOrigin(float X, float Y);

        /// Get the Origin of the Button
        /// x & y = 0.5 -> Center
        Vector2f const& GetOrigin() const;


        /// Set the Angle of the Object
        void SetAngle(float Angle);

        /// Get the Angle of the Object
        float GetAngle() const;

    private:
        Vector2<Type> mSize;
        Vector2<Type> mPosition;
        Vector2f mOrigin;
        float mAngle;
    };

    typedef Rectangle<unsigned int> URectangle;
    typedef Rectangle<int> IRectangle;
    typedef Rectangle<float> FRectangle;
    typedef Rectangle<double> DRectangle;
}

#include "Rectangle.inl"

#endif // ___RECTANGLE__H___
