#include "LevelScreen.h"
#include <stdio.h>
#include <iostream>
#include "Globals.h"
#include <fstream>
#include <stdlib.h>


typedef Core::Globals CG;
typedef Game::Globals GG;
namespace CI = Core::Input;
namespace BUTTONS = Game::Screens::LevelScreenButtons;

namespace Game
{
    namespace Screens
    {
        namespace LevelScreenButtons
        {
            void Back()
            {
                CG::gpCurrentScreen = &(GG::gStartScreen);
            }
            void StartLevel()
			{
                if(GG::gLevelScreen.CurrentButtonText().compare("?"))
				{
                    GG::gGameScreen.LoadLevel(GG::gLevelScreen.CurrentButtonText());
                    CG::gpCurrentScreen = &(GG::gGameScreen);
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
            return mButtons[mCurrentButton.y][mCurrentButton.x].GetText();
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
            mpBackground = Core::Texture::LoadFromFile( mPaths[0] );

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

            mTextDummy.SetTextOrigin(0, -1);
            mTextDummy.SetTextHeight(64);

            mTextDummy.SetText("Easy");
            mTextDummy.SetPosition(GG::WINDOW_X / 4.0, 10);
            mTexts.push_back(mTextDummy);

            mTextDummy.SetText("Normal");
            mTextDummy.Move(GG::WINDOW_X / 2.0, 0);
            mTexts.push_back(mTextDummy);

            mTextDummy.SetText("Impossible");
            mTextDummy.Move(0, GG::WINDOW_Y / 2.0);
            mTexts.push_back(mTextDummy);

            mTextDummy.SetText("Hard");
            mTextDummy.Move(-GG::WINDOW_X / 2.0, 0);
            mTexts.push_back(mTextDummy);

/// Set the Buttons

            mButtonDummy.SetSize(48, 48);
            mButtonDummy.SetTextHeight(36);
            mButtonDummy.SetOrigin(-1, -1);
            mButtonDummy.SetFunction(&(BUTTONS::StartLevel));

            for(int i = 1; i < mPaths.size(); ++i)
                mButtonDummy.AddTexture( mPaths[i] );

            int Level;
            int Y, y;
            int X, x;

            for(Y = 0; Y < mSystems.y; Y++)
            {
                mButtonDummy.SetPosition(0, mTexts[2*Y].GetTextRect().y + mTexts[2*Y].GetTextRect().h + mSpace);

                for(y = 0; y < mRows_System; y++)
                {
                    for(X = 0; X < mSystems.x; X++)
                    {
                        mButtonDummy.SetPosition((mTexts[X].GetTextRect().x + mTexts[X].GetTextRect().w / 2.0) - mButtons_Row_System/2.0*(mSpace + mButtonDummy.GetSize().x), mButtonDummy.GetPosition().y);

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

                            mButtonDummy.SetText(mBuffer);
                            mButtonRow.push_back(mButtonDummy);
                            mButtonDummy.Move(mButtonDummy.GetSize().x + mSpace, 0);
                        }
                    }

                    mButtonDummy.Move(0, mSpace + mButtonDummy.GetSize().y);
                    mButtons.push_back(mButtonRow);
                    mButtonRow.clear();
                }
            }
        }

        void LevelScreen::HandleInputs()
        {
            if( CI::KeyDown(CI::BUTTON_A) )
                mButtons[mCurrentButton.y][mCurrentButton.x].CallFunction();

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
            SDL_RenderCopy( CG::gpRenderer, mpBackground.get(), NULL, NULL);

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
                for(y = 0; y < mRows_System; y++)
                {
                    for(X = 0; X < mSystems.x; X++)
                    {
                        for(x = 0; x < mButtons_Row_System; x++)
                        {
                            if(!mButtons[mRows_System*Y+y][mButtons_Row_System*X+x].GetText().compare("?")) // is a ?-sign
                            {
                                Level = mButtons_Row_System*mRows_System*mSystems.x*Y + mButtons_Row_System*mRows_System*X + mButtons_Row_System*y + x + 1;

                                if(Level <= mHighestLevel)
                                {
                                    std::cout << "New Level unlocked!" << std::endl;
                                    sprintf(mBuffer, "%d", Level);
                                    mButtons[mRows_System*Y+y][mButtons_Row_System*X+x].SetText(mBuffer);
                                }
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
