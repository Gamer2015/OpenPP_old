#include "Init.h"

typedef Core::Globals CG;
typedef Game::Globals GG;
namespace CE = Core::Exceptions;

namespace Game
{
namespace Init
{

/// Initializes SDL2
void InitSDL2()
{
    SDL::Globals::Init(GG::TITLE, GG::WINDOW_X, GG::WINDOW_Y);

    /// Initialize SDL_image
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags) )
    {
        throw CE::ExSDLError( "SDL_image could not initialize", IMG_GetError() );
    }

    /// Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        throw CE::ExSDLError( "SDL_ttf could not initialize", TTF_GetError() );
    }

    SDL::Texture::LoadTextFont("Media/Font.ttf");
}

/// Set the Loading Screen
void SetLoadingScreen()
{
    GG::gpLoadingTexture = Core::Texture::LoadFromFile( "Media/Loading.jpg" );

    SDL_RenderClear( SDLG::gpRenderer );
    SDL_RenderCopy( SDLG::gpRenderer, GG::gpLoadingTexture.get(), NULL, NULL);
    SDL_RenderPresent( SDLG::gpRenderer );
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

}
}
