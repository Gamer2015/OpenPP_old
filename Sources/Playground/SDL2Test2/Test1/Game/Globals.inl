#include "Globals.h"

typedef Game::Globals GG;

namespace Game
{
    // Window Dimewnsions
	const char GG::TITLE[32] = "Test 2";
	const O2D::Vector2<int> GG::Window(640, 480);

    // Game Spezification
    int GG::FPS = 50;
    int GG::TICKS_FPS = 40;
    bool GG::GAME_RUNNING = false;

    // Media
	std::shared_ptr< SDL_Texture > GG::gpLoadingTexture;
}
