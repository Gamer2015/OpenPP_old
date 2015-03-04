#ifndef OPENPP_PROJECTS_THESIS_GAME_INIT_H_
#define OPENPP_PROJECTS_THESIS_GAME_INIT_H_

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

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <stdio.h>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Exceptions/ExSDLError.hpp>
#include <Objects/2D/SDL2/Texture.hpp>
#include "Globals.h"
#include "LevelScreen.h"
#include "StartScreen.h"
#include "GameScreen.h"
#include "WinScreen.h"
#include "LostScreen.h"

namespace OO2 = Openpp::Objects::Objects2D;
namespace SDL = OO2::SDL2;
typedef SDL::Globals SDLG;

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

} // Init
} // Game

#endif // OPENPP_PROJECTS_THESIS_GAME_INIT_H_
