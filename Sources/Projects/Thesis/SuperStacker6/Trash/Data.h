#ifndef ___GAME_DATA__H___
#define ___GAME_DATA__H___

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <vector>
#include <string>

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
            Position.x = 0;
            Position.y = 0;
        }
    };

    class Data
    {
    public:
        Data();

        void ThrowObject(int PositionX, int PositionY);
        void Render(sf::RenderWindow *Window);
        void Update();
        void LoadData(std::string path);

        // Data
    public:
        b2World* mWorld;

    private:
        b2Vec2 mGravity;
        int OffsetX;
        void NewWorld();
        void Load(std::string path);

        float UNSCALE(int pix);
        int SCALE(float size);
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

        sf::ConvexShape mPolygon;
        b2Vec2 mVertex;
        int mVertexCount;
        int mIndex;
        float mAngle;

        sf::CircleShape mCircle;
        float mRadius;

        sf::Text mText;
        sf::Font mFont;
        char buffer[64];
    };
}

#endif // ___GAME_DATA__H___
