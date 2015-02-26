#ifndef ___TEXT__H___
#define ___TEXT__H___

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Sprite Class for Games in C++ with SDL
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  -
 *
\********************************************/

#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include "Texture.h"
#include "Globals.h"

namespace Core
{
    class Text
    {
    public:
        /// Set Text
        void SetText(std::string Text);

        /// Get Text
        std::string const& GetText() const;

        /// Set the Height of the Text
        void SetTextHeight(float y);

        /// Get the Size of the Text
        Vector2i const& GetTextSize() const;

        /// Set the Origin of the Text
        /// x = -1 -> Left Align | x = 0 -> Centered | x = 1 -> Right Align
        void SetTextOrigin(float x, float y);

        /// Get the Origin of the Text
        Vector2f const& GetTextOrigin() const;

        /// Set the Position of the Text
        void SetPosition(float X, float Y);

        /// Move the Text
        void Move(float X, float Y);

        /// Get the Position of the Text
        Vector2f const& GetPosition() const;

        /// Render the Text
        void Render() const;

        /// Render the Text with a relative Offset
        void Render(float OffsetX, float OffsetY) const;

        SDL_Rect const& GetTextRect() const;

        std::shared_ptr< SDL_Texture > const& GetTextTexture() const;

    protected:
        virtual void CalcTextRenderRect();
        SDL_Rect mTextRect;

    private:
        std::shared_ptr< SDL_Texture > mpTextTexture;
        std::string mText;

        Vector2i mTextSize;
        int mTextHeight;
        Vector2f mTextOrigin;

        mutable SDL_Rect mDummyRect;

        Vector2f mPosition;
    };
}

#endif // ___CTEXTURE__H___
