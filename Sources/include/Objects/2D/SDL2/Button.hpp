#ifndef LIBREPP_OBJECTS_2D_SDL2_BUTTON_H_
#define LIBREPP_OBJECTS_2D_SDL2_BUTTON_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Button Class for Games with SDL
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <Objects/LObject.hpp>

#include <SDL2/SDL.h>
#include <memory>
#include <vector>
#include "Globals.hpp"
#include "SDL_Rectangle.hpp"

#include "Properties/Texture.hpp"
#include "Properties/Text.hpp"

#include <cmath>

namespace LO = Librepp::Objects;
namespace LOP = LO::Properties;

namespace LSDL2 = LO::Objects2D::SDL2;
typedef LSDL2::Globals LSG;
typedef LSDL2::Texture LST;
typedef void (*FunctionPointer)();

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

class Button : public SDL_Rectangle<float>
{
public:
	Button(LO::LObject* const _pParent = nullptr);


	/// properties
	Properties::Text text;
	std::vector<Properties::Texture> textures;


	/// Set Function the Button points to
	void SetFunction(const FunctionPointer Function = NULL);

	/// Calls the Function the Button points to
	void call() const;


	/// Checks if the Point (X, Y) is inside the Button
	/// @returns true if it is inside
	/// Not supported for tilted buttons
	bool PointIsInside(float X, float Y) const;

	/// Render the Button
	void render(int Index = 0) const;

protected:
	virtual void ChildChanged(int _childId);

private:
	FunctionPointer mFunction;

	/* Render Rectangel */
	SDL_Rect mTextRect;
	SDL_Point mTextOrigin;
};

} // SDL2
} // Objects2D
} // Objects
} // Librepp

#include "Button.inl"

#endif // LIBREPP_OBJECTS_2D_SDL2_BUTTON_H_
