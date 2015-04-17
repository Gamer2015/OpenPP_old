#ifndef OPENPP_OBJECTS_2D_SDL2_TEXTURE_H_
#define OPENPP_OBJECTS_2D_SDL2_TEXTURE_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Texture Loading Class for Games in C++ with SDL
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  -
 *
\********************************************/

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include "../Vector2.hpp"
#include "Exceptions/ExSDLError.hpp"
#include "Globals.hpp"

namespace Openpp {
namespace Objects {
namespace SDL2 {

class Texture
{
private:
	Texture() = delete;

public:
    struct Info {
        std::shared_ptr<SDL_Texture> texture;
        Vector2<int> size;
    };

	/// Load a Texture from a File
    static Info Get(SDL_Surface* pSurface, SDL_Renderer* pRenderer = Globals::Renderer());

	/// Load a Texture from a File
    static Info Get(const std::string& rcPath, SDL_Renderer* pRenderer = Globals::Renderer());

	/// Make a Texture from a Text
    static Info GetText(const std::string& rcText, int height, SDL_Renderer* pRenderer = Globals::Renderer(), const SDL_Color = Color);

	/// Set the Font used by LoadText
    static void SetFont(const std::string& Path);

private:
    static std::string strFont;
    static std::shared_ptr< TTF_Font > pFont;
    static int text_height;
	static SDL_Color Color;
};

} // SDL2

} // Objects
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_TEXTURE_H_
