#include "Data.h"
#include "Globals.h"
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>

typedef Game::Globals GG;

namespace Game
{
	std::vector<std::string> SplitString( std::string &string, std::string delimiter )
	{
		std::vector<std::string> result;

		std::size_t pos;
		int begin = 0;

		for( pos = string.find_first_of(delimiter); pos != std::string::npos; pos = string.find_first_of(delimiter, begin = pos + 1) )
		{
			result.push_back(string.substr(begin, pos - begin));
		}
		result.push_back(string.substr(begin));

		return result;
	}

    enum Layer
    {
        Rectangle,
        Circle,
		Triangle,

        Count
    };

    Data::Data() :
		OffsetX(GG::WINDOW.x / 8)
    {
        mGravity.Set(0.0f, -9.81f);

        mCircleShape.m_p.Set(0, 0);

        mFixtureDef.density = 1.0f;
        mFixtureDef.friction = 0.5f;
        mFixtureDef.restitution = 0.2f;

        mTextObjectCount.height = 20;
		mTextObjectCount.position.y = GG::WINDOW.y;
        mTextObjectCount.origin.set(-1, 1);

		mTextObjectInfo.height = 18;
		mTextObjectInfo.origin.set(0, -1);

        mPaths.push_back("Media/Red.png");
        mPaths.push_back("Media/Circle.png");
        mPaths.push_back("Media/Triangle.png");
        mPaths.push_back("Media/Clock.png");
    }

    void Data::Init()
    {
        mTextures.push_back(SDL::Texture::Get(mPaths[0]).texture);
        mTextures.push_back(SDL::Texture::Get(mPaths[1]).texture);
        mTextures.push_back(SDL::Texture::Get(mPaths[2]).texture);

        mClock.set(mPaths[3]);
        mClock.position.set(40, 40);
        mClock.size.set(64, 64);
    }

    void Data::ThrowObject(int PositionX, int PositionY)
    {
        if( mData.size() > 0)
        {
			mBodyDef.position.Set(UNSCALE(PositionX - OffsetX), UNSCALE(GG::WINDOW.y - PositionY) - mData[0].HalfSize.y );
            mBodyDef.angle = -mData[0].Angle;

            switch( mData[0].GeometryType )
            {
            case e_circle:
						mCircleShape.m_radius = mData[0].HalfSize.x;
                        mFixtureDef.shape = &(mCircleShape);
                break;
            case e_rectangle:
						mPolygonShape.SetAsBox(mData[0].HalfSize.x, mData[0].HalfSize.y);
                        mFixtureDef.shape = &(mPolygonShape);
                break;
			case e_triangle:
						mVertex.Set(-mData[0].HalfSize.x, mData[0].HalfSize.y);
						mVertices.push_back(mVertex);
						mVertex.Set(mData[0].HalfSize.x, mData[0].HalfSize.y);
						mVertices.push_back(mVertex);
						mVertex.Set(0, -mData[0].HalfSize.y);
						mVertices.push_back(mVertex);

						mPolygonShape.Set(&mVertices[0], 3);
                        mFixtureDef.shape = &(mPolygonShape);
                break;

            default:
                break;
            }
			mpBody = mWorld->CreateBody(&mBodyDef);
            mpBody->CreateFixture(&mFixtureDef);

            mData.erase(mData.begin());

			if(mData.size() == 0)
			{
				mLastElementClock = SDL_GetTicks();
                mNoMoveClock = SDL_GetTicks();
			}
        }
    }

    void Data::Update()
    {
		mWorld->Step( 1.0/GG::FPS, 8, 3);
    }

