#include "Game/Init.h"
#include <Objects/2D/SDL2/Text.hpp>
#include <Objects/2D/SDL2/Sprite.hpp>
#include <Objects/2D/SDL2/Button.hpp>
#include <Objects/2D/SDL2/Globals.hpp>

#include <iostream>

namespace OO = Openpp::Objects;
namespace SDL = OO::SDL2;

int main(int argc, char* argv[])
{
    Game::Init::Init();

    SDL::Sprite<int> sprite1;
    sprite1.set("Red.png");
    sprite1.position.set(50, 50);
    sprite1.origin.set(1, 1);
    sprite1.size.set(50, 50);

    SDL::Sprite<int> sprite2;
    sprite2.set("Red.png");
    sprite2.position.set(50, 50);
    sprite2.origin.set(0, 0);
    sprite2.size.set(50, 50);

    SDL::Text text1;
    text1.origin.set(-1, -1);
    text1.height = 32;
    text1.set("Hello1");
    text1.position.set(50, 50);

    SDL::Text text2;
    text2.origin.set(0, 0);
    text2.height = 32;
    text2.set("Hello2");
    text2.position.set(50, 50);

    SDL::Text text3;
    text3.origin.set(1, 1);
    text3.height = 32;
    text3.set("Hello3");
    text3.position.set(50, 50);

    SDL::Button button;
	button.textures[0].set("Red.png");
	button.textures[1].set("green.png");
	button.origin.set(0, 0);
	button.size.set(200, 100);

    button.text.height.set(64);
	button.text.set("Hallo2");
    button.text.origin.set(-1, -1);
    button.position.set(GG::Window);

    OO::Vector2<int> mouse;

	int Time;
	int i = 0;
	int textureNumber = 0;

	while( SDL::Globals::WindowIsOpen )
	{
		Time = SDL_GetTicks();

		SDL_Event event;
		while(SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
			{
				SDL::Globals::WindowIsOpen = false;
			}

			if(event.type == SDL_MOUSEMOTION)
			{
				mouse.set(event.motion.x, event.motion.y);
			}
		}

		SDL_RenderClear( SDL::Globals::Renderer() );

		if(button.isInside(mouse.x, mouse.y))
			textureNumber = 1;
		else
			textureNumber = 0;

        button.Render(textureNumber);
        sprite1.Render();
        text1.Render();
        sprite2.Render();
        text2.Render();

		button.angle += 0.05;

		SDL_RenderPresent( SDL::Globals::Renderer() );

		while(SDL_GetTicks() - Time < 1000.0/60);
	}

	return 0;
}
