#include "Texture.hpp"

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

Texture::Texture(LObject* _pParent) :
	LO::LObject(_pParent)
{}

void Texture::set(const std::string& _rcPath)
{
	_mpTexture = Openpp::Objects::Objects2D::SDL2::Texture::Get(_rcPath);

	LO::LObject::ChildChanged();
}
void Texture::set(const std::shared_ptr<SDL_Texture> _pTexture)
{
	_mpTexture = _pTexture;

	LO::LObject::ChildChanged();
}

SDL_Texture*const Texture::operator()() const
{
	return _mpTexture.get();
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