    void Data::Render()
    {
        OO::Vector2<int> Position(OffsetX / 2, OffsetX / 2 - 8);
        OO::Vector2<int> HalfSize(OffsetX / 2 - 16, OffsetX / 2 - 16);

        for(mIndex = 0; mIndex < mData.size(); ++mIndex)
        {
            mObject.size.set(SCALE(mData[mIndex].HalfSize.x * 2), SCALE(mData[mIndex].HalfSize.y * 2));

            sprintf(mBuffer, "%.0f x %.0f", (float)mObject.size.x, (float)mObject.size.y);
			mTextObjectInfo.position.set( Position.x, Position.y + HalfSize.y + 2 );
            mTextObjectInfo.set(mBuffer);
            mTextObjectInfo.Render();

            if(mObject.size.x > mObject.size.y)
            {
                mObject.size.set(2 * HalfSize.x, 2 * HalfSize.y * mObject.size.y / mObject.size.x);
            }
            else if(mObject.size.x < mObject.size.y)
            {
                mObject.size.set(2 * HalfSize.x * mObject.size.x/mObject.size.y, 2 * HalfSize.y);
            }
            else
            {
                mObject.size.set(2 * HalfSize.x, 2 * HalfSize.y);
            }

			mObject.angle = mData[mIndex].Angle;
            mObject.position = Position;

            switch( mData[mIndex].GeometryType )
            {
            case e_circle:
                mObject.set(mTextures[Circle]);
                break;
            case e_rectangle:
                mObject.set(mTextures[Rectangle]);
                break;
            case e_triangle:
                mObject.set(mTextures[Triangle]);
				break;

            default:
                break;
            }
            mObject.Render();

			Position.y += OffsetX;
        }
		static int count;
		count = 0;
		NewPositions.clear();

        for (mpBody = mWorld->GetBodyList(); mpBody != NULL; mpBody = mpBody->GetNext())
		{
			count++;
            b2Vec2 b2Pos;
			b2Pos = mpBody->GetPosition();

            OO::Vector2<float> position;
			position.x = SCALE(b2Pos.x);
			position.y = SCALE(b2Pos.y);

			NewPositions.push_back(position);

            for(mpFixture = mpBody->GetFixtureList(); mpFixture != NULL; mpFixture = mpFixture->GetNext())
            {
                b2Shape::Type shapeType = mpFixture->GetType();
				mObject.position.set(OffsetX + position.x, GG::WINDOW.y - position.y);
                mObject.angle = -mpBody->GetAngle();

                if ( shapeType == b2Shape::e_circle )
                {
                    mpCircleShape = (b2CircleShape*)mpFixture->GetShape();

                    mDiameter = 2 * SCALE(mpCircleShape->m_radius);
                    mObject.size.set(mDiameter, mDiameter);
                    mObject.set(mTextures[Circle]);
                }
                else if ( shapeType == b2Shape::e_polygon )
                {
                    mpPolygonShape = (b2PolygonShape*)mpFixture->GetShape();
                    mVertexCount = mpPolygonShape->GetVertexCount();

					mVertex = mpPolygonShape->GetVertex(0);
                    mObject.size.set(std::abs(2 * SCALE(mVertex.x)), std::abs(2 * SCALE(mVertex.y)));

					if(mVertexCount == 4)
                    {
                        mObject.set(mTextures[Rectangle]);
                    }
					if(mVertexCount == 3)
					{
                        mObject.set(mTextures[Triangle]);
					}
                }

				if(mObject.rect().y - std::max(mObject.rect().h, mObject.rect().w) > GG::WINDOW.y)
                {
					if(mpBody->GetType() == b2_dynamicBody)
					{
						mWorld->DestroyBody(mpBody);
						GG::gGameScreen.LostLevel();
					}
				}
                else
				{
                    mObject.Render();
                }
            }
		}

        if(NoBodyMoves() == false)
            mNoMoveClock = SDL_GetTicks();

        if((SDL_GetTicks() - mLastElementClock > 10*1000 ||  SDL_GetTicks() - mNoMoveClock > 2*1000) && mData.size() == 0)
		{
			GG::gGameScreen.WinLevel();
		}

		OldPositions = NewPositions;

		sprintf(mBuffer, "%d", count);

        mTextObjectCount.set(mBuffer);
        mTextObjectCount.Render();

		if(mData.size() == 0)
		{
            mClock.angle.set(2*M_PI / (10*1000) * (SDL_GetTicks() - mLastElementClock));
            mClock.Render();
		}
	}
    bool Data::NoBodyMoves()
	{
		if(OldPositions.size() != NewPositions.size())
			return false;

		for(int i = 0; i < NewPositions.size(); i++)
		{
			if(NewPositions[i] != OldPositions[i])
				return false;
		}

		return true;
	}

