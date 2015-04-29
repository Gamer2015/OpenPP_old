#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/Vector2.hpp>
#include <Objects/IScreen.hpp>
#include <memory>

namespace OO = Openpp::Objects;
namespace SDL = OO::SDL2;

class Globals
{
public:
	// Window Dimensions
	static const char Title[16];
	static const OO::Vector2<int> Window;

	// Game Spezification
	static const int FPS;
	static const int TICKS_FPS;
	static bool GAME_RUNNING;

	// Screens
	static Openpp::ScreenPointer gpCurrentScreen;

	static int Scaling;
};

#endif // GLOBALS_H
