#ifndef OPENPP_OBJECTS_2D_SDL2_TEXT_H_
#define OPENPP_OBJECTS_2D_SDL2_TEXT_H_

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

#include "../../OObject.hpp"

#include <SDL.h>
#include <memory>
#include <string>
#include "Texture.hpp"
#include "Globals.hpp"
#include "Properties/Text.hpp"

#include "../../Properties/OType.hpp"
#include "../Vector2.hpp"
#include <cmath>


namespace Openpp {
namespace Objects {
namespace SDL2 {

class Text : public Properties::Text
{
public:
	Text(OObject* const _pParent = nullptr);
	Text(std::string _text, OObject* const _pParent = nullptr);


	/// properties
	Vector2<int> position;
	Objects::Properties::OType<float> angle;


	/// rendered rect
	const SDL_Rect& rect() const;

	/// render
    void Render() const;

protected:
	virtual void ChildChanged(int _childId);

private:
	const SDL_Point& rectOrigin() const;
	SDL_Point mRectOrigin;
	SDL_Rect mRect;
};

} // SDL2

} // Objects
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_TEXT_H_
