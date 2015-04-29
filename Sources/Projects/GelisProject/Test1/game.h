#ifndef GELI_THESIS_GAME_
#define GELI_THESIS_GAME_

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "player.h"
#include "physics.h"
#include <Box2D/Box2D.h>
#include "pause.h"
#include <SDL_image.h>
#include <cmath>

class Game
{
public:
	Game();

	void init();

	void events();

	void update();

	void render();

	void close();

	void run();

	SDL_Texture* loadTexture( std::string path );

protected:
	Pause pause;
	
	bool bPause;

	SDL_Renderer* m_gRenderer;
	SDL_Window* m_gWindow;
	Player player;
	SDL_Rect playerRect;
	SDL_Surface* playerSurf;
	SDL_Texture* playerTex;
    SDL_Texture* dynBoxTex;
    SDL_Texture* circleTex;
    SDL_Texture* firstTriangleTex;
    SDL_Texture* secondTriangleTex;
	SDL_Rect goalRect;

	b2Shape::Type ShapeType;
	b2PolygonShape* PolygonShape;
	b2Vec2 VertexVec;
	b2CircleShape* CircleShape;

	bool quit;
	bool jump;

	int ScreenWidth;
	int ScreenHeight;

	int scaling;

	SDL_Event e;

	b2Vec2 playerpos;
	b2Vec2 stonepos;
	b2Vec2 shape;

	float angle;

	Physics physics;

	bool force;
    bool rotating;
	b2Vec2 forceVec;

	float fric;

	float angRot = 0;
};

#endif
