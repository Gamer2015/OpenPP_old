#ifndef GAME_INIT_H_
#define GAME_INIT_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Init Functions for SDL based Games
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  - Not Finished!
 *
\********************************************/

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <stdio.h>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Exceptions/ExSDLError.hpp>
#include <Objects/2D/SDL2/Texture.hpp>
#include "Globals.h"

namespace Game
{
    namespace Init
    {
        /// Initialize SDL
        void InitSDL2();

        /// Loads the Loading-Screen
        void SetLoadingScreen();

        /// Loads Media
        void LoadMedia();

        /// Initializes all Components
        void Init();
    }
}

#include "Init.inl"

#endif // ___GAME_INIT__H___
