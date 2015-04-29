#include "game.h"

Game::Game()
{
	bPause = false;

	bool madskills = true;

	scaling = 30;

	quit = false;
	jump = false;

	force = false;
	forceVec.x = 0;
	forceVec.y = 0;

	ScreenHeight = 720;
	ScreenWidth = 720;

	goalRect.w = 120;
	goalRect.h = 120;
	goalRect.x = 50;
	goalRect.y = 50;
}
SDL_Texture* Game::loadTexture( std::string path )
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

	newTexture = SDL_CreateTextureFromSurface( m_gRenderer, loadedSurface );

	SDL_FreeSurface( loadedSurface );

	return newTexture;
}

void Game::init()
{
	int flags = IMG_INIT_PNG;

	m_gWindow = SDL_CreateWindow("FreshGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	if(m_gWindow == NULL)
	{
		printf("An Error occured while trying to SDL_CreateWindow\n");
	}

	m_gRenderer = SDL_CreateRenderer(m_gWindow, -1, SDL_RENDERER_ACCELERATED);

	playerRect.w = player.m_width;
	playerRect.h = player.m_height;

	IMG_Init(flags);

	dynBoxTex = loadTexture( "box.png");
	playerTex = loadTexture( "player.png" );
	circleTex = loadTexture( "circle.png");
	firstTriangleTex = loadTexture( "firstTriangle.png");
	secondTriangleTex = loadTexture( "secondTriangle.png");

}

void Game::events()
{
	while(SDL_PollEvent(&e) != 0)
	{
		if( e.type == SDL_QUIT )
			quit = true;
		if (e.type == SDL_KEYDOWN)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_UP:
					forceVec.y += 100;
					break;

				case SDLK_DOWN:
					forceVec.y += -100;
					break;

				case SDLK_LEFT:
					forceVec.x += -100;
					break;
				case SDLK_RIGHT:
					forceVec.x += 100;
					break;
				case 'x':
					rotating = true;
					angRot = 6;
					break;
				case 'z':
					rotating = true;
					angRot = -6;
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				case 'w':
					physics.SetGravity(0.0f, 10.0f);
					break;
				case 's':
					physics.SetGravity(0.0f, -10.0f);
					break;
				case 'a':
					physics.SetGravity(-10.0f, 0.0f);
					break;
				case 'd':
					physics.SetGravity(10.0f, 0.0f);
					break;
				case 'p':
					bPause = !bPause;
					break;
			}
		}
		if (e.type == SDL_KEYUP)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_UP:
					forceVec.y = 0;
					break;

				case SDLK_DOWN:
					forceVec.y = 0;
					break;

				case SDLK_LEFT:
					forceVec.x = 0;
					break;

				case SDLK_RIGHT:
					forceVec.x = 0;
					break;
				case 'x':
					rotating = false;
					break;
				case 'z':
					rotating = false;
					break;
			}
		}
	}
}

void Game::update()
{
	physics.Step();
}
void Game::close()
{
	SDL_DestroyWindow( m_gWindow );
	m_gWindow = NULL;
	SDL_Quit();
}

