#include "Text.hpp"

namespace Openpp {
namespace Objects {
namespace Objects2D {
namespace SDL2 {
namespace Properties {

Text::Text(OObject* const _pParent) :
	Text("", _pParent)
{}
Text::Text(const std::string& _rctext, OObject* const _pParent) :
	OObject(_pParent),
	_mText(_rctext),
	height(this),
    origin(this)
{}

void Text::set(const std::string& _rcText)
{
	_mText = _rcText;

	ChildChanged(selfId());
}
void Text::set(const Text& _rcText)
{
    _mText = _rcText;
}

const Vector2<int>& Text::size() const
{
    return mpTexture.size;
}
SDL_Texture* Text::texture() const
{
    return mpTexture.texture.get();
}

Text::operator std::string() const
{
	return _mText;
}

void Text::ChildChanged(int _childId)
{
	if(_childId == selfId())
    {
        if(height != 0)
            mpTexture = Texture::GetText(*this, height);
	}
	else if(_childId == height.id())
    {
        if((std::string)*this != "")
            mpTexture = Texture::GetText(*this, height);
	}
	OObject::ChildChanged();
}

} // Properties
} // SDL2
} // Objects2D
} // Objects
} // Openpp
