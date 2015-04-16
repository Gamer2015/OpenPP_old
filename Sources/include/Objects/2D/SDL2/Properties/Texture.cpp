#include "Texture.hpp"

namespace Openpp {
namespace Objects {
namespace Objects2D {
namespace SDL2 {
namespace Properties {

Texture::Texture(OObject* const _pParent) :
	OO::OObject(_pParent)
{}

void Texture::set(const std::string& _rcPath)
{
    _mpTexture = Openpp::Objects::Objects2D::SDL2::Texture::Get(_rcPath);

    OO::OObject::ChildChanged();
}
void Texture::set(const SDL2::Texture::Info _pTexture)
{
    _mpTexture = _pTexture;
}

SDL_Texture* Texture::get() const
{
    return _mpTexture.texture.get();
}
void Texture::operator=(const Texture& _rcTexture)
{
	_mpTexture = _rcTexture._mpTexture;
}

} // Properties
} // SDL2
} // Objects2D
} // Objects
} // Openpp
