#include "Init.h"

namespace SDL = Openpp::Objects::Objects2D::SDL2;
namespace SDLE = SDL::Exceptions;
typedef SDLG SDLG;

typedef Game::Globals GG;

namespace Game
{
namespace Init
{

/// Initializes SDL2
void InitSDL2()
{
	SDLG::Init(GG::TITLE, GG::WINDOW, IMG_INIT_PNG | IMG_INIT_JPG);

	SDL::Texture::LoadFont("Media/Font.ttf", 128);
}

/// Set the Loading Screen
void SetLoadingScreen()
{
    GG::gpLoadingTexture = SDL::Texture::Get( "Media/Loading.jpg" );

    SDL_RenderClear( SDLG::Renderer() );
    SDL_RenderCopy( SDLG::Renderer(), GG::gpLoadingTexture.get(), NULL, NULL);
    SDL_RenderPresent( SDLG::Renderer() );
}

/// Loads Media (images etc.)
void LoadMedia()
{
    GG::gStartScreen.Init();
    GG::gLevelScreen.Init();
    GG::gGameScreen.Init();
    GG::gWinScreen.Init();
    GG::gLostScreen.Init();
}

/// Initializes all Components
void Init()
{
    InitSDL2();
    SetLoadingScreen();
    LoadMedia();
}

} // Init
} // Game
