#include "World.h"
#include "Globals.h"
#include <Objects/2D/SDL2/Texture.hpp>

World::World() :
	textures {
	{"box", SDL::Texture::Get("box.png").texture},
	{"player", SDL::Texture::Get("player.png").texture},
	{"circle", SDL::Texture::Get("circle.png").texture},
	{"tri1", SDL::Texture::Get("firstTriangle.png").texture},
	{"tri2", SDL::Texture::Get("firstTriangle.png").texture} },
	mWorld(b2Vec2(0,-9.81))
{
	mWorld.SetAllowSleeping(false);
}

void World::Step()
{
	mWorld.Step( 1.0/Globals::FPS, 8, 3);
}
void World::SetGravity(float x, float y)
{
	static b2Vec2 gravity;
	gravity.Set(x, y);

	mWorld.SetGravity(gravity);
}

b2Body* World::CreateBox(float posx, float posy, float sizex, float sizey, float fric)
{
	b2BodyDef DefBody;
	DefBody.position.Set(posx, posy);
	if(fric >= 0) DefBody.type = b2_dynamicBody;
	b2Body* body = mWorld.CreateBody(&DefBody);

	b2PolygonShape shape;
	shape.SetAsBox(sizex, sizey);


	if(fric >= 0)
	{
		b2FixtureDef DefFixture;
		DefFixture.shape = &shape;
		DefFixture.density = 1.0f;
		DefFixture.friction = fric;

		body->CreateFixture(&DefFixture);
	}
	else
		body->CreateFixture(&shape, 0.0f);

	return body;
}
b2Body* World::CreateCircle(float posx, float posy, float radius, float fric)
{
	b2BodyDef DefBody;
	DefBody.position.Set(posx, posy);
	if(fric >= 0) DefBody.type = b2_dynamicBody;
	b2Body* body = mWorld.CreateBody(&DefBody);

	b2CircleShape shape;
	shape.m_p.Set(0.0f, 0.0f);
	shape.m_radius = radius;


	if(fric >= 0)
	{
		b2FixtureDef DefFixture;
		DefFixture.shape = &shape;
		DefFixture.density = 1.0f;
		DefFixture.friction = fric;

		body->CreateFixture(&DefFixture);
	}
	else
		body->CreateFixture(&shape, 0.0f);

	return body;
}

void World::Render()
{
	for(b2Body* loopbody = mWorld.GetBodyList(); loopbody != NULL; loopbody = loopbody->GetNext())
	{
		b2Vec2 pos = loopbody->GetPosition();
		pos.x = pos.x * Globals::Scaling;
		pos.y = Globals::Window.y - pos.y * Globals::Scaling;

		float angle = -(180/3.141 * loopbody->GetAngle());

		SDL_Rect rect;
		rect.x = pos.x;
		rect.y = pos.y;


		for(b2Fixture* Fix = loopbody->GetFixtureList(); Fix != NULL ; Fix = Fix->GetNext())
		{
			b2Shape::Type ShapeType = Fix->GetType();

			if(ShapeType == b2Shape::e_polygon)
			{
				b2PolygonShape* polygon = (b2PolygonShape*)Fix->GetShape();
				if(polygon->GetVertexCount() == 4)
				{
					b2Vec2 Vertex = polygon->GetVertex(0);
					rect.w = abs(Vertex.x * 2 * Globals::Scaling);
					rect.h = abs(Vertex.y * 2 * Globals::Scaling);

					float fric = Fix->GetFriction();
					if(loopbody->GetType() == b2_dynamicBody)
					{
						if(fric > 0.95)
							SDL_RenderCopyEx(SDL::Globals::Renderer(), textures["player"].get(), NULL, &rect, angle, NULL, SDL_FLIP_NONE);
						else
							SDL_RenderCopyEx(SDL::Globals::Renderer(), textures["box"].get(), NULL, &rect, angle, NULL, SDL_FLIP_NONE);
					}
					else
						SDL_RenderCopyEx(SDL::Globals::Renderer(), textures["box"].get(), NULL, &rect, angle, NULL, SDL_FLIP_NONE);
				}
			}
			else if(ShapeType == b2Shape::e_circle)
			{
				b2CircleShape* shape = (b2CircleShape*)Fix->GetShape();

				float diameter = 2 * Globals::Scaling * shape->m_radius;
				rect.w = diameter;
				rect.h = diameter;

				SDL_RenderCopyEx(SDL::Globals::Renderer(), textures["circle"].get(), NULL, &rect, angle, NULL, SDL_FLIP_NONE);
			}
		}
	}
}
