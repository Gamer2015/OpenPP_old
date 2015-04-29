#include "Game.h"

#include <SDL.h>
#include "Globals.h"
#include "../Core/Input.h"

#include "GameState.h"

namespace SDL = Openpp::Objects::SDL2;

void Game::Init()
{
	SDL::Globals::Init(Globals::Title, Globals::Window, "Sans.ttf");
}

void Game::Run()
{
	Globals::gpCurrentScreen = GameState::Get();

	while( SDL::Globals::WindowIsOpen )
	{
		unsigned int Time(SDL_GetTicks());

		Input::Read();
		Globals::gpCurrentScreen->HandleInputs();

		Globals::gpCurrentScreen->Update();

		SDL_RenderClear( SDL::Globals::Renderer() );
		Globals::gpCurrentScreen->Render();
		SDL_RenderPresent( SDL::Globals::Renderer() );

		if(SDL_GetTicks() - Time < 1000.0/Globals::FPS)
			SDL_Delay(1000.0/Globals::FPS - (SDL_GetTicks() - Time));
	}
}
