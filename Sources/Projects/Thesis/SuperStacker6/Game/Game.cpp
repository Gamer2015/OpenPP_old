#include "Game.h"

namespace SDL = Openpp::Objects::Objects2D::SDL2;
typedef SDL::Globals SDLG;
typedef Game::Globals GG;
typedef Core::Input CI;

namespace Game
{
    void GameRoutine()
    {
        unsigned int Time;

        while( SDLG::WindowIsOpen )
        {
            Time = SDL_GetTicks();

            CI::Read();
            SDLG::gpCurrentScreen->HandleInputs();

            SDLG::gpCurrentScreen->Update();

            SDL_RenderClear( SDLG::Renderer() );
            SDLG::gpCurrentScreen->Render();
            SDL_RenderPresent( SDLG::Renderer() );

            while(SDL_GetTicks() - Time < 1000.0/GG::FPS);
        }
    }

    void StartGameRoutine()
    {
        SDLG::gpCurrentScreen = &(GG::gStartScreen);

        GameRoutine();
    }
}
