#include "StartScreen.h"
#include <stdio.h>
#include "Globals.h"

typedef Core::Globals CG;
typedef Game::Globals GG;
namespace CI = Core::Input;
namespace BUTTONS = Game::Screens::StartScreenButtons;

namespace Game
{
    namespace Screens
    {
        namespace StartScreenButtons
        {
            void BTN_START()
            {
//                GG::gGameScreen.LoadWorld("Levels/Level 1");
                CG::gpCurrentScreen = &(GG::gLevelScreen);
            }
            void BTN_QUIT()
            {
                CG::WindowIsOpen = false;
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
            mpBackground = Core::Texture::LoadFromFile( mPaths[0] );

            for(int i = 1; i < mPaths.size(); ++i)
                mButtonDummy.AddTexture( mPaths[i]);

            mButtonDummy.SetSize(320, 64);
            mButtonDummy.SetOrigin(-1, -1);
            mButtonDummy.SetTextOrigin(-1, 0);
            mButtonDummy.SetTextHeight(48);

            mButtonDummy.SetPosition(0, 20);
            mButtonDummy.SetFunction(&(BUTTONS::BTN_START));
            mButtonDummy.SetText("Start");
            mButtons.push_back(mButtonDummy);

            mButtonDummy.Move(0, 64);
            mButtonDummy.SetFunction();
            mButtonDummy.SetText("Options");
            mButtons.push_back(mButtonDummy);

            mButtonDummy.Move(0, 64);
            mButtonDummy.SetFunction(&(BUTTONS::BTN_QUIT));
            mButtonDummy.SetText("Quit");
            mButtons.push_back(mButtonDummy);
        }

        void StartScreen::HandleInputs()
        {
            if( CI::KeyDown(CI::BUTTON_A) )
                mButtons[mCurrentButton].CallFunction();

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
            SDL_RenderCopy( CG::gpRenderer, mpBackground.get(), NULL, NULL);

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
