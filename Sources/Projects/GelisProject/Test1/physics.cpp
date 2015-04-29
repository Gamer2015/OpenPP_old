#include "physics.h"

Physics::Physics() 
: mWorld(b2Vec2(0.0,0.0)),
velocityIterations(6),	
positionIterations(2),
timeStep(1.0f / 60.0),
count(6)
{
	mWorld.SetAllowSleeping(false);
}

b2Body* Physics::CreateWorld(float posx, float posy, float sizex, float sizey)
{
	mGravity.Set(0.0f, -10.0f);

	mWorld.SetGravity(mGravity);

	DefGroundBody.position.Set(posx, posy);

	DefGroundBody.type = b2_staticBody;

	groundbody = mWorld.CreateBody(&DefGroundBody);

	groundbox.SetAsBox(sizex, sizey);

	groundbody->CreateFixture(&groundbox, 0.0f);

	return groundbody;
}

b2Body* Physics::CreateObjectBox(float posx, float posy, float sizex, float sizey, float fric)
{
	DefBody.type = b2_dynamicBody;

	DefBody.position.Set(posx, posy);

	body = mWorld.CreateBody(&DefBody);

	dynamicBox.SetAsBox(sizex, sizey);

	DefFixture.shape = &dynamicBox;

	DefFixture.density = 1.0f;

	DefFixture.friction = fric;

	body->CreateFixture(&DefFixture);

	return body;
}

b2Body* Physics::CreateObjectCircle(float posx, float posy, float rad, float fric)
{
	DefBody.type = b2_dynamicBody;

	body = mWorld.CreateBody(&DefBody);

	circleShape.m_p.Set(0.0f, 0.0f);

	circleShape.m_radius = rad;

	DefFixture.shape = &circleShape;

	DefFixture.density = 1.0f;

	DefFixture.friction = fric;

	body->CreateFixture(&DefFixture);

	return body;
}

b2Body* Physics::CreateObjectHexagon(float posx, float posy, float rad, float fric)
{
	DefBody.type = b2_dynamicBody;

	DefBody.position.Set(posx, posy);

	body = mWorld.CreateBody(&DefBody);

    vertices[0].Set(1/3.0f * rad, 0.0f);
    vertices[1].Set(2/3.0f * rad, 0.0f);
    vertices[2].Set(rad, 0.5f * rad);
    vertices[3].Set(2/3.0f * rad, rad);
    vertices[4].Set(1/3.0f * rad, rad);
    vertices[5].Set(0.0f, 0.5f * rad);

	hexagonShape.Set(vertices, count);

	DefFixture.shape = &hexagonShape;

	DefFixture.density = 1.0f;

	DefFixture.friction = fric;

	body->CreateFixture(&DefFixture);

	position = body->GetPosition();

	body->SetTransform(position, 0.0f);

	return body;
}


void Physics::Step()
{
	mWorld.Step(timeStep, velocityIterations, positionIterations);
}

void Physics::SetGravity(float x, float y)
{
	mGravity.Set(x, y);

	mWorld.SetGravity(mGravity);
}
