#ifndef ___GAME_WIN_SCREEN__H___
#define ___GAME_WIN_SCREEN__H___

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "../../Core/Globals.h"
#include "../../Core/Screen.h"
#include "../../Core/Input.h"
#include "../../Core/Button.h"

namespace Game
{
    namespace Screens
    {
		class WinScreen : public Core::Screen
        {
        public:
			WinScreen();
            void Init();

            void HandleInputs();

            void Update();

			void Render();

        protected:

		private:
            std::vector< std::string > mPaths;
			std::shared_ptr< SDL_Texture > mBackground;

			std::vector< Core::Button > mButtons;
			Core::Button mButtonDummy;
			int mCurrentButton;

			Core::Text mText;
			char mBuffer[64];

			void BUTTON_Up();
			void BUTTON_Down();
        };
    }
}

#endif // ___GAME_Win_SCREEN__H___
