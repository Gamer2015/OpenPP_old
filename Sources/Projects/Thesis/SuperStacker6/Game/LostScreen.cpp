#include "LostScreen.h"
#include "Globals.h"

namespace SDL = Openpp::Objects::Objects2D::SDL2;
namespace SDLE = SDL::Exceptions;
typedef SDL::Globals SDLG;

typedef Game::Globals GG;
typedef Core::Input CI;

namespace Game
{
    namespace Screens
    {
		namespace LostScreenButtons
		{
			void Retry()
			{
				GG::gGameScreen.Retry();
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
		LostScreen::LostScreen()
		{
			mPaths.push_back("Media/Background.jpg");
			mPaths.push_back("Media/ButtonDefault.png");
			mPaths.push_back("Media/ButtonHover.png");
        }
		void LostScreen::Init()
        {
			mBackground = SDL::Texture::Get( mPaths[0] );

			mText.set("You Lost! :(");
			mText.position.set(GG::WINDOW.x / 2.0, GG::WINDOW.y / 4.0);
			mText.height.set(GG::WINDOW.y / 4.0);

			for(int i = 1; i < mPaths.size(); ++i)
				mButtonDummy.textures[i-1].set(SDL::Texture::Get(mPaths[i]));

			mButtonDummy.size.set(GG::WINDOW.x * 3.0/ 4.0, GG::WINDOW.y / 4.0 );
			mButtonDummy.text.height.set(GG::WINDOW.y / 4.0);
			mButtonDummy.origin.set(0, -1);

			mButtonDummy.position.set(GG::WINDOW.x / 2.0, GG::WINDOW.y * 3 / 7.0);
			mButtonDummy.text.set("Retry");
			mButtonDummy.SetFunction(&(LostScreenButtons::Retry));
			mButtons.push_back(mButtonDummy);

			mButtonDummy.position.add(0, GG::WINDOW.y / 4.0);
			mButtonDummy.text.set("Back");
			mButtonDummy.SetFunction(&(LostScreenButtons::ChangeLevel));
			mButtons.push_back(mButtonDummy);
        }

		void LostScreen::HandleInputs()
		{
			if( CI::KeyDown(CI::BUTTON_A) )
				mButtons[mCurrentButton].call();

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
