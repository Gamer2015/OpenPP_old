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
#include <Objects/Properties/OType.hpp>
#include <Objects/2D/Vector2.hpp>

#include "../Texture.hpp"
#include <string>
#include <SDL2/SDL.h>


namespace OO = Openpp::Objects;
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
namespace Properties
{

class Text : public LO::LObject
{
public:
	Text(LO::OObject* const _pParent = nullptr);
	Text(const std::string& _rctext, OObject* const _pParent = nullptr);


	/// properties
	LOP::OType<int> height;
	LO2::Vector2<float> origin;


	/// set the text
	void set(const std::string& _rctext);
	void set(const Text& _rctext);

	const LO2::Vector2<int>& size() const;

	/// getter
	SDL_Texture* texture() const;

	/// get the text
	const std::string& operator()() const;

protected:
	virtual void ChildChanged(int _childId);

private:
	std::shared_ptr< SDL_Texture > mpTexture;
	LO2::Vector2<int> Size;

	std::string _mText;
};

} // Properties
} // Objects2D
} // Objects
} // SDL2
} // Openpp

#include "Text.inl"

#endif // OPENPP_OBJECTS_2D_SDL2_PROPERTIES_TEXT_H_
