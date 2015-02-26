#ifndef GAME_GLOBALS_H_
#define GAME_GLOBALS_H_

#include <SDL2/SDL.h>
#include <memory>
#include <Objects/2D/LSDL2/Globals.hpp>
#include <Objects/2D/LSDL2/Screen.hpp>

namespace Game
{
    class Globals
    {
        // Window Dimensions
    public:
		static const char TITLE[32];
        static const int WINDOW_X;
        static const int WINDOW_Y; // 4:3 Screen

        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;

        // Game Spezification
    public:
        static int FPS;
        static int TICKS_FPS;
        static bool GAME_RUNNING;

        // Media
    public:
        static std::shared_ptr< SDL_Texture > gpLoadingTexture;
    };
}

#include "Globals.inl"

#endif // ___GAME_GLOBALS__H___
