#ifndef LIBREPP_OBJECTS_2D_SDL2_SDL_RECTANGLE_H_
#define LIBREPP_OBJECTS_2D_SDL2_SDL_RECTANGLE_H_

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

#include <SDL2/SDL.h>
#include <Objects/2D/Rectangle.hpp>

namespace LO = Librepp::Objects;
namespace LO2 = LO::Objects2D;

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

template <typename T>
class SDL_Rectangle : public LO2::Rectangle<T>
{
public:
	SDL_Rectangle(LO::LObject* const _pParent = nullptr);

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
} // Librepp

#include "SDL_Rectangle.inl"

#endif // LIBREPP_OBJECTS_2D_SDL2_SDL_RECTANGLE_H_
