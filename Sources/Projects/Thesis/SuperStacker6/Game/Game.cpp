#include "Game.h"

typedef Game::Globals GG;
typedef Core::Globals CG;
namespace CI = Core::Input;

namespace Game
{
    void GameRoutine()
    {
        unsigned int Time;

        while( CG::WindowIsOpen )
        {
            Time = SDL_GetTicks();

            CI::Read();
            CG::gpCurrentScreen->HandleInputs();

            CG::gpCurrentScreen->Update();

            SDL_RenderClear( CG::GetRenderer() );
            CG::gpCurrentScreen->Render();
            SDL_RenderPresent( CG::GetRenderer() );

            while(SDL_GetTicks() - Time < 1000.0/GG::FPS);
        }
    }

    void StartGameRoutine()
    {
        CG::gpCurrentScreen = &(GG::gStartScreen);

        GameRoutine();
    }
}
