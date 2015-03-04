#include "Globals.hpp"

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

void Globals::Init(const std::string &rTitle, int Width, int Height)
{
	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		throw Exceptions::ExSDLError( "SDL could not initialize", SDL_GetError() );
	}

	pWindow = SDL_CreateWindow(rTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
	if( pWindow == NULL )
	{
		throw Exceptions::ExSDLError( "Window could not be created", SDL_GetError() );
	}
	WindowIsOpen = true;

	pRenderer.reset(SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED ), SDL_DestroyRenderer);
	if( pRenderer == NULL )
	{
		throw Exceptions::ExSDLError( "Renderer could not be created", SDL_GetError() );
	}
	SDL_SetRenderDrawColor( pRenderer.get(), 0xFF, 0xFF, 0xFF, 0xFF );
}
bool Globals::WindowIsOpen = false;

/// Global Renderer
SDL_Renderer* Globals::Renderer() { return pRenderer.get(); }

/// Current Screen
Screen* Globals::gpCurrentScreen = NULL;

SDL_Window* Globals::pWindow = NULL;
std::shared_ptr<SDL_Renderer> Globals::pRenderer = NULL;

} // SDL2
} // Objects2D
} // Objects
} // Openpp
