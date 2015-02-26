#ifndef Openpp_OBJECTS_2D_SDL2_TEXT_H_
#define Openpp_OBJECTS_2D_SDL2_TEXT_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Text Class
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  -
 *
\********************************************/

#include <Objects/LObject.hpp>

#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include "Texture.hpp"
#include "Globals.hpp"
#include "Properties/Text.hpp"

#include <Objects/Properties/LType.hpp>
#include <Objects/2D/Vector2.hpp>
#include <cmath>

namespace LO = Openpp::Objects;
namespace LOP = LO::Properties;
namespace LO2 = LO::Objects2D;


namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

class Text : public Properties::Text
{
public:
	Text(LO::LObject* const _pParent = nullptr);
	Text(std::string _text, LO::LObject* const _pParent = nullptr);


	/// properties
	LO2::Vector2<int> position;
	LOP::LType<float> angle;


	/// rendered rect
	const SDL_Rect& rect() const;

	/// render
	void render() const;

protected:
	virtual void ChildChanged(int _childId);

private:
	const SDL_Point& rectOrigin() const;
	SDL_Point mRectOrigin;
	SDL_Rect mRect;
};

} // SDL2
} // Objects2D
} // Objects
} // Openpp

#include "Text.inl"

#endif // Openpp_OBJECTS_2D_SDL2_TEXT_H_
