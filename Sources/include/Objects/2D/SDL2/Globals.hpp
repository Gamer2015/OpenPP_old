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

#include <SDL2/SDL.h>
#include <memory>
#include "Exceptions/ExSDLError.hpp"
#include "Screen.hpp"

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
	static void Init(const std::string& rTitle, int Width, int Height);
	static bool WindowIsOpen;

	static SDL_Renderer* Renderer();

	// Global Screen Pointer
	static Screen* gpCurrentScreen;

private:
	static SDL_Window* pWindow;
	static std::shared_ptr< SDL_Renderer > pRenderer;
};

} // SDL2
} // Objects2D
} // Objects
} // Openpp

#include "Globals.inl"

#endif // OPENPP_OBJECTS_2D_SDL2_GLOBALS_HPP_
