#ifndef OPENPP_PROJECTS_THESIS_GAME_START_SCREEN_H_
#define OPENPP_PROJECTS_THESIS_GAME_START_SCREEN_H_

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

#include <SDL.h>
#include "../../Core/Input.h"
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Screen.hpp>
#include <Objects/2D/SDL2/Button.hpp>
#include <Objects/2D/SDL2/Texture.hpp>
#include <vector>

namespace SDL = Openpp::Objects::Objects2D::SDL2;
typedef SDL::Globals SDLG;

namespace Game
{
    namespace Screens
    {
        namespace StartScreenButtons
        {
            void BTN_Start();
            void BTN_QUIT();
        }

        class StartScreen : public SDL::Screen
        {
        public:
            StartScreen();
            void Init();

            void HandleInputs();

            void Update();

            void Render();

        private:
            std::vector< std::string > mPaths;

            std::vector< SDL::Button > mButtons;
            SDL::Button mButtonDummy;
            char mCurrentButton;

            std::shared_ptr< SDL_Texture > mpBackground;


            void BUTTON_UP();
            void BUTTON_DOWN();
        };
    }
}

#endif // OPENPP_PROJECTS_THESIS_GAME_START_SCREEN_H_
