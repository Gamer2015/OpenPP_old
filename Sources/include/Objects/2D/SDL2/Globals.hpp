#ifndef OPENPP_OBJECTS_2D_SDL2_GLOBALS_HPP_
#define OPENPP_OBJECTS_2D_SDL2_GLOBALS_HPP_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Global Core Elements of each SDL Based Program
 * _______________________________________________
 *
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <memory>
#include "Exceptions/ExSDLError.hpp"
#include "../../IScreen.hpp"
#include "../Vector2.tpp"

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

class Globals
{
private:
	Globals() = delete;

public:
	static void Init(const std::string& rTitle, Vector2<int> _window, unsigned int _image_flags = IMG_INIT_PNG | IMG_INIT_JPG);
	static bool WindowIsOpen;

    /// Global Renderer
	static SDL_Renderer* Renderer();

	/// Current Screen
	// static Screen* gpCurrentScreen;

private:
	static SDL_Window* pWindow;
	static std::shared_ptr< SDL_Renderer > pRenderer;
};

} // SDL2
} // Objects2D
} // Objects
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_GLOBALS_HPP_
