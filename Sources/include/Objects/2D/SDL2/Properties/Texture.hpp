#ifndef OPENPP_OBJECTS_2D_SDL2_PROPERTIES_TEXTURE_H_
#define OPENPP_OBJECTS_2D_SDL2_PROPERTIES_TEXTURE_H_

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

#include "../../../OObject.hpp"
#include "../Texture.hpp"


#include <SDL.h>
#include <string>

namespace OO = Openpp::Objects;

namespace Openpp {
namespace Objects {
namespace Objects2D {
namespace SDL2 {
namespace Properties {

class Texture : public OO::OObject
{
public:
	Texture(OO::OObject* const _pParent = nullptr);

	/// set the text
	void set(const std::string& _rcPath);
    void set(const SDL2::Texture::Info _pTexture);

    /// get the text
    SDL_Texture* get() const;

	void operator=(const Texture& _rcTexture);

private:
    SDL2::Texture::Info _mpTexture;
};

} // Properties
} // SDL2
} // Objects2D
} // Objects
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_PROPERTIES_TEXTURE_H_
