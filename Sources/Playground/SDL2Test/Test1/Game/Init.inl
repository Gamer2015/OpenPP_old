#include "Init.h"

namespace LSDL2 = Openpp::Objects::Objects2D::SDL2;
namespace LSDL2E = LSDL2::Exceptions;
typedef Game::Globals GG;

namespace Game
{
namespace Init
{

/// Initializes SDL2
void InitSDL2()
{
	LSDL2::Globals::Init(GG::TITLE, GG::Window, IMG_INIT_PNG | IMG_INIT_JPG);

    LSDL2::Texture::SetFont("Media/Font.ttf");
}

/// Set the Loading Screen
void SetLoadingScreen()
{
}

/// Loads Media (images etc.)
void LoadMedia()
{
}

/// Initializes all Components
void Init()
{
    InitSDL2();
    SetLoadingScreen();
    LoadMedia();
}

}
}
