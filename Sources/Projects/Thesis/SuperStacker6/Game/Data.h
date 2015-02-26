#ifndef ___GAME_DATA__H___
#define ___GAME_DATA__H___

#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include <vector>
#include <string>
#include "../../Core/Globals.h"
#include "../../Core/Math/Vector2.h"
#include "../../Core/Text.h"
#include "../../Core/Sprite.h"

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

        Core::Sprite mObject;
		float mDiameter;
		std::vector<b2Vec2> mVertices;
        b2Vec2 mVertex;
		int mVertexCount;

		char mBuffer[64];
		Core::Text mTextObjectCount;
        Core::Text mTextObjectInfo;

		unsigned int mLastElementClock;
		unsigned int mNoMoveClock;
		Core::Sprite mClock;

		std::vector< Vector2f > NewPositions;
		std::vector< Vector2f > OldPositions;
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

#endif // ___GAME_DATA__H___
