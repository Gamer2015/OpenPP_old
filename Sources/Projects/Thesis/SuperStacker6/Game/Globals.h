#ifndef OPENPP_PROJECTS_THESIS_GAME_GLOBALS_H_
#define OPENPP_PROJECTS_THESIS_GAME_GLOBALS_H_

#include <SDL.h>
#include <memory>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/IScreen.hpp>
#include "StartScreen.h"
#include "LevelScreen.h"
#include "GameScreen.h"
#include "WinScreen.h"
#include "LostScreen.h"

namespace GS = Game::Screens;
namespace OO = Openpp::Objects;
namespace SDL = OO::SDL2;

namespace Game
{
    class Globals
    {
        // Window Dimensions
    public:
        static const char TITLE[16];
        static const OO::Vector2<int> WINDOW; // 4:3 Screen

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

        static Openpp::ScreenPointer gpCurrentScreen;

        // Media
    public:
        static std::shared_ptr< SDL_Texture > gpLoadingTexture;
    };
}
#endif // OPENPP_PROJECTS_THESIS_GAME_GLOBALS_H_
