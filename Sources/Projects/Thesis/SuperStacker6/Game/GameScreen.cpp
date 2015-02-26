#include "GameScreen.h"
#include "Globals.h"
#include <stdlib.h>

typedef Core::Globals CG;
typedef Game::Globals GG;
namespace CI = Core::Input;

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
            mBackground = Core::Texture::LoadFromFile( mPaths[0] );

            mMouse.SetTexture(mPaths[1]);
            mMouse.SetPosition( GG::WINDOW_X * 9 / 16, 5);
            mMouse.SetSize(21, 21);
            mMouse.SetOrigin(0, -1);

            mWhiteBox.SetTexture(mPaths[2]);
            mWhiteBox.SetSize(GG::WINDOW_X / 8, GG::WINDOW_Y);
            mWhiteBox.SetOrigin(-1, -1);

            mGameData.Init();
        }

        void GameScreen::HandleInputs()
        {
            if( CI::KeyDown(CI::BUTTON_A))
                mGameData.ThrowObject(mMouse.GetRenderRect().x + mMouse.GetSize().x / 2.0, mMouse.GetRenderRect().y + mMouse.GetRenderRect().h + 5);

            if( CI::KeyIsPressed(CI::BUTTON_RIGHT) )
            {
                mMouse.Move(MOUSE_SPEED * SPEED_FACTOR, 0);
                if(mMouse.GetRenderRect().x + mMouse.GetRenderRect().w > GG::WINDOW_X - 5)
                {
                    mMouse.SetOrigin(1, -1);
                    mMouse.SetPosition(GG::WINDOW_X - 5, 5);
                }
            }
            if( CI::KeyIsPressed(CI::BUTTON_LEFT) )
            {
                mMouse.Move(-MOUSE_SPEED * SPEED_FACTOR, 0);
                if(mMouse.GetRenderRect().x < GG::WINDOW_X / 8 + 5)
                {
                    mMouse.SetOrigin(-1, -1);
                    mMouse.SetPosition(GG::WINDOW_X / 8 + 5, 5);
                }
            }

            if( CI::KeyDown(CI::BUTTON_START) )
                CG::gpCurrentScreen = &(GG::gLevelScreen);
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
            SDL_RenderCopy(CG::GetRenderer(), mBackground.get(), NULL, NULL);

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
			if(atoi(this->GetCurrentLevel().c_str()) > GG::gLevelScreen.GetHighestLevel())
			{
				GG::gLevelScreen.SetHighestLevel(atoi(this->GetCurrentLevel().c_str()));
			}
			mGameRunning = false;
			CG::gpCurrentScreen = &(GG::gWinScreen);
		}
		void GameScreen::LostLevel()
		{
			mGameRunning = false;
			CG::gpCurrentScreen = &(GG::gLostScreen);
		}
    }
}
