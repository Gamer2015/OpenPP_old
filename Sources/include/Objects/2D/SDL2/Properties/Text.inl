#include "Text.hpp"

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

Text::Text(OObject* const _pParent) :
	Text("", _pParent)
{}
Text::Text(const std::string& _rctext, OObject* const _pParent) :
	OObject(_pParent),
	_mText(_rctext),
	height(this),
	origin(this),
	Size(this)
{}

void Text::set(const std::string& _rcText)
{
	_mText = _rcText;

	ChildChanged(selfId());
}
void Text::set(const Text& _rcText)
{
	_mText = _rcText();

	ChildChanged(selfId());
}

const LO2::Vector2<int>& Text::size() const
{
	return Size;
}
SDL_Texture* Text::texture() const
{
	return mpTexture.get();
}

const std::string& Text::operator()() const
{
	return _mText;
}

void Text::ChildChanged(int _childId)
{
	if(_childId == selfId())
	{
		std::cout << (*this)() << std::endl;
		Size.set(Texture::GetSize((*this)()));
		mpTexture = Texture::GetText((*this)());

		ChildChanged(height.id());
		return;
	}
	else if(_childId == height.id())
	{
		if(height() != 0 && size().x() != 0 && size().y() != 0)
		{
			Size.set(size().x() * height() / size().y(), height());
		}
	}
	LO::LObject::ChildChanged();
}

} // Properties
} // SDL2
} // Objects2D
} // Objects
} // Openpp
