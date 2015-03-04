#ifndef OPENPP_OBJECTS_2D_SDL2_BUTTON_H_
#define OPENPP_OBJECTS_2D_SDL2_BUTTON_H_

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

#include <Objects/OObject.hpp>

#include <SDL.h>
#include <memory>
#include <vector>
#include "Globals.hpp"
#include "SDL_Rectangle.tpp"

#include "Properties/Texture.hpp"
#include "Properties/Text.hpp"

#include <cmath>

namespace OO = Openpp::Objects;
namespace LOP = OO::Properties;

namespace LSDL2 = OO::Objects2D::SDL2;
typedef LSDL2::Globals LSG;
typedef LSDL2::Texture LST;
typedef void (*FunctionPointer)();

namespace Openpp
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
	Button(OO::OObject* const _pParent = nullptr);


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
    void Render(int Index = 0) const;

	/// Applies all changes to the button
	void Refresh();

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
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_BUTTON_H_
