#include "Data.h"
#include "Globals.h"
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

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

    Data::Data() :
        OffsetX(GG::WINDOW_X / 8)
    {
        mGravity.Set(0.0f, -9.81f);

        mCircleShape.m_p.Set(0, 0);

        mCircle.setFillColor(sf::Color::Red);
        mPolygon.setFillColor(sf::Color::Red);
        mCircle.setOutlineColor(sf::Color::Red);
        mPolygon.setOutlineColor(sf::Color::Red);

        mFixtureDef.density = 1.0f;
        mFixtureDef.friction = 0.5f;
        mFixtureDef.restitution = 0.2f;

        mFont.loadFromFile("Media/Font.ttf");
        mText.setFont( mFont );
        mText.setColor(sf::Color::Black);
    }

    void Data::ThrowObject(int PositionX, int PositionY)
    {
        if( mData.size() > 0)
        {
            mBodyDef.position.Set( UNSCALE(PositionX - OffsetX), UNSCALE(GG::WINDOW_Y - PositionY) - mData[0].HalfSize.y );
            mpBody = mWorld->CreateBody(&mBodyDef);

            switch( mData[0].GeometryType )
            {
            case e_circle:
                        mCircleShape.m_radius = mData[0].HalfSize.y;
                        mFixtureDef.shape = &(mCircleShape);
                break;
            case e_rectangle:
                        mPolygonShape.SetAsBox(mData[0].HalfSize.x, mData[0].HalfSize.y, b2Vec2(0, 0), mData[0].Angle );
                        mFixtureDef.shape = &(mPolygonShape);
                break;
            case e_triangle:
                        // Set the Points
                        mFixtureDef.shape = &(mPolygonShape);
                break;

            default:
                break;
            }
            mpBody->CreateFixture(&mFixtureDef);

            mData.erase(mData.begin());
        }
    }

    void Data::Update()
    {
        mWorld->Step( 1.0/GG::FPS, 8, 3);

        b2Body* pBody;
        for (mpBody = mWorld->GetBodyList(); mpBody != NULL; mpBody = pBody)
        {
            pBody = mpBody->GetNext();

            b2Vec2 position = mpBody->GetPosition();

            if(position.y < -10.0f)
            {
                mWorld->DestroyBody(mpBody);
            }
        }
    }

    void Data::Render(sf::RenderWindow *Window)
    {
        sf::Vector2f Position(OffsetX / 2, OffsetX / 2);
        sf::Vector2f HalfSize(OffsetX / 2 - 8, OffsetX / 2 - 8);
        sf::Vector2f Point;
        int i;

        for(mIndex = 0; mIndex < mData.size(); ++mIndex)
        {
            i = 0;

            switch( mData[mIndex].GeometryType )
            {
            case e_circle:
                        mCircle.setRadius( HalfSize.y );
                        mCircle.setPosition(Position);
                        mCircle.setOrigin( HalfSize );

                        Window->draw(mCircle);

                        sprintf(buffer, "%d x %d", SCALE(mData[mIndex].HalfSize.y * 2), SCALE(mData[mIndex].HalfSize.y * 2));
                        mText.setPosition( Position );
                        mText.setCharacterSize(16);
                        mText.move( -HalfSize.y + 8, -12 );
                        mText.setString(buffer);

                        Window->draw(mText);
                break;
            case e_rectangle:
                        mPolygon.setPosition( Position );
                        mPolygon.setOrigin( HalfSize );
                        mPolygon.setPointCount(4);

                        Point.x = 0;
                        Point.y = 0;
                        mPolygon.setPoint(i++, Point);
                        Point.x = 2 * HalfSize.x;
                        mPolygon.setPoint(i++, Point);
                        Point.y = 2 * HalfSize.y;
                        mPolygon.setPoint(i++, Point);
                        Point.x = 0;
                        mPolygon.setPoint(i++, Point);

                        Window->draw(mPolygon);

                        sprintf(buffer, "%d x %d\n  %.1f%c", SCALE(mData[mIndex].HalfSize.x * 2.0), SCALE(mData[mIndex].HalfSize.y * 2.0), RAD_GRAD(mData[mIndex].Angle), '°');
                        mText.setPosition( Position );
                        mText.move( -HalfSize.x + 8, -HalfSize.y/2 );
                        mText.setCharacterSize(16);
                        mText.setString(buffer);

                        Window->draw(mText);
                break;
            case e_triangle:
                break;

            default:
                break;
            }
            Position.y += OffsetX;
        }
        int count = 0;
        mPolygon.setOrigin( 0, 0 );

        for (mpBody = mWorld->GetBodyList(); mpBody != NULL; mpBody = mpBody->GetNext())
        {
            count++;
            b2Vec2 position = mpBody->GetPosition();
            position.x = SCALE(position.x);
            position.y = SCALE(position.y);

            for(mpFixture = mpBody->GetFixtureList(); mpFixture != NULL; mpFixture = mpFixture->GetNext())
            {
                b2Shape::Type shapeType = mpFixture->GetType();

                if ( shapeType == b2Shape::e_circle )
                {
                    mpCircleShape = (b2CircleShape*)mpFixture->GetShape();
                    mRadius = SCALE(mpCircleShape->m_radius);

                    mCircle.setRadius( mRadius );
                    mCircle.setPosition( OffsetX + position.x, GG::WINDOW_Y - position.y );
                    mCircle.setOrigin( mRadius, mRadius );

                    Window->draw(mCircle);
                }
                else if ( shapeType == b2Shape::e_polygon )
                {
                    mpPolygonShape = (b2PolygonShape*)mpFixture->GetShape();

                    mVertexCount = mpPolygonShape->GetVertexCount();
                    mAngle = RAD_GRAD(mpBody->GetAngle());

                    mPolygon.setRotation(- mAngle);
                    mPolygon.setPointCount(mVertexCount);
                    mPolygon.setPosition( OffsetX + position.x, GG::WINDOW_Y - position.y );

                    for(mIndex = 0; mIndex < mVertexCount; mIndex++)
                    {
                        mVertex = mpPolygonShape->GetVertex(mIndex);
                        mPolygon.setPoint(mIndex, sf::Vector2f( SCALE(mVertex.x), -SCALE(mVertex.y)));
                    }

                    Window->draw(mPolygon);
                }
            }
        }

        sprintf(buffer, "%d", count);

        mText.setString(buffer);
        mText.setCharacterSize(20);
        mText.setPosition(5, GG::WINDOW_Y - 25);

        Window->draw(mText);
    }

    void Data::LoadData( std::string path )
    {
        NewWorld();
        Load(path);

        mBodyDef.type = b2_staticBody;

        for( mIndex = 0; mIndex < mData.size(); ++mIndex )
        {
            if(mData[mIndex].BodyType == b2_staticBody)
            {
                mBodyDef.position = mData[mIndex].Position;
                mpBody = mWorld->CreateBody(&mBodyDef);

                switch( mData[mIndex].GeometryType )
                {
                case e_circle:
                            mCircleShape.m_radius = mData[mIndex].HalfSize.y;
                            mFixtureDef.shape = &(mCircleShape);
                    break;
                case e_rectangle:
                            mPolygonShape.SetAsBox( mData[mIndex].HalfSize.x, mData[mIndex].HalfSize.y, b2Vec2(0, 0), mData[mIndex].Angle );
                            mFixtureDef.shape = &(mPolygonShape);
                    break;

                default:
                    break;
                }
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

        std::ifstream myFile( (path+".ocl").c_str() );
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

                if( LineData[mIndex++].compare("C") == 0)
                {
                    mGeometryDummy.GeometryType = e_circle;

                    mGeometryDummy.HalfSize.y = UNSCALE(atoi(LineData[mIndex++].c_str()) / 2.0);
                }
                else
                {
                    mGeometryDummy.GeometryType = e_rectangle;

                    mGeometryDummy.HalfSize.x = UNSCALE(atoi(LineData[mIndex++].c_str()) / 2.0);
                    mGeometryDummy.HalfSize.y = UNSCALE(atoi(LineData[mIndex++].c_str()) / 2.0);

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

    float Data::UNSCALE(int pix)
    {
        return pix * 10.0f / GG::WINDOW_X;
    }
    int Data::SCALE(float size)
    {
        return (int)(size / 10.0f * GG::WINDOW_X);
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
