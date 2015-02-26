#ifndef ___SDL_RECTANGLE__H___
#define ___SDL_RECTANGLE__H___

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

#include <SDL2/SDL.h>
#include "Rectangle.h"
#include "Math/Vector2.h"

namespace Core
{
    class SDL_Rectangle : public FRectangle
    {
    public:
        /// Set the Position of the Button
        void SetPosition(float X, float Y);

        /// Move the Button
        void Move(float X, float Y);

        /// Sets the Size of the Button
        void SetSize(float X, float Y);

        /// Set the Origin of the Button
        void SetOrigin(float X, float Y);

        SDL_Rect const& GetRenderRect() const;

    protected:
        virtual void CalcRenderRect();
        SDL_Rect mRenderRect;
    };
}

#endif // ___SDL_RECTANGLE__H___
