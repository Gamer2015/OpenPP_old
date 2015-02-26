#ifndef ___START_SCREEN__H___
#define ___START_SCREEN__H___

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Start Screen in SDL based Games
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  - Not Finished!
 *  - Needs to be Ported!
 *
\********************************************/

#include <SDL2/SDL.h>
#include "../../Core/Input.h"
#include "../../Core/Globals.h"
#include "../../Core/Screen.h"
#include "../../Core/Button.h"
#include "../../Core/Texture.h"
#include <vector>

namespace Game
{
    namespace Screens
    {
        namespace StartScreenButtons
        {
            void BTN_Start();
            void BTN_QUIT();
        }

        class StartScreen : public Core::Screen
        {
        public:
            StartScreen();
            void Init();

            void HandleInputs();

            void Update();

            void Render();

        private:
            std::vector< std::string > mPaths;

            std::vector< Core::Button > mButtons;
            Core::Button mButtonDummy;
            char mCurrentButton;

            std::shared_ptr< SDL_Texture > mpBackground;


            void BUTTON_UP();
            void BUTTON_DOWN();
        };
    }
}

#endif // ___GAME_START_SCREEN__H___
