#ifndef ___CORE_GLOBALS__H___
#define ___CORE_GLOBALS__H___

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Global Core Elements of each SDL Based Program
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <SDL2/SDL.h>
#include "Screen.h"

namespace Core
{
    class Globals
    {
    public:
        // Global Screen Pointer
        static Screen* gpCurrentScreen;

        // Global Renderer
        static SDL_Renderer* gpRenderer;
        static SDL_Renderer* GetRenderer();

        // Global Window
        static SDL_Window* gpWindow;
        static bool WindowIsOpen;
    };
}

#endif // ___CORE_GLOBALS__H___
