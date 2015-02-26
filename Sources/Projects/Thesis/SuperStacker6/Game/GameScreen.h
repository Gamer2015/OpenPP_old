#ifndef OPENPP_PROJECTS_THESIS_GAME_GAME_SCREEN_H_
#define OPENPP_PROJECTS_THESIS_GAME_GAME_SCREEN_H_

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Data.h"
#include "../../Core/Input.h"
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Screen.hpp>
#include <Objects/2D/SDL2/Sprite.hpp>
#include <Objects/2D/SDL2/Texture.hpp>

namespace OO2 = Openpp::Objects::Objects2D;
namespace SDL = OO2::SDL2;
typedef SDL::Globals SDLG;

namespace Game
{
    namespace Screens
    {
        class GameScreen : public SDL::Screen
        {
        public:
            GameScreen();
            void Init();

            void HandleInputs();

            void Update();

            void Render();

			std::string GetCurrentLevel() const;

            void LoadLevel( std::string path );
			void Retry();

			void WinLevel();
			void LostLevel();

        protected:

        private:
            Game::Data mGameData;
			std::string mCurrentLevel;

            std::vector< std::string > mPaths;
            std::shared_ptr< SDL_Texture > mBackground;
            SDL::Sprite<float> mMouse;

            SDL::Sprite<int> mWhiteBox;

            float MOUSE_SPEED;
            float SPEED_FACTOR;

            bool mGameRunning;
        };
    }
}

#endif // OPENPP_PROJECTS_THESIS_GAME_GAME_SCREEN_H_
