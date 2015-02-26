#ifndef ___LEVEL_SCREEN__H___
#define ___LEVEL_SCREEN__H___

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Level Screen in SDL based Games
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
#include "../../Core/Text.h"
#include "../../Core/Texture.h"
#include "../../Core/Math/Vector2.h"
#include <vector>

namespace Game
{
    namespace Screens
    {
        namespace LevelScreenButtons
        {
            void BTN_Start();
            void BTN_QUIT();
        }

        class LevelScreen : public Core::Screen
        {
        public:
            LevelScreen();
            void Init();

            void HandleInputs();

            void Update();

            void Render();

            void SetHighestLevel(int Level);

            int GetHighestLevel();

            std::string CurrentButtonText();

        private:
            int mHighestLevel;
            std::vector< std::string > mPaths;

            std::vector< std::vector< Core::Button > > mButtons;
            std::vector< Core::Button > mButtonRow;
            Core::Button mButtonDummy;
            Vector2<int> mCurrentButton;
            int mSpace;

            int mButtons_Row_System;
            int mRows_System;
            Vector2<int> mSystems;

            std::vector< Core::Text > mTexts;
            Core::Text mTextDummy;
            char mBuffer[64];

            std::shared_ptr< SDL_Texture > mpBackground;

            void BUTTON_Up();
            void BUTTON_Right();
            void BUTTON_Down();
            void BUTTON_Left();
        };
    }
}

#endif // ___GAME_START_SCREEN__H___
