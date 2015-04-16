#ifndef OPENPP_OBJECTS_2D_SDL2_PROPERTIES_TEXT_H_
#define OPENPP_OBJECTS_2D_SDL2_PROPERTIES_TEXT_H_

/********************************************\
 * Date: 17th February 2015
 * Author: Stefan Kreiner
 * Usage: Text Property for SDLObjects
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include "../../../OObject.hpp"
#include "../../../Properties/OType.hpp"
#include "../../Vector2.hpp"

#include "../Texture.hpp"
#include <string>
#include <SDL.h>


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

class Text : public OObject
{
public:
	Text(OObject* const _pParent = nullptr);
	Text(const std::string& _rctext, OObject* const _pParent = nullptr);


	/// properties
	Objects::Properties::OType<int> height;
	Vector2<float> origin;


	/// set the text
	void set(const std::string& _rctext);
	void set(const Text& _rctext);

	const Vector2<int>& size() const;

	/// getter
	SDL_Texture* texture() const;

	/// get the text
	operator std::string() const;

protected:
	virtual void ChildChanged(int _childId);

private:
    SDL2::Texture::Info mpTexture;

	std::string _mText;
};

} // Properties
} // Objects2D
} // Objects
} // SDL2
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_PROPERTIES_TEXT_H_
