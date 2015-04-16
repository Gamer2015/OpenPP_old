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

#include "../../OObject.hpp"

#include <SDL.h>
#include <memory>
#include <vector>
#include "Globals.hpp"
#include "SDL_Rectangle.hpp"

#include "Properties/Texture.hpp"
#include "Properties/Text.hpp"
#include <functional>

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
	Button(OObject* const _pParent = nullptr);


	/// properties
	Properties::Text text;
	std::vector<Properties::Texture> textures;
	std::function<void()> function;


	/// Checks if the Point (X, Y) is inside the Button
	bool isInside(float X, float Y) const;


	/// Render the Button
	void Render(int Index = 0) const;

protected:
	virtual void ChildChanged(int _childId);

private:
	/* Render Rectangel */
	SDL_Rect mTextRect;
	SDL_Point mTextOrigin;
};

} // SDL2
} // Objects2D
} // Objects
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_BUTTON_H_
