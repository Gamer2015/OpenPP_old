#ifndef OPENPP_OBJECTS_2D_SDL2_SDL_RECTANGLE_H_
#define OPENPP_OBJECTS_2D_SDL2_SDL_RECTANGLE_H_

/********************************************\
 * Usage: base class for renderable SDLObjects
 * Date: 20th of February 2015
 * Author: Stefan Kreiner
 * _______________________________________________
 *
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <SDL.h>
#include <Objects/2D/Rectangle.hpp>
#include <cmath>

namespace OO = Openpp::Objects;
namespace OO2 = OO::Objects2D;

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

template <typename T>
class SDL_Rectangle : public OO2::Rectangle<T>
{
public:
    SDL_Rectangle(OO::OObject* const _pParent = nullptr);

	/// rendered rect
	const SDL_Rect& rect() const;

protected:
	virtual void ChildChanged(int _childId);

	SDL_Point mRectOrigin;
	const SDL_Point& rectOrigin() const;

	SDL_Rect mRect;
};

} // SDL2
} // Objects2D
} // Objects
} // Openpp

#include "SDL_Rectangle.inl"

#endif // OPENPP_OBJECTS_2D_SDL2_SDL_RECTANGLE_H_
