/************************************************\
 * Author: Stefan Kreiner
 * Date: 10.12.2014
 *
 * Usage: Basics of a SFML-Based Game
 *
\************************************************/

#include "Game/Game.h"
#include "Game/Init.h"

namespace GI = Game::Init;

int main(int argc, char** argv)
{
    GI::Init();
    Game::StartGameRoutine();

    return 0;
}
