#ifndef OPENPP_PROJECTS_THESIS_GAME_DATA_H_
#define OPENPP_PROJECTS_THESIS_GAME_DATA_H_

#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include <vector>
#include <string>
#include <Objects/2D/Vector2.hpp>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Text.hpp>
#include <Objects/2D/SDL2/Sprite.hpp>

namespace OO2 = Openpp::Objects::Objects2D;
namespace SDL = OO2::SDL2;
typedef SDL::Globals SDLG;

namespace Game
{
    enum EGeometryType
    {
        e_circle,
        e_rectangle,
        e_triangle
    };

    struct GeometryData // ALL data in Size / Rad
    {
        b2BodyType BodyType;
        // Static Objects
        b2Vec2 Position;

        EGeometryType GeometryType;

        // All
        b2Vec2 HalfSize;


        // NOT Circle
        float Angle;

        void reset()
        {
			Angle = 0;
			Position.SetZero();
			HalfSize.SetZero();
        }
    };

    class Data
    {
    public:
        Data();

        void ThrowObject(int PositionX, int PositionY);
        void Render();
        void Update();
        void LoadData(std::string path);
        void Init();

        // Data
    public:
        b2World* mWorld;

    private:
        b2Vec2 mGravity;
        int OffsetX;
        void NewWorld();
        void Load(std::string path);

		float UNSCALE(float pix);
		float SCALE(float size);
        float RAD_GRAD(float rad);
        float GRAD_RAD(float grad);

        // Usefull stuff
        std::vector<GeometryData> mData;
        GeometryData mGeometryDummy;

        b2Body* mpBody;
        b2BodyDef mBodyDef;
        b2Fixture* mpFixture;
        b2FixtureDef mFixtureDef;
        b2CircleShape mCircleShape;
        b2CircleShape* mpCircleShape;
        b2PolygonShape mPolygonShape;
        b2PolygonShape* mpPolygonShape;

        int mIndex;
        std::vector< std::string > mPaths;

        std::vector< std::shared_ptr< SDL_Texture > > mTextures;

        SDL::Sprite<float> mObject;
		float mDiameter;
		std::vector<b2Vec2> mVertices;
        b2Vec2 mVertex;
		int mVertexCount;

		char mBuffer[64];
        SDL::Text mTextObjectCount;
        SDL::Text mTextObjectInfo;

		unsigned int mLastElementClock;
		unsigned int mNoMoveClock;
        SDL::Sprite<int> mClock;

        std::vector< OO2::Vector2<float> > NewPositions;
        std::vector< OO2::Vector2<float> > OldPositions;
		bool NoBodyMoves();
/*
        sf::ConvexShape mPolygon;
        float mAngle;

        sf::CircleShape mCircle;

        sf::Text mText;
        sf::Font mFont;
*/
    };
}

#endif // OPENPP_PROJECTS_THESIS_GAME_DATA_H_
