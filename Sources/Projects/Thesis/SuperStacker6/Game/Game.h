#ifndef OPENPP_PROJECTS_THESIS_GAME_GAME_H_
#define OPENPP_PROJECTS_THESIS_GAME_GAME_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Standard Game Routine for SDL based Games
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <SDL.h>
#include "Globals.h"
#include <Objects/2D/SDL2/Globals.hpp>
#include "../../Core/Input.h"

namespace Game
{
    void GameRoutine();
    void StartGameRoutine();
}

#endif // OPENPP_PROJECTS_THESIS_GAME_GAME_H_
