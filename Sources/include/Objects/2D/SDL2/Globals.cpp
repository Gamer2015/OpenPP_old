#include "Globals.hpp"
#include "Texture.hpp"

namespace Openpp {
namespace Objects {
namespace SDL2 {

void Globals::Init(const std::string &_title, Vector2<int> _window, const std::string& _font, unsigned int _image_flags)
{
	/// Initialize SDL2
	SDL_Init(0);

	/// Initialize SDL2
	SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		throw ExSDLError( "SDL could not initialize", SDL_GetError() );
	}

	/// Initialize SDL_image
	if( !(IMG_Init(_image_flags) ))
	{
		throw ExSDLError( "SDL_image could not initialize", IMG_GetError() );
	}

	/// Initialize SDL_ttf
	if( TTF_Init() == -1 )
	{
		throw ExSDLError( "SDL_ttf could not initialize", TTF_GetError() );
	}


	pWindow = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _window.x, _window.y, SDL_WINDOW_SHOWN);
	if( pWindow == NULL )
	{
		throw ExSDLError( "Window could not be created", SDL_GetError() );
	}
	WindowIsOpen = true;

	pRenderer.reset(SDL_CreateRenderer( pWindow, -1, SDL_RENDERER_ACCELERATED ), SDL_DestroyRenderer);
	if( pRenderer == NULL )
	{
		throw ExSDLError( "Renderer could not be created", SDL_GetError() );
	}
	SDL_SetRenderDrawColor( pRenderer.get(), 0xFF, 0xFF, 0xFF, 0xFF );

	if(_font != "")
		Texture::SetFont(_font);
}
bool Globals::WindowIsOpen = false;

/// Global Renderer
SDL_Renderer* Globals::Renderer() { return pRenderer.get(); }

/// Current Screen
// Screen* Globals::gpCurrentScreen = NULL;

SDL_Window* Globals::pWindow = NULL;
std::shared_ptr<SDL_Renderer> Globals::pRenderer = NULL;

} // SDL2

} // Objects
} // Openpp
