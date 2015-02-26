#include "WinScreen.h"
#include "Globals.h"
#include <stdlib.h>

typedef Game::Globals GG;
namespace CI = Core::Input;

namespace Game
{
	namespace Screens
	{
		namespace WinScreenButtons
		{
			void NextLevel()
			{
				char buffer[16];
				sprintf(buffer, "%d", atoi(GG::gGameScreen.GetCurrentLevel().c_str()) + 1);
				GG::gGameScreen.LoadLevel(buffer);
                SDLG::gpCurrentScreen = &(GG::gGameScreen);
			}
			void ChangeLevel()
			{
                SDLG::gpCurrentScreen = &(GG::gLevelScreen);
			}
		}

		enum TextureLayer
		{
			DEFAULT,
			HOVER,

			COUNT
		};

		WinScreen::WinScreen()
		{
			mPaths.push_back("Media/Background.jpg");
			mPaths.push_back("Media/ButtonDefault.png");
			mPaths.push_back("Media/ButtonHover.png");
		}
		void WinScreen::Init()
		{
			mBackground = Core::Texture::LoadFromFile( mPaths[0] );

			mText.SetText("You Win! :D");
			mText.SetPosition(GG::WINDOW_X / 2.0, GG::WINDOW_Y / 4.0);
			mText.SetTextHeight(GG::WINDOW_Y / 4.0);

			for(int i = 1; i < mPaths.size(); ++i)
				mButtonDummy.AddTexture(mPaths[i]);

			mButtonDummy.SetSize(GG::WINDOW_X * 3.0/ 4.0, GG::WINDOW_Y / 4.0 );
			mButtonDummy.SetTextHeight(GG::WINDOW_Y / 4.0);
			mButtonDummy.SetOrigin(0, -1);

			mButtonDummy.SetPosition(GG::WINDOW_X / 2.0, GG::WINDOW_Y * 3/7.0);
			mButtonDummy.SetText("Next Level");
			mButtonDummy.SetFunction(&(WinScreenButtons::NextLevel));
			mButtons.push_back(mButtonDummy);

			mButtonDummy.Move(0, GG::WINDOW_Y / 4.0);
			mButtonDummy.SetText("Back");
			mButtonDummy.SetFunction(&(WinScreenButtons::ChangeLevel));
			mButtons.push_back(mButtonDummy);
		}

		void WinScreen::HandleInputs()
		{
			if( CI::KeyDown(CI::BUTTON_A) )
				mButtons[mCurrentButton].CallFunction();

			if( CI::KeyDown(CI::BUTTON_UP) )
				BUTTON_Up();
			if( CI::KeyDown(CI::BUTTON_DOWN) )
				BUTTON_Down();
		}

		void WinScreen::Update()
		{

		}

		void WinScreen::Render()
		{
            SDL_RenderCopy(SDLG::Renderer(), mBackground.get(), NULL, NULL);

			for( int i = 0; i < mButtons.size(); i++ )
			{
				if( i == mCurrentButton )
					mButtons[i].Render(HOVER);
				else
					mButtons[i].Render(DEFAULT);
			}
            mText.Render();
		}

		void WinScreen::BUTTON_Up()
		{
			if(--mCurrentButton < 0)
				mCurrentButton = mButtons.size() - 1;
		}
		void WinScreen::BUTTON_Down()
		{
			if(++mCurrentButton == mButtons.size() )
				mCurrentButton = 0;
		}
	}
}
