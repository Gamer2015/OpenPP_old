#ifndef ___GAME_GAME_SCREEN__H___
#define ___GAME_GAME_SCREEN__H___

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Data.h"
#include "../../Core/Globals.h"
#include "../../Core/Screen.h"
#include "../../Core/Sprite.h"
#include "../../Core/Texture.h"
#include "../../Core/Input.h"

namespace Game
{
    namespace Screens
    {
        class GameScreen : public Core::Screen
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
            Core::Sprite mMouse;

            Core::Sprite mWhiteBox;

            float MOUSE_SPEED;
            float SPEED_FACTOR;

            bool mGameRunning;
        };
    }
}

#endif // ___GAME_GAME_SCREEN__H___
