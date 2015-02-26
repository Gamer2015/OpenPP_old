#include "Text.hpp"

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

Text::Text(OObject* const _pParent) :
	Text("", _pParent)
{}
Text::Text(std::string _text, OObject* const _pParent) :
	Properties::Text(_text, _pParent),
	position(this),
	angle(this)
{}

const SDL_Rect& Text::rect() const
{
	return mRect;
}

const SDL_Point& Text::rectOrigin() const
{
	return mRectOrigin;
}

void Text::render() const
{
	if(texture())
		SDL_RenderCopyEx( Globals::Renderer(), texture(), NULL, &(rect()), 57.295779513082320876798154814105 * angle(), &(rectOrigin()), SDL_FLIP_NONE);
}

void Text::ChildChanged(int _childId)
{
	Properties::Text::ChildChanged(_childId);

	if(_childId != angle.id())
	{
		mRect.w = size().x();
		mRect.h = size().y();

		mRectOrigin.x = ceil(mRect.w / 2.0 * (origin.x() + 1));
		mRectOrigin.y = ceil(mRect.h / 2.0 * (origin.y() + 1));

		mRect.x = position.x() - mRectOrigin.x;
		mRect.y = position.y() - mRectOrigin.y;
	}
}


} // SDL2
} // Objects2D
} // Objects
} // Openpp
