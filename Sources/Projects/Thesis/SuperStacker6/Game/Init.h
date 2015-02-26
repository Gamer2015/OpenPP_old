#ifndef ___GAME_INIT__H___
#define ___GAME_INIT__H___

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
#include "../../Core/Globals.h"
#include "../../Core/Exceptions/ExSDLError.h"
#include "../../Core/Texture.h"
#include "Globals.h"
#include "LevelScreen.h"
#include "StartScreen.h"
#include "GameScreen.h"
#include "WinScreen.h"
#include "LostScreen.h"

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

#endif // ___GAME_INIT__H___
