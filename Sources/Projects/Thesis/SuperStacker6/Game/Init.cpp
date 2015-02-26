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
            if( SDL_Init(SDL_INIT_VIDEO) < 0 )
            {
                throw CE::ExSDLError( "SDL could not initialize", SDL_GetError() );
            }

            CG::gpWindow = SDL_CreateWindow(GG::TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GG::WINDOW_X, GG::WINDOW_Y, SDL_WINDOW_SHOWN);
            if( CG::gpWindow == NULL )
            {
                throw CE::ExSDLError( "Window could not be created", SDL_GetError() );
            }
            CG::WindowIsOpen = true;

            CG::gpRenderer = SDL_CreateRenderer( CG::gpWindow, -1, SDL_RENDERER_ACCELERATED );
            if( CG::gpRenderer == NULL )
            {
                throw CE::ExSDLError( "Renderer could not be created", SDL_GetError() );
            }
            SDL_SetRenderDrawColor( CG::gpRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

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

            Core::Texture::LoadTextFont("Media/Font.ttf");
        }

        /// Set the Loading Screen
        void SetLoadingScreen()
        {
            GG::gpLoadingTexture = Core::Texture::LoadFromFile( "Media/Loading.jpg" );

            SDL_RenderClear( CG::gpRenderer );
            SDL_RenderCopy( CG::gpRenderer, GG::gpLoadingTexture.get(), NULL, NULL);
            SDL_RenderPresent( CG::gpRenderer );
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
