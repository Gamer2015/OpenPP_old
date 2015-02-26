#ifndef ___GAME__H___
#define ___GAME__H___

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

#include <SDL2/SDL.h>
#include "Globals.h"
#include "../../Core/Globals.h"
#include "../../Core/Input.h"

namespace Game
{
    void GameRoutine();
    void StartGameRoutine();
}

#endif // ___GAME__H___
