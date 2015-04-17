#include "Init.h"

namespace SDL = Openpp::Objects::SDL2;
typedef Game::Globals GG;

namespace Game
{
namespace Init
{

/// Initializes SDL2
void InitSDL2()
{
    SDL::Globals::Init(GG::TITLE, GG::Window, IMG_INIT_PNG | IMG_INIT_JPG);

    SDL::Texture::SetFont("Media/Font.ttf");
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
