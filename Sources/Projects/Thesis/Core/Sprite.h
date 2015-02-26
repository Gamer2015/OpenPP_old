#ifndef ___SPRITE__H___
#define ___SPRITE__H___

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
#include "SDL_Rectangle.h"
#include "Texture.h"
#include "Globals.h"

namespace Core
{
    class Sprite : public SDL_Rectangle
    {
    public:
        /// Set Texture of Sprite[Index]
        /// @param Texure: Shared Pointer to extern Texture
        /// @param Index: Index of new Texture
        template <typename T>
        void SetTexture(const std::shared_ptr<T> Texture);

        /// Set Texture of Sprite[Index]
        /// @param Path: Path to Texture
        /// @param Index: Index of new Texture
        /// @exception: ExFileError
        /// @exception: ExSDLError
        void SetTexture(std::string Path);

        /// Render the Button
        void Render() const;

    private:
        std::shared_ptr< SDL_Texture > mTexture;
    };
}

#endif // ___CTEXTURE__H___
