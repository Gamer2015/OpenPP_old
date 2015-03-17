#include "Button.hpp"

#include <iostream>

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

inline float RAD_GRAD(float _radiant)
{
	return 180/M_PI * _radiant;
}

Button::Button(OObject* const _pParent) :
	SDL_Rectangle<float>(_pParent),
	text(this),
	textures(2, this)
{}

bool Button::isInside(float X, float Y) const
{
	Vector2<float> mouse(X, Y);
	Vector2<float> origin(rect().x + rectOrigin().x, rect().y + rectOrigin().y);

	mouse -= origin;
	mouse.angle -= this->angle;
	mouse += origin;

	if(mouse.x < SDL_Rectangle<float>::rect().x)
		return false;
	if(mouse.x > SDL_Rectangle<float>::rect().x + SDL_Rectangle<float>::rect().w)
		return false;

	if(mouse.y < SDL_Rectangle<float>::rect().y)
		return false;
	if(mouse.y > SDL_Rectangle<float>::rect().y + SDL_Rectangle<float>::rect().h)
		return false;

	return true;
}

void Button::Render(int Index) const
{
	if(Index < textures.size())
	{
		if(textures[Index]() != nullptr)
		{
			SDL_RenderCopyEx(Globals::Renderer(), textures[Index](), NULL, &rect(), RAD_GRAD(angle), &rectOrigin(), SDL_FLIP_NONE);
		}
	}

	if(text.texture() != nullptr)
	{
		SDL_RenderCopyEx(Globals::Renderer(), text.texture(), NULL, &mTextRect, RAD_GRAD(angle), &mTextOrigin, SDL_FLIP_NONE);
	}
}

void Button::ChildChanged(int _childId)
{
	SDL_Rectangle::ChildChanged(_childId);

    mTextRect.w = text.size().x;
    mTextRect.h = text.size().y;

    mTextRect.x = rect().x + rect().w / 2.0 *(text.origin.x + 1) - text.size().x / 2.0 * (text.origin.x + 1);
    mTextRect.y = rect().y + rect().h / 2.0 *(text.origin.y + 1) - text.size().y / 2.0 * (text.origin.y + 1);

	mTextOrigin.x = (rect().x + rectOrigin().x) - mTextRect.x;
	mTextOrigin.y = (rect().y + rectOrigin().y) - mTextRect.y;
}

} // SDL2
} // Objects2D
} // Objects
} // Openpp
