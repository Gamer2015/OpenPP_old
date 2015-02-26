#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* loadFromFile(const std::string& Path, SDL_Renderer* pRenderer)
{
	// don't care bout error checking now
	SDL_Surface* tempSurface = IMG_Load(Path.c_str());

	return SDL_CreateTextureFromSurface(pRenderer, tempSurface);
}

template <typename T>
class Vector2
{
public:
	T x;
	T y;
};

class Player
{
public:
	Player( SDL_Renderer* pRenderer ) { mpRenderer = pRenderer; }

	void SetTexture(const std::string& Path) { mpTexture = loadFromFile(Path, mpRenderer); }

	void Render() { SDL_RenderCopy(mpRenderer, mpTexture, NULL, &GetRenderRect()); }

	Vector2<float> Pos;
	Vector2<float> Size;

private:
	const SDL_Rect& GetRenderRect()
	{
		mRenderRect.x = Pos.x;
		mRenderRect.y = Pos.y;
		mRenderRect.w = Size.x;
		mRenderRect.h = Size.y;
		return mRenderRect;
	}

	SDL_Renderer* mpRenderer;
	SDL_Texture* mpTexture;
	SDL_Rect mRenderRect;
};

int main(int argc, char* argv[])
{
	std::cout << "Test 1" << std::endl;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* pWindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	SDL_Renderer *pRenderer = SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED );
	SDL_SetRenderDrawColor( pRenderer, 0xFF, 0x00, 0x00, 0xFF );

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	char Buttons = 0;
	enum { BUTTON_RIGHT = 0x01, BUTTON_LEFT = 0x02 };

	Player player(pRenderer);
	player.SetTexture("white.png");
	player.Pos.x = 50;
	player.Pos.y = 50;
	player.Size.x = 50;
	player.Size.y = 50;

	std::cout << "Test 1" << std::endl;

	float Velocity = 50 * 1.0/60;

	SDL_Event Event;

	int Time = SDL_GetTicks();

	bool quit = false;
	while(!quit)
	{
		while(SDL_PollEvent(&Event) != 0)
		{
			if(Event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (Event.type == SDL_KEYDOWN)
			{
				switch(Event.key.keysym.sym)
				{
					case SDLK_a: Buttons |= (BUTTON_LEFT);
						break;
					case SDLK_d: Buttons |= (BUTTON_RIGHT);
						break;

					default:
						break;
				}
			}
			else if(Event.type == SDL_KEYUP)
			{
				switch(Event.key.keysym.sym)
				{
					case SDLK_a: Buttons &= ~(BUTTON_LEFT);
						break;
					case SDLK_d: Buttons &= ~(BUTTON_RIGHT);
						break;

					default:
						break;
				}
			}
		}

		if(Buttons & BUTTON_RIGHT)
		{
			player.Pos.x += Velocity;
		}
		if(Buttons & BUTTON_LEFT)
		{
			player.Pos.x -= Velocity;
		}

		SDL_RenderClear( pRenderer );

		player.Render();

		SDL_RenderPresent( pRenderer );
		while(SDL_GetTicks() - Time < 1000.0/60);
		Time = SDL_GetTicks();
	}


	return 0;
}
