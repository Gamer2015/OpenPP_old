#include "StartScreen.h"
#include <stdio.h>
#include "Globals.h"

typedef Game::Globals GG;
typedef Core::Input CI;
namespace BUTTONS = Game::Screens::StartScreenButtons;

namespace Game
{
    namespace Screens
    {
        namespace StartScreenButtons
        {
            void BTN_START()
			{
				GG::gpCurrentScreen = &(GG::gLevelScreen);
            }
            void BTN_QUIT()
            {
                SDLG::WindowIsOpen = false;
            }
        }

        void StartScreen::BUTTON_UP()
        {
            if(--mCurrentButton < 0)
                mCurrentButton = mButtons.size() - 1;
        }
        void StartScreen::BUTTON_DOWN()
        {
            if(++mCurrentButton == mButtons.size() )
                mCurrentButton = 0;
        }

        enum TextureLayer
        {
            DEFAULT,
            HOVER,

            COUNT
        };

        StartScreen::StartScreen()
            : mpBackground(nullptr)
        {
            mCurrentButton = 0;

            mPaths.push_back("Media/Background.jpg");
            mPaths.push_back("Media/ButtonDefault.png");
            mPaths.push_back("Media/ButtonHover.png");
        }
        void StartScreen::Init()
        {
			mpBackground = SDL::Texture::Get( mPaths[0] );

			for(int i = 1; i < mPaths.size(); ++i)
				mButtonDummy.textures[i-1].set(SDL::Texture::Get(mPaths[i]));

            mButtonDummy.size.set(320, 64);
            mButtonDummy.origin.set(-1, -1);
            mButtonDummy.text.origin.set(-1, 0);
            mButtonDummy.text.height.set(48);

            mButtonDummy.position.set(0, 20);
			mButtonDummy.SetFunction(&(BUTTONS::BTN_START));
            mButtonDummy.text.set("Start");
            mButtons.push_back(mButtonDummy);

            mButtonDummy.position.add(0, 64);
            mButtonDummy.SetFunction();
            mButtonDummy.text.set("Options");
            mButtons.push_back(mButtonDummy);

            mButtonDummy.position.add(0, 64);
            mButtonDummy.SetFunction(&(BUTTONS::BTN_QUIT));
            mButtonDummy.text.set("Quit");
            mButtons.push_back(mButtonDummy);
        }

        void StartScreen::HandleInputs()
        {
            if( CI::KeyDown(CI::BUTTON_A) )
				mButtons[mCurrentButton].call();

            if( CI::KeyDown(CI::BUTTON_UP) )
                BUTTON_UP();

            if( CI::KeyDown(CI::BUTTON_DOWN) )
                BUTTON_DOWN();

            if( CI::KeyDown(CI::BUTTON_START) )
                BUTTONS::BTN_START();
        }

        void StartScreen::Update()
        {

        }

        void StartScreen::Render()
        {
            SDL_RenderCopy( SDLG::Renderer(), mpBackground.get(), NULL, NULL);

            for( char iter = 0; iter < mButtons.size(); iter++ )
            {
                if( iter == mCurrentButton )
                    mButtons[iter].Render(HOVER);
                else
                    mButtons[iter].Render(DEFAULT);
            }
        }
    }
}
