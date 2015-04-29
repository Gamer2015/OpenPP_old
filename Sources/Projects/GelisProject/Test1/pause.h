#ifndef GELI_THESIS_PAUSE
#define GELI_THESIS_PAUSE

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

class Pause
{
public:
	Pause();
        
    void init(SDL_Renderer* renderer, int ScreenWidth, int ScreenHeight);

    void render(SDL_Renderer* renderer);
    
protected:
	SDL_Surface* PauseSur;
	SDL_Texture* PauseTex;
	SDL_Rect FontRect;
	int x, y;
};

#endif
