/************************************************\
 * Author: Stefan Kreiner
 * Date: 10.12.2014
 *
 * Usage: Basics of a SFML-Based Game
 *
\************************************************/

#include "Game/Game.h"
#include "Game/Init.h"
#include "../Core/Logger.h"

namespace GI = Game::Init;

int main(int argc, char** argv)
{
    Core::Logger::LogMessage(Core::LogLevel::Info, "Starting Program");

    GI::Init();
    Game::StartGameRoutine();

    Core::Logger::LogMessage(Core::LogLevel::Info, "Successfully Finished\n");

    return 0;
}
