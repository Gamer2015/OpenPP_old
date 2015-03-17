#include "LevelScreen.h"
#include <stdio.h>
#include <iostream>
#include "Globals.h"
#include <fstream>
#include <stdlib.h>

namespace SDL = Openpp::Objects::Objects2D::SDL2;
namespace SDLE = SDL::Exceptions;
typedef SDL::Globals SDLG;

typedef Game::Globals GG;
typedef Core::Input CI;
namespace BUTTONS = Game::Screens::LevelScreenButtons;

namespace Game
{
    namespace Screens
    {
        namespace LevelScreenButtons
        {
            void Back()
            {
				GG::gpCurrentScreen = &(GG::gStartScreen);
            }
            void StartLevel()
			{
                if(GG::gLevelScreen.CurrentButtonText().compare("?"))
				{
                    GG::gGameScreen.LoadLevel(GG::gLevelScreen.CurrentButtonText());
					GG::gpCurrentScreen = &(GG::gGameScreen);
                }
            }
        }

        void LevelScreen::BUTTON_Up()
        {
            if(--mCurrentButton.y < 0)
                mCurrentButton.y = mButtons.size() - 1;
        }
        void LevelScreen::BUTTON_Right()
        {
            if(++mCurrentButton.x == mButtons[mCurrentButton.y].size() )
                mCurrentButton.x = 0;
        }

        void LevelScreen::BUTTON_Down()
        {
            if(++mCurrentButton.y >= mButtons.size() )
                mCurrentButton.y = 0;
        }
        void LevelScreen::BUTTON_Left()
        {
            if(--mCurrentButton.x < 0 )
                mCurrentButton.x = mButtons[mCurrentButton.y].size() - 1;
        }

        std::string LevelScreen::CurrentButtonText()
        {
            return mButtons[mCurrentButton.y][mCurrentButton.x].text;
        }

        enum TextureLayer
        {
            DEFAULT,
            HOVER,

            COUNT
        };

        LevelScreen::LevelScreen()
            : mpBackground(nullptr),
              mSpace(5),
              mButtons_Row_System(5),
              mRows_System(2),
              mSystems(2, 2)
        {
            mPaths.push_back("Media/Background.jpg");
            mPaths.push_back("Media/ButtonDefault.png");
            mPaths.push_back("Media/ButtonHover.png");

        }
        void LevelScreen::Init()
        {
            mpBackground = SDL::Texture::Get( mPaths[0] );

/// Get Highest Level Reached

            std::string Line;
            std::ifstream myFile("Levels/HighestLevel.txt");

            if(myFile.is_open())
            {
                if(std::getline(myFile, Line))
                {
                    mHighestLevel = atoi(Line.c_str());
                }
            }

/// Set the Texts

            mTextDummy.origin.set(0, -1);
            mTextDummy.height.set(64);

            mTextDummy.set("Easy");
			mTextDummy.position.set(GG::WINDOW.x / 4.0, 10);
            mTexts.push_back(mTextDummy);

            mTextDummy.set("Normal");
			mTextDummy.position.add(GG::WINDOW.x / 2.0, 0);
            mTexts.push_back(mTextDummy);

            mTextDummy.set("Impossible");
			mTextDummy.position.add(0, GG::WINDOW.y / 2.0);
            mTexts.push_back(mTextDummy);

            mTextDummy.set("Hard");
			mTextDummy.position.add(-GG::WINDOW.x / 2.0, 0);
            mTexts.push_back(mTextDummy);

/// Set the Buttons

            mButtonDummy.size.set(48, 48);
            mButtonDummy.text.height.set(36);
            mButtonDummy.origin.set(-1, -1);
            mButtonDummy.SetFunction(&(BUTTONS::StartLevel));

			for(int i = 1; i < mPaths.size(); ++i)
				mButtonDummy.textures[i-1].set(SDL::Texture::Get(mPaths[i]));

            int Level;
            int Y, y;
            int X, x;

            for(Y = 0; Y < mSystems.y; Y++)
            {
				mButtonDummy.position.set(0, mTexts[2*Y].rect().y + mTexts[2*Y].rect().h + mSpace);

                for(y = 0; y < mRows_System; y++)
                {
                    for(X = 0; X < mSystems.x; X++)
                    {
						mButtonDummy.position.set((mTexts[X].rect().x + mTexts[X].rect().w / 2.0) - mButtons_Row_System/2.0*(mSpace + mButtonDummy.size.x), mButtonDummy.position.y);

                        for(x = 0; x < mButtons_Row_System; x++)
                        {
                            Level = mButtons_Row_System*mRows_System*mSystems.x*Y + mButtons_Row_System*mRows_System*X + mButtons_Row_System*y + x + 1;
                            if(Level > mHighestLevel)
                            {
                                mBuffer[0] = '?';
                                mBuffer[1] = 0;
                            }
                            else
                            {
                                sprintf(mBuffer, "%d", mButtons_Row_System*mRows_System*mSystems.x*Y + mButtons_Row_System*mRows_System*X + mButtons_Row_System*y + x + 1);
                            }

                            mButtonDummy.text.set(mBuffer);
                            mButtonRow.push_back(mButtonDummy);
							mButtonDummy.position.add(mButtonDummy.size.x + mSpace, 0);
                        }
                    }

					mButtonDummy.position.add(0, mSpace + mButtonDummy.size.y);
                    mButtons.push_back(mButtonRow);
                    mButtonRow.clear();
                }
            }
        }

