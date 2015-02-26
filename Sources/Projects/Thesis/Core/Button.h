#ifndef ___BUTTON__H___
#define ___BUTTON__H___

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Button Class for Games in C++ with SDL
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <SDL2/SDL.h>
#include <memory>
#include <vector>
#include "Globals.h"
#include "SDL_Rectangle.h"
#include "Text.h"
#include "Math/Vector2.h"
#include "Exceptions/ExFileError.h"
#include "Exceptions/ExSDLError.h"

typedef Core::Globals CG;
typedef void (*FunctionPointer)();

namespace Core
{
    class Button : public Text, public SDL_Rectangle
    {

    public:
        Button();

        /// Set Function the Button points to
        void SetFunction(const FunctionPointer Function = NULL);

        /// Get Function the Button points to
        FunctionPointer GetFunction() const;

        /// Calls the Function the Button points to
        void CallFunction() const;

        /// Adds a Texture Layer
        /// @param Texure: Shared Pointer to extern Texture
        /// @param Index: Index of new Texture
        template <typename T>
        void AddTexture(const std::shared_ptr<T> Texture);

        /// Adds a Texture Layer
        /// @param Path: Path to Texture
        /// @param Index: Index of new Texture
        /// @exception: ExFileError
        /// @exception: ExSDLError
        void AddTexture(std::string Path);

        /// Set Texture of Sprite[Index]
        /// @param Texure: Shared Pointer to extern Texture
        /// @param Index: Index of new Texture
        template <typename T>
        void SetTexture(const std::shared_ptr<T> Texture, int Index = 0);

        /// Set Texture of Sprite[Index]
        /// @param Path: Path to Texture
        /// @param Index: Index of new Texture
        /// @exception: ExFileError
        /// @exception: ExSDLError
        void SetTexture(std::string Path, int Index = 0);

        /// Get a Reference to a const Texture of the Button
        std::shared_ptr< SDL_Texture > const& GetTexture(int Index = 0) const;

        /// Get the Number of Textures in the Button
        int GetTextureCount() const;

        /// Set the Position of the Button
        void SetPosition(float X, float Y);

        /// Move the Button
        void Move(float X, float Y);

        /// Get the Position of the Button
        Vector2f const& GetPosition() const;

        /// Checks if the Point (X, Y) is inside the Button
        /// @returns true if it is inside
        bool PointIsInside(float X, float Y) const;

        /// Render the Button
        void Render(int Index = 0) const;

        /// Render the Button at a given Position relative to its own position
        void Render(float OffsetX, float OffsetY, int Index = 0) const;

    protected:
        virtual void CalcRenderRect();
        virtual void CalcTextRenderRect();

    private:
        std::vector< std::shared_ptr<SDL_Texture> > mpTextures;

        FunctionPointer mFunction;

        /* Render Rectangels */
        mutable SDL_Rect mDummyRect;
    };
}

#endif // ___BUTTON__H___
