#include "LostScreen.h"
#include "Globals.h"

typedef Core::Globals CG;
typedef Game::Globals GG;
namespace CI = Core::Input;

namespace Game
{
    namespace Screens
    {
		namespace LostScreenButtons
		{
			void Retry()
			{
				GG::gGameScreen.Retry();
				CG::gpCurrentScreen = &(GG::gGameScreen);
			}
			void ChangeLevel()
			{
				CG::gpCurrentScreen = &(GG::gLevelScreen);
			}
		}

		enum TextureLayer
		{
			DEFAULT,
			HOVER,

			COUNT
		};
		LostScreen::LostScreen()
		{
			mPaths.push_back("Media/Background.jpg");
			mPaths.push_back("Media/ButtonDefault.png");
			mPaths.push_back("Media/ButtonHover.png");
        }
		void LostScreen::Init()
        {
            mBackground = Core::Texture::LoadFromFile( mPaths[0] );

			mText.text.set("You Lost! :(");
			mText.position.set(GG::WINDOW_X / 2.0, GG::WINDOW_Y / 4.0);
			mText.text.height.set(GG::WINDOW_Y / 4.0);

			for(int i = 1; i < mPaths.size(); ++i)
				mButtonDummy.AddTexture(mPaths[i]);

			mButtonDummy.size.set(GG::WINDOW_X * 3.0/ 4.0, GG::WINDOW_Y / 4.0 );
			mButtonDummy.text.height.set(GG::WINDOW_Y / 4.0);
			mButtonDummy.origin.set(0, -1);

			mButtonDummy.position.set(GG::WINDOW_X / 2.0, GG::WINDOW_Y * 3 / 7.0);
			mButtonDummy.text.set("Retry");
			mButtonDummy.SetFunction(&(LostScreenButtons::Retry));
			mButtons.push_back(mButtonDummy);

			mButtonDummy.position.add(0, GG::WINDOW_Y / 4.0);
			mButtonDummy.text.set("Back");
			mButtonDummy.SetFunction(&(LostScreenButtons::ChangeLevel));
			mButtons.push_back(mButtonDummy);
        }

		void LostScreen::HandleInputs()
		{
			if( CI::KeyDown(CI::BUTTON_A) )
				mButtons[mCurrentButton].CallFunction();

			if( CI::KeyDown(CI::BUTTON_UP) )
				BUTTON_Up();
			if( CI::KeyDown(CI::BUTTON_DOWN) )
				BUTTON_Down();
        }

		void LostScreen::Update()
		{

        }

		void LostScreen::Render()
        {
            SDL_RenderCopy(CG::GetRenderer(), mBackground.get(), NULL, NULL);

			for( int i = 0; i < mButtons.size(); i++ )
			{
				if( i == mCurrentButton )
					mButtons[i].Render(HOVER);
				else
					mButtons[i].Render(DEFAULT);
			}
			mText.Render();
		}

		void LostScreen::BUTTON_Up()
		{
			if(--mCurrentButton < 0)
				mCurrentButton = mButtons.size() - 1;
		}
		void LostScreen::BUTTON_Down()
		{
			if(++mCurrentButton == mButtons.size() )
				mCurrentButton = 0;
		}
    }
}
