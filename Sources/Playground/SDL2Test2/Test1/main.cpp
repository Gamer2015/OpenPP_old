#include "Game/Init.h"
#include <Objects/2D/SDL2/Text.hpp>
#include <Objects/2D/SDL2/Sprite.tpp>
#include <Objects/2D/SDL2/Button.hpp>
#include <Objects/2D/SDL2/Globals.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Renderer* pRenderer;

	SDL_Window* pWindow = SDL_CreateWindow("Hello World",
										   50,
										   50,
										   640,
										   480,
										   0);

	bool quit = false;
	while( !quit )
	{

		SDL_Event event;
		while(SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}

			if(event.type == SDL_MOUSEMOTION)
			{
			}
		}
	}

	return 0;
}