        void LevelScreen::HandleInputs()
        {
            if( CI::KeyDown(CI::BUTTON_A) )
				mButtons[mCurrentButton.y][mCurrentButton.x].call();

            if( CI::KeyDown(CI::BUTTON_UP) )
                BUTTON_Up();
            if( CI::KeyDown(CI::BUTTON_RIGHT) )
                BUTTON_Right();
            if( CI::KeyDown(CI::BUTTON_DOWN) )
                BUTTON_Down();
            if( CI::KeyDown(CI::BUTTON_LEFT) )
                BUTTON_Left();

            if( CI::KeyDown(CI::BUTTON_START) )
                BUTTONS::Back();
        }

        void LevelScreen::Update()
        {

        }

        void LevelScreen::Render()
        {
			SDL_RenderCopy( SDLG::Renderer(), mpBackground.get(), NULL, NULL);

            for( int y = 0; y < mButtons.size(); y++ )
            {
                for( int x = 0; x < mButtons[y].size(); x++ )
                {
                    if( x == mCurrentButton.x && y == mCurrentButton.y )
                        mButtons[y][x].Render(HOVER);
                    else
                        mButtons[y][x].Render(DEFAULT);
                }
            }
            for( int i = 0; i < mTexts.size(); i++)
            {
                mTexts[i].Render();
            }
		}

		void LevelScreen::SetHighestLevel(int Level)
		{
			mHighestLevel = Level;
			sprintf(mBuffer, "%d", Level);

			std::ofstream HighscoreFile("Levels/HighestLevel.txt", std::ofstream::out | std::ofstream::trunc );
			HighscoreFile << Level;
			HighscoreFile.close();

			int Y, y;
			int X, x;

			for(Y = 0; Y < mSystems.y; Y++)
			{
				for(X = 0; X < mSystems.x; X++)
				{
					for(y = 0; y < mRows_System; y++)
					{
						for(x = 0; x < mButtons_Row_System; x++)
						{
							if(!((std::string)mButtons[mRows_System*Y+y][mButtons_Row_System*X+x].text).compare("?")) // is a ?-sign
							{
								Level = mButtons_Row_System*mRows_System*mSystems.x*Y + mButtons_Row_System*mRows_System*X + mButtons_Row_System*y + x + 1;
								if(Level <= mHighestLevel)
								{
									std::cout << "New Level unlocked!" << std::endl;
									sprintf(mBuffer, "%d", Level);
									mButtons[mRows_System*Y+y][mButtons_Row_System*X+x].text.set(mBuffer);
									mButtons[mRows_System*Y+y][mButtons_Row_System*X+x].Refresh();
								}
								else
									break;
							}
						}
					}
				}
			}
		}

        int LevelScreen::GetHighestLevel()
        {
            return mHighestLevel;
        }
    }
}
