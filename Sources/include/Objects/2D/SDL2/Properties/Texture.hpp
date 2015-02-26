#ifndef Openpp_OBJECTS_2D_SDL2_PROPERTIES_TEXTURE_H_
#define Openpp_OBJECTS_2D_SDL2_PROPERTIES_TEXTURE_H_

/********************************************\
 * Date: 17th February 2015
 * Author: Stefan Kreiner
 * Usage: Texture Property for SDLObjects
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <Objects/LObject.hpp>
#include "../Texture.hpp"


#include <SDL2/SDL.h>
#include <string>

namespace LO = Openpp::Objects;

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{
namespace Properties
{

class Texture : public LO::LObject
{
public:
	Texture(LO::LObject* const _pParent = nullptr);

	/// set the text
	void set(const std::string& _rcPath);
	void set(const std::shared_ptr<SDL_Texture> _pTexture);

	/// get the text
	SDL_Texture* const operator()() const;

	void operator=(const Texture& _rcTexture);

private:
	std::shared_ptr< SDL_Texture > _mpTexture;
};

} // Properties
} // SDL2
} // Objects2D
} // Objects
} // Openpp

#include "Texture.inl"

#endif // Openpp_OBJECTS_2D_SDL2_PROPERTIES_TEXTURE_H_
