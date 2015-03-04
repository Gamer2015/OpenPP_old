#ifndef OPENPP_PROJECTS_THESIS_GAME_WIN_SCREEN_H_
#define OPENPP_PROJECTS_THESIS_GAME_WIN_SCREEN_H_

#include <SDL.h>
#include <vector>
#include <memory>
#include "../../Core/Input.h"
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Screen.hpp>
#include <Objects/2D/SDL2/Button.hpp>
#include <Objects/2D/SDL2/Text.hpp>

namespace SDL = Openpp::Objects::Objects2D::SDL2;
typedef SDL::Globals SDLG;

namespace Game
{
    namespace Screens
    {
        class WinScreen : public SDL::Screen
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

            std::vector< SDL::Button > mButtons;
            SDL::Button mButtonDummy;
			int mCurrentButton;

            SDL::Text mText;
			char mBuffer[64];

			void BUTTON_Up();
			void BUTTON_Down();
        };
    }
}

#endif // OPENPP_PROJECTS_THESIS_GAME_WIN_SCREEN_H_
