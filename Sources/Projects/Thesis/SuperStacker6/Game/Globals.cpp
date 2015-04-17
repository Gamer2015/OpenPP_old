#include "Globals.h"

typedef Game::Globals GG;

namespace Game
{
    // Window Dimewnsions
    const char GG::TITLE[16] = "Test 2";
    const OO::Vector2<int> GG::WINDOW(640, 640 * 3.0 / 4.0);

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

    Openpp::ScreenPointer GG::gpCurrentScreen;
}