void Game::render()
{	
	SDL_SetRenderDrawColor( m_gRenderer, 0x00, 0xFF, 0x00, 0xFF );
	SDL_RenderClear(m_gRenderer);

	SDL_SetRenderDrawColor( m_gRenderer, 0xFF, 0x00, 0x00, 0xFF );
	SDL_RenderFillRect( m_gRenderer, &goalRect );

	for(b2Body* loopbody = physics.mWorld.GetBodyList(); loopbody != NULL;  loopbody = loopbody->GetNext())
	{
		playerpos = loopbody->GetPosition();
		player.m_posX = playerpos.x * scaling;
		player.m_posY = ScreenHeight - playerpos.y * scaling;

		angle = -(180/3.141 * loopbody->GetAngle());

		playerRect.x = player.m_posX;
		playerRect.y = player.m_posY;


		for(b2Fixture* Fix = loopbody->GetFixtureList(); Fix != NULL ; Fix = Fix->GetNext())
		{
			ShapeType = Fix->GetType();

			if(ShapeType == b2Shape::e_polygon)
			{
				PolygonShape = (b2PolygonShape*)Fix->GetShape();
				if(PolygonShape->GetVertexCount() == 4)
				{
					VertexVec = PolygonShape->GetVertex(0);
					playerRect.w = abs(VertexVec.x * 2 * scaling);
					playerRect.h = abs(VertexVec.y * 2 * scaling);

					fric = Fix->GetFriction();
					if(loopbody->GetType() == b2_dynamicBody)
					{
						if(fric == 1.0)
							SDL_RenderCopyEx(m_gRenderer, playerTex, NULL, &playerRect, angle, NULL, SDL_FLIP_NONE);
						else if(fric < 0.95)
							SDL_RenderCopyEx(m_gRenderer, dynBoxTex, NULL, &playerRect, angle, NULL, SDL_FLIP_NONE);
					}
					else
						SDL_RenderCopyEx(m_gRenderer, dynBoxTex, NULL, &playerRect, angle, NULL, SDL_FLIP_NONE);
				}
			}
			else if(ShapeType == b2Shape::e_circle)
			{
				playerRect.w = 60;
				playerRect.h = 60;

				SDL_RenderCopyEx(m_gRenderer, circleTex, NULL, &playerRect, angle, NULL, SDL_FLIP_NONE);
			}
		}
	}
	SDL_RenderPresent(m_gRenderer);
}

void Game::run()
{
	init();
	TTF_Init();
	pause.init(m_gRenderer, ScreenWidth, ScreenHeight);


	b2Body* Floor = physics.CreateWorld(0.0, 1.0, 80.0, 1.0);
	b2Body* Sky = physics.CreateWorld(0.0, 25.0, 80.0, 1.0);
	b2Body* lbound = physics.CreateWorld(-1.0, 25.0, 1.0, 80.0);
	b2Body* rbound = physics.CreateWorld(23.0, 25.0, 1.0, 80.0);

	b2Body* Stone = physics.CreateWorld(16.8, 10.0, 1.0, 1.0);
	b2Body* Stone2 = physics.CreateWorld(12.8, 15.0, 1.0, 1.0);

	b2Body* enemybody = physics.CreateObjectBox(10, 10.0, 1.0, 1.0, 0.9);
	b2Body* playerbody = physics.CreateObjectBox(14.3, 20.0, 1.0, 1.0, 1.0);

	b2Body* circlebody = physics.CreateObjectCircle(8.0, 8.0, 1.0, 1.0);

	Uint32 time = 0;

	while( !quit)
	{
		if(!bPause)
		{
			time = SDL_GetTicks();

			if(forceVec.x > 100)
				forceVec.x = 100;
			if(forceVec.x < -100)
				forceVec.x = -100;

			if(forceVec.y > 100)
				forceVec.y = 100;
			if(forceVec.y < -100)
				forceVec.y = -100;

			if(rotating)
			{
				if(playerbody->GetAngularVelocity() < 6 && playerbody->GetAngularVelocity() > -6)
					playerbody->ApplyAngularImpulse(angRot, true);
			}

			playerbody->SetAngularVelocity(playerbody->GetAngularVelocity() * 0.995);


			playerbody->ApplyForce( forceVec, playerbody->GetWorldCenter(), true );

			events();
			update();
			render();

			if((abs((((b2PolygonShape*)(enemybody->GetFixtureList()->GetShape()))->GetVertex(0)).x) + enemybody->GetPosition().x) * scaling <= 170)
			{
				if((abs((((b2PolygonShape*)(enemybody->GetFixtureList()->GetShape()))->GetVertex(0)).y) + enemybody->GetPosition().y) * scaling >= 550)
				{
					printf("You won!");
				}
			}

			while(SDL_GetTicks() - time < 100/6){}
		}

		else
		{
			events();
			pause.render(m_gRenderer);
		}
	}
	close();
}
