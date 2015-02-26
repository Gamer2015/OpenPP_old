#include "Globals.h"

typedef Core::Globals CG;

namespace Core
{
    // Choose current Screen
    Screen* CG::gpCurrentScreen = NULL;

    // GLobal Renderer that is used
    SDL_Renderer* CG::gpRenderer = NULL;
    SDL_Renderer* CG::GetRenderer() { return gpRenderer; }

    // Global Window that is used
    SDL_Window* CG::gpWindow = NULL;
    bool CG::WindowIsOpen;
}
