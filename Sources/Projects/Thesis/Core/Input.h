#ifndef OPENPP_PROJECTS_THESIS_CORE_INPUT_H_
#define OPENPP_PROJECTS_THESIS_CORE_INPUT_H_

#define USE_SDL_INPUT

#ifdef USE_RASPBERRY_INPUT
#include "RaspIO.h"
namespace INPUT = Raspberry::Input;
#elif defined(USE_SFML_INPUT)
#include <SFML/Graphics.hpp>
#elif defined(USE_SDL_INPUT)
#include <SDL.h>
#endif

namespace Core
{

class Input
{
public:
	enum EButton
	{
		BUTTON_UP = 0x01,
		BUTTON_DOWN = 0x02,
		BUTTON_LEFT = 0x04,
		BUTTON_RIGHT = 0x08,

		BUTTON_A = 0x10,
		BUTTON_B = 0x20,
		BUTTON_X = 0x40,
		BUTTON_Y = 0x80,

		BUTTON_SELECT = 0x100,
		BUTTON_START = 0x200,
		BUTTON_MAIN = 0x400,

		BUTTON_ANY = 0x7FF
	};

	static void Read();
	static bool KeyIsPressed(EButton button);
	static bool KeyDown(EButton button);
	static bool KeyUp(EButton button);

private:
	static bool KeyWasPressed(EButton button);

	static unsigned short mOldButtons;
	static unsigned short mButtons;
};

} // Core

#endif // OPENPP_PROJECTS_THESIS_CORE_INPUT_H_
