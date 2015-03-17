#ifndef OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_EDITOR_HPP_
#define OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_EDITOR_HPP_

#include <Objects/2D/SDL2/Globals.hpp>
#include "../Globals.hpp"
#include "EditorGui.hpp"

class Editor
{
public:
	/// Programm Logic
	void run()
	{
		unsigned int Time;

		while( SDL::Globals::WindowIsOpen )
		{
			Time = SDL_GetTicks();

			_mGui->HandleInputs();

			_mGui->Update();

			SDL_RenderClear( SDL::Globals::Renderer() );
			_mGui->Render();
			SDL_RenderPresent( SDL::Globals::Renderer() );

			while(SDL_GetTicks() - Time < 1000.0/Globals::FPS());
		}
	}

private:
	EditorGui _mGui;
};

#endif // OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_EDITOR_HPP_
