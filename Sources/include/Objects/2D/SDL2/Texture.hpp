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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <Objects/2D/Vector2.hpp>
#include "Exceptions/ExSDLError.hpp"
#include "Globals.hpp"

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

class Texture
{
private:
	Texture() = delete;

public:
	/// Load a Texture from a File
	static std::shared_ptr<SDL_Texture> Get(SDL_Surface* pSurface, SDL_Renderer* pRenderer = Globals::Renderer());

	/// Load a Texture from a File
	static std::shared_ptr<SDL_Texture> Get(const std::string& rcPath, SDL_Renderer* pRenderer = Globals::Renderer());

	/// Make a Texture from a Text
	static std::shared_ptr<SDL_Texture> GetText(const std::string& rcText, SDL_Renderer* pRenderer = Globals::Renderer(), const SDL_Color = Color);

	/// Returns the Text Size of the Texture
	static Vector2<int> GetSize(const std::string& Text);

	/// Set the Font used by LoadText
	static void LoadFont(const std::string Path);

private:
	static std::shared_ptr< TTF_Font > pFont;
	static std::shared_ptr< SDL_Surface > pLoadedSurface;
	static std::shared_ptr< SDL_Texture > pTexture;
	static SDL_Color Color;
};

} // SDL2
} // Objects2D
} // Objects
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_TEXTURE_H_
