#ifndef OPENPP_PROJECTS_THESIS_GAME_GAME_SCREEN_H_
#define OPENPP_PROJECTS_THESIS_GAME_GAME_SCREEN_H_

#include <SDL.h>
#include <vector>
#include <memory>
#include "Data.h"
#include "../../Core/Input.h"
#include <Objects/IScreen.hpp>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Sprite.hpp>
#include <Objects/2D/SDL2/Texture.hpp>

namespace OO = Openpp::Objects;
namespace SDL = OO::SDL2;
typedef SDL::Globals SDLG;

namespace Game
{
    namespace Screens
    {
		class GameScreen : public Openpp::IScreen
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
			void Leave() {}
			void Enter() {}

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
