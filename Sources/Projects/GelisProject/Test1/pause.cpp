#include "pause.h"

Pause::Pause()
{
    x = 300,
    y = 100;
}

void Pause::init(SDL_Renderer* renderer, int ScreenWidth, int ScreenHeight)
{
    TTF_Init();

    TTF_Font* tolleFont = TTF_OpenFont("Sans.ttf", 100);

    SDL_Color white  = { 0, 255, 255};

    PauseSur = TTF_RenderText_Solid(tolleFont, "PAUSE", white);

    if(PauseSur == NULL)
		std::cout << "ERROR: " << TTF_GetError() << std::endl;
    
    PauseTex = SDL_CreateTextureFromSurface(renderer, PauseSur);

	if(PauseTex == NULL)
		std::cout << "Tex = NULL: " << SDL_GetError() << std::endl;

    FontRect.x = ScreenWidth / 2 - (x / 2);
    FontRect.y = ScreenHeight / 2 - (y / 2);
    FontRect.w = x;
    FontRect.h = y;
}


void Pause::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0x00, 0xFF );

    SDL_RenderCopyEx(renderer, PauseTex, NULL, &FontRect, 0, NULL, SDL_FLIP_NONE);

    //SDL_RenderFillRect( renderer, &FontRect );

	SDL_RenderPresent(renderer);
}
