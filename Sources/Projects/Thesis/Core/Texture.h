#ifndef ___CTEXTURE__H___
#define ___CTEXTURE__H___

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
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include "Math/Vector2.h"
#include "Exceptions/ExSDLError.h"
#include "Globals.h"

typedef Core::Globals CG;

namespace Core
{
    class Texture
    {
        static std::shared_ptr< TTF_Font > pFont;
        static std::shared_ptr< SDL_Surface > pLoadedSurface;
        static std::shared_ptr< SDL_Texture > pTexture;
        static SDL_Color Color;
    public:
        /// Load a Texture from a File
        /// @exceptions: 2 Different ExSDLError
        static std::shared_ptr<SDL_Texture> LoadFromSurface(SDL_Surface* pSurface, SDL_Renderer* pRenderer = CG::gpRenderer);

        /// Load a Texture from a File
        /// @exceptions: 2 Different ExSDLError
        static std::shared_ptr<SDL_Texture> LoadFromFile(const std::string Path, SDL_Renderer* pRenderer = CG::gpRenderer);

        /// Make a Texture from a Text
        /// @exceptions:
        static std::shared_ptr<SDL_Texture> LoadText(const std::string Text, const SDL_Color = Color, SDL_Renderer* pRenderer = CG::gpRenderer);

        /// Returns the Text Size of the Texture
        static Vector2<int> GetTextSize(std::string Text);

        /// Set the Font used by LoadText
        /// @exceptions: Some ExSDLErrors
        static void LoadTextFont(const std::string Path);
    };
}

#endif // ___CTEXTURE__H___
