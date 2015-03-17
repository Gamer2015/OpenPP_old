#include "GameScreen.h"
#include "Globals.h"
#include <stdlib.h>

typedef Game::Globals GG;
typedef Core::Input CI;

#define GRAD_RAD 0.01745329251994329576923690768489
#define RAD_GRAD 57.295779513082320876798154814105

namespace Game
{
    namespace Screens
    {
        GameScreen::GameScreen()
        {
            MOUSE_SPEED = 180.0 / GG::FPS;
            SPEED_FACTOR = 1.0;

            mPaths.push_back("Media/Background.jpg");
            mPaths.push_back("Media/Arrow.png");
            mPaths.push_back("Media/White.png");
        }
        void GameScreen::Init()
        {
            mBackground = SDL::Texture::Get(mPaths[0]);

            mMouse.set(mPaths[1]);
			mMouse.position.set(GG::WINDOW.x * 9 / 16, 5);
            mMouse.size.set(21, 21);
            mMouse.origin.set(0, -1);

            mWhiteBox.set(mPaths[2]);
			mWhiteBox.size.set(GG::WINDOW.x / 8, GG::WINDOW.y);
            mWhiteBox.origin.set(-1, -1);

            mGameData.Init();
        }

        void GameScreen::HandleInputs()
        {
            if( CI::KeyDown(CI::BUTTON_A))
                mGameData.ThrowObject(mMouse.rect().x + mMouse.size.x / 2.0, mMouse.rect().y + mMouse.rect().h + 5);

            if( CI::KeyIsPressed(CI::BUTTON_RIGHT) )
            {
                mMouse.position.x += MOUSE_SPEED * SPEED_FACTOR;
				if(mMouse.rect().x + mMouse.rect().w > GG::WINDOW.x - 5)
                {
                    mMouse.origin.set(1, -1);
					mMouse.position.set(GG::WINDOW.x - 5, 5);
                }
            }
            if( CI::KeyIsPressed(CI::BUTTON_LEFT) )
            {
                mMouse.position.x -= MOUSE_SPEED * SPEED_FACTOR;
				if(mMouse.rect().x < GG::WINDOW.x / 8 + 5)
                {
                    mMouse.origin.set(-1, -1);
					mMouse.position.set(GG::WINDOW.x / 8 + 5, 5);
                }
            }

            if( CI::KeyDown(CI::BUTTON_START) )
				GG::gpCurrentScreen = &(GG::gLevelScreen);
        }

        void GameScreen::Update()
        {
            if( mGameRunning == true )
            {
                mGameData.Update();
            }
        }

        void GameScreen::Render()
        {
            SDL_RenderCopy(SDLG::Renderer(), mBackground.get(), NULL, NULL);

            mWhiteBox.Render();

            mGameData.Render();

            mMouse.Render();
        }

		std::string GameScreen::GetCurrentLevel() const
		{
			return mCurrentLevel;
		}

        void GameScreen::LoadLevel( std::string path )
        {
			mCurrentLevel = path;

            mGameData.LoadData( path );

            mGameRunning = true;
        }
		void GameScreen::Retry()
		{
			mGameData.LoadData( mCurrentLevel );

			mGameRunning = true;
		}

		void GameScreen::WinLevel()
		{
			if(atoi(this->GetCurrentLevel().c_str()) >= GG::gLevelScreen.GetHighestLevel())
			{
				GG::gLevelScreen.SetHighestLevel(atoi(this->GetCurrentLevel().c_str()) + 1);
			}
			mGameRunning = false;
			GG::gpCurrentScreen = &(GG::gWinScreen);
		}
		void GameScreen::LostLevel()
		{
			mGameRunning = false;
			GG::gpCurrentScreen = &(GG::gLostScreen);
		}
    }
}
