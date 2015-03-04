#include "Globals.h"

typedef Game::Globals GG;

namespace Game
{
    // Window Dimewnsions
    const char GG::TITLE[16] = "Test 2";
    const int GG::WINDOW_X = 640;
    const int GG::WINDOW_Y = WINDOW_X * 3.0 / 4.0; // 4:3 Screen

    const int GG::SCREEN_WIDTH = WINDOW_X;
    const int GG::SCREEN_HEIGHT = WINDOW_Y;

    // Game Spezification
    int GG::FPS = 50;
    int GG::TICKS_FPS = 40;
    bool GG::GAME_RUNNING = false;

    // Media
    std::shared_ptr< SDL_Texture > GG::gpLoadingTexture;

    // Screens
    GS::StartScreen GG::gStartScreen;
    GS::LevelScreen GG::gLevelScreen;
    GS::GameScreen GG::gGameScreen;
	GS::WinScreen GG::gWinScreen;
	GS::LostScreen GG::gLostScreen;
}
