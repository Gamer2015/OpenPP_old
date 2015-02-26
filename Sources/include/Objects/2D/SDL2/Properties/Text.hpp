#ifndef LIBREPP_OBJECTS_2D_SDL2_PROPERTIES_TEXT_H_
#define LIBREPP_OBJECTS_2D_SDL2_PROPERTIES_TEXT_H_

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

#include <Objects/LObject.hpp>
#include <Objects/Properties/LType.hpp>
#include <Objects/2D/Vector2.hpp>

#include "../Texture.hpp"
#include <string>
#include <SDL2/SDL.h>


namespace LO = Librepp::Objects;
namespace LOP = LO::Properties;

namespace LO2 = LO::Objects2D;

namespace Librepp
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
	Text(LO::LObject* const _pParent = nullptr);
	Text(const std::string& _rctext, LObject* const _pParent = nullptr);


	/// properties
	LOP::LType<int> height;
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
} // Librepp

#include "Text.inl"

#endif // LIBREPP_OBJECTS_2D_SDL2_PROPERTIES_TEXT_H_
