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
			LSDL2::Globals::Init(GG::TITLE, GG::WINDOW_X, GG::WINDOW_Y);

            /// Initialize SDL_image
			int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
            if( !(IMG_Init(imgFlags) & imgFlags) )
            {
				throw LSDL2E::ExSDLError( "SDL_image could not initialize", IMG_GetError() );
            }

            /// Initialize SDL_ttf
            if( TTF_Init() == -1 )
            {
				throw LSDL2E::ExSDLError( "SDL_ttf could not initialize", TTF_GetError() );
			}

			LSDL2::Texture::LoadFont("Media/Font.ttf");
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
