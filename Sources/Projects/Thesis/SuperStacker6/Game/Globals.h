#ifndef OPENPP_PROJECTS_THESIS_GAME_GLOBALS_H_
#define OPENPP_PROJECTS_THESIS_GAME_GLOBALS_H_

#include <SDL.h>
#include <memory>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Screen.hpp>
#include "StartScreen.h"
#include "LevelScreen.h"
#include "GameScreen.h"
#include "WinScreen.h"
#include "LostScreen.h"

namespace GS = Game::Screens;

namespace Game
{
    class Globals
    {
        // Window Dimensions
    public:
        static const char TITLE[16];
        static const int WINDOW_X;
        static const int WINDOW_Y; // 4:3 Screen

        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;

        // Game Spezification
    public:
        static int FPS;
        static int TICKS_FPS;
        static bool GAME_RUNNING;

        // Screens
    public:
        static GS::StartScreen gStartScreen;
        static GS::LevelScreen gLevelScreen;
        static GS::GameScreen gGameScreen;
		static GS::WinScreen gWinScreen;
		static GS::LostScreen gLostScreen;

        // Media
    public:
        static std::shared_ptr< SDL_Texture > gpLoadingTexture;
    };
}
#endif // ___GAME_GLOBALS__H___
