#ifndef WORLD_H
#define WORLD_H

#include <Box2D/Box2D.h>

#include <SDL.h>
#include <map>
#include <string>

class World
{
	World();
	World(const World&) = delete;
	void operator=(const World&) = delete;

public:
	static World& Get() { static World world; return world; }


	void Step();

	void SetGravity(float x, float y);

	b2Body* CreateBox(float posx, float posy, float sizex, float sizey, float fric=-1);
	b2Body* CreateCircle(float posx, float posy, float radius, float fric=-1);

	void Render();

private:
	b2World mWorld;
	int Scaling;
	std::map<std::string, std::shared_ptr<SDL_Texture> > textures;
};

#endif // WORLD_H
