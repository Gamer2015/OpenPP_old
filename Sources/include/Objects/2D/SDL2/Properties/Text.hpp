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

#include <Objects/OObject.hpp>
#include <Objects/Properties/OType.tpp>
#include <Objects/2D/Vector2.tpp>

#include "../Texture.hpp"
#include <string>
#include <SDL.h>


namespace OO = Openpp::Objects;
namespace OO2 = OO::Objects2D;
namespace SDL = OO2::SDL2;
namespace OOP = OO::Properties;


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

class Text : public OO::OObject
{
public:
	Text(OO::OObject* const _pParent = nullptr);
	Text(const std::string& _rctext, OObject* const _pParent = nullptr);


	/// properties
    OOP::OType<int> height;
	OO2::Vector2<float> origin;


	/// set the text
	void set(const std::string& _rctext);
	void set(const Text& _rctext);

	const OO2::Vector2<int>& size() const;

	/// getter
	SDL_Texture* texture() const;

	/// get the text
    operator std::string() const;

protected:
	virtual void ChildChanged(int _childId);

private:
	std::shared_ptr< SDL_Texture > mpTexture;
	OO2::Vector2<int> Size;

	std::string _mText;
};

} // Properties
} // Objects2D
} // Objects
} // SDL2
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_PROPERTIES_TEXT_H_
