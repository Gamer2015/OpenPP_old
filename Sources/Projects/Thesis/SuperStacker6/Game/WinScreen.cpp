#include "WinScreen.h"
#include "Globals.h"
#include <stdlib.h>

typedef Game::Globals GG;
typedef Core::Input CI;

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
				GG::gpCurrentScreen = &(GG::gGameScreen);
			}
			void ChangeLevel()
			{
				GG::gpCurrentScreen = &(GG::gLevelScreen);
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
            mBackground = SDL::Texture::Get( mPaths[0] ).texture;

			mText.set("You Win! :D");
			mText.position.set(GG::WINDOW.x / 2.0, GG::WINDOW.y / 4.0);
			mText.height.set(GG::WINDOW.y / 4.0);

			for(int i = 1; i < mPaths.size(); ++i)
				mButtonDummy.textures[i-1].set(SDL::Texture::Get(mPaths[i]));

			mButtonDummy.size.set(GG::WINDOW.x * 3.0/ 4.0, GG::WINDOW.y / 4.0 );
			mButtonDummy.text.height.set(GG::WINDOW.y / 4.0);
			mButtonDummy.origin.set(0, -1);

			mButtonDummy.position.set(GG::WINDOW.x / 2.0, GG::WINDOW.y * 3/7.0);
			mButtonDummy.text.set("Next Level");
			mButtonDummy.function = ((WinScreenButtons::NextLevel));
			mButtons.push_back(mButtonDummy);

			mButtonDummy.position.add(0, GG::WINDOW.y / 4.0);
			mButtonDummy.text.set("Back");
			mButtonDummy.function = ((WinScreenButtons::ChangeLevel));
			mButtons.push_back(mButtonDummy);
		}

		void WinScreen::HandleInputs()
		{
			if( CI::KeyDown(CI::BUTTON_A) )
				mButtons[mCurrentButton].function();

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