    void Data::LoadData( std::string path )
	{
        mNoMoveClock = SDL_GetTicks();
		mLastElementClock = SDL_GetTicks();

        NewWorld();
        Load(path);

        mBodyDef.type = b2_staticBody;

        for( mIndex = 0; mIndex < mData.size(); ++mIndex )
        {
            if(mData[mIndex].BodyType == b2_staticBody)
            {
				mBodyDef.position = mData[mIndex].Position;
				mBodyDef.angle = -mData[mIndex].Angle;

                switch( mData[mIndex].GeometryType )
                {
                case e_circle:
						mCircleShape.m_radius = mData[mIndex].HalfSize.y;
						mFixtureDef.shape = &(mCircleShape);
					break;
				case e_rectangle:
						mPolygonShape.SetAsBox( mData[mIndex].HalfSize.x, mData[mIndex].HalfSize.y);
						mFixtureDef.shape = &(mPolygonShape);
                    break;
				case e_triangle:
						mVertex.Set(-mData[mIndex].HalfSize.x, mData[mIndex].HalfSize.y);
						mVertices.push_back(mVertex);
						mVertex.Set(mData[mIndex].HalfSize.x, mData[mIndex].HalfSize.y);
						mVertices.push_back(mVertex);
						mVertex.Set(0, -mData[mIndex].HalfSize.y);
						mVertices.push_back(mVertex);

						mPolygonShape.Set(&mVertices[0],3);
						mFixtureDef.shape = &(mPolygonShape);
					break;
				default:
                    break;
                }
				mpBody = mWorld->CreateBody(&mBodyDef);
                mpBody->CreateFixture(&mFixtureDef);

                mData.erase(mData.begin() + mIndex--);
            }
        }

        mBodyDef.type = b2_dynamicBody;
    }
    void Data::NewWorld()
    {
        if(mWorld != NULL)
            delete mWorld;
        mWorld = new b2World(mGravity);
        mData.clear();
    }
    void Data::Load(std::string path)
    {
        std::string Line;
        std::vector<std::string> LineData;

		std::ifstream myFile( std::string("Levels/Level " + path + ".lvl").c_str() );
        if (myFile.is_open())
        {
            while ( std::getline(myFile, Line) )
            {
                mGeometryDummy.reset();
                mIndex = 0;

                LineData = SplitString(Line, " ");

                if( LineData[mIndex++].compare("S") == 0)
                {
                    mGeometryDummy.BodyType = b2_staticBody;

                    mGeometryDummy.Position.x = UNSCALE(atoi(LineData[mIndex++].c_str()));
                    mGeometryDummy.Position.y = UNSCALE(atoi(LineData[mIndex++].c_str()));
                }
                else
                {
                    mGeometryDummy.BodyType = b2_dynamicBody;
                }

				if( LineData[mIndex].compare("C") == 0)
					mGeometryDummy.GeometryType = e_circle;
				else if( LineData[mIndex].compare("R") == 0 )
					mGeometryDummy.GeometryType = e_rectangle;
				else if( LineData[mIndex].compare("T") == 0 )
					mGeometryDummy.GeometryType = e_triangle;
				mIndex++;

				mGeometryDummy.HalfSize.x = UNSCALE(atoi(LineData[mIndex++].c_str()) / 2.0);

				if(mIndex < LineData.size())
					mGeometryDummy.HalfSize.y = UNSCALE(atoi(LineData[mIndex++].c_str()) / 2.0);
				else
					mGeometryDummy.HalfSize.y = mGeometryDummy.HalfSize.x;

				if(mGeometryDummy.GeometryType != e_circle)
				{
                    if(mIndex < LineData.size())
                    {
                        mGeometryDummy.Angle = GRAD_RAD(atof(LineData[mIndex++].c_str()));
                    }
                }

                mData.push_back(mGeometryDummy);
            }
            myFile.close();
        }
    }

	float Data::UNSCALE(float pix)
    {
		return pix * 10.0f / GG::WINDOW.x;
    }
	float Data::SCALE(float size)
    {
		return (int)(size / 10.0f * GG::WINDOW.x);
    }
    float Data::RAD_GRAD(float rad)
    {
        return rad * 180 / M_PI;
    }
    float Data::GRAD_RAD(float grad)
    {
        return grad / 180 * M_PI;
    }
}
