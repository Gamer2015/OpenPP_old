#include "Game.h"

namespace SDL = Openpp::Objects::SDL2;
typedef SDL::Globals SDLG;
typedef Game::Globals GG;
typedef Core::Input CI;

namespace Game
{
    void GameRoutine()
	{
        while( SDLG::WindowIsOpen )
        {
			unsigned int Time(SDL_GetTicks());

            CI::Read();
			GG::gpCurrentScreen->HandleInputs();

			GG::gpCurrentScreen->Update();

            SDL_RenderClear( SDLG::Renderer() );
			GG::gpCurrentScreen->Render();
            SDL_RenderPresent( SDLG::Renderer() );

			if(SDL_GetTicks() - Time < 1000.0/Globals::FPS)
				SDL_Delay(1000.0/Globals::FPS - (SDL_GetTicks() - Time));
        }
    }

    void StartGameRoutine()
    {
		GG::gpCurrentScreen = &(GG::gStartScreen);

        GameRoutine();
    }
}
