#ifndef GELI_THESIS_PHYSICS
#define GELI_THESIS_PHYSICS

#include <Box2D/Box2D.h>
#include <stdio.h>

enum { PLAYER=2, NORMAL=1 };

class Physics
{
public:
	Physics();
	~Physics(){}
	b2Body* CreateWorld(float posx, float posy, float sizex, float sizey);

	b2Body* CreateObjectBox(float posx, float posy, float sizex, float sizey, float fric);

	b2Body* CreateObjectCircle(float posx, float posy, float rad, float fric);

	b2Body* CreateObjectHexagon(float posx, float posy, float rad, float fric);

	void SetGravity(float x, float y);

	void Step();

	b2World mWorld;

protected:
	float timeStep;
	int velocityIterations; 
	int positionIterations;

private:

	b2Vec2 mGravity;
	b2BodyDef DefGroundBody;
	b2PolygonShape groundbox;
	b2Body* groundbody;
private:
	b2BodyDef DefBody;
	b2Body* body;
	b2PolygonShape dynamicBox;
	b2FixtureDef DefFixture;
	b2Vec2 position;
private:
	b2CircleShape circleShape;
private:
	b2PolygonShape hexagonShape;
	int count;
    b2Vec2 vertices[6];
public:
	int type;
};

#endif
