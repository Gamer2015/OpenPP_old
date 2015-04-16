#ifndef OPENPP_OBJECTS_2D_SDL2_SPRITE_H_
#define OPENPP_OBJECTS_2D_SDL2_SPRITE_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Sprite Class for Games with SDL
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  -
 *
\********************************************/

#include <SDL.h>
#include <memory>
#include <string>
#include "SDL_Rectangle.hpp"
#include "Texture.hpp"
#include "Globals.hpp"
#include <cmath>

namespace Openpp {
namespace Objects {
namespace Objects2D {
namespace SDL2 {

template <typename T>
class Sprite : public SDL_Rectangle<T>
{
public:
	Sprite(OObject* const _pParent = nullptr);

	/// Set Texture
	void set(const std::shared_ptr<SDL_Texture> pTexture);

	/// Set Texture
	void set(const std::string& Path);

	/// Get Texture
	std::shared_ptr<SDL_Texture> operator()() const;

	/// Render Sprite
    void Render() const;

protected:
	std::shared_ptr< SDL_Texture > mpTexture;
};

} // SDL2
} // Objects2D
} // Objects
} // Openpp

#include "Sprite.tpp"

#endif // OPENPP_OBJECTS_2D_SDL2_SPRITE_H_
