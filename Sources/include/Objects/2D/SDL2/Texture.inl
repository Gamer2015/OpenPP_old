#include "Texture.hpp"

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

std::shared_ptr<SDL_Texture> Texture::Get(SDL_Surface* pSurface, SDL_Renderer* pRenderer)
{
	pLoadedSurface.reset( pSurface, SDL_FreeSurface );

	pTexture.reset( SDL_CreateTextureFromSurface (pRenderer, pLoadedSurface.get()), SDL_DestroyTexture );
	if( pTexture == nullptr )
	{
		throw Exceptions::ExSDLError( std::string("Unable to create texture from Surface"), SDL_GetError() );
	}

	return pTexture;
}

std::shared_ptr<SDL_Texture> Texture::Get(const std::string& rcPath, SDL_Renderer* pRenderer)
{
	pLoadedSurface.reset( IMG_Load(rcPath.c_str()), SDL_FreeSurface );
	if( pLoadedSurface == nullptr )
	{
		throw Exceptions::ExSDLError( std::string("Unable to Load Image " + rcPath), IMG_GetError() );
	}

	pTexture.reset( SDL_CreateTextureFromSurface (pRenderer, pLoadedSurface.get()), SDL_DestroyTexture );
	if( pTexture == nullptr )
	{
		throw Exceptions::ExSDLError( std::string("Unable to create texture from " + rcPath), SDL_GetError() );
	}

	return pTexture;
}

std::shared_ptr<SDL_Texture> Texture::GetText(const std::string& rcText, SDL_Renderer* pRenderer, const SDL_Color Color)
{
	pTexture.reset();

	if(rcText.length() == 0)
		return pTexture;

	pLoadedSurface.reset( TTF_RenderText_Solid(Texture::pFont.get(), rcText.c_str(), Color), SDL_FreeSurface );
	if( pLoadedSurface == nullptr )
	{
		throw Exceptions::ExSDLError( std::string("Unable to render text surface " + rcText), TTF_GetError() );
	}

	pTexture.reset( SDL_CreateTextureFromSurface (pRenderer, pLoadedSurface.get()), SDL_DestroyTexture );
	if( pTexture == nullptr )
	{
		throw Exceptions::ExSDLError( "Unable to create texture from from rendered text", SDL_GetError() );
	}

	return pTexture;
}

Vector2<int> Texture::GetSize(const std::string& Text)
{
	Vector2<int> Size;

	int x;
	int y;

	if( TTF_SizeText(pFont.get(), Text.c_str(), (&x), (&y)) != 0 )
	{
		throw Exceptions::ExSDLError( std::string("Unable to get Size of Text " + Text), TTF_GetError() );
	}

	Size.set(x, y);

	return Size;
}

void Texture::LoadFont(const std::string Path)
{
	pFont.reset( TTF_OpenFont( Path.c_str(), 128 ), TTF_CloseFont );
	if( pFont == nullptr )
	{
		throw Exceptions::ExSDLError( std::string("Unable to load Font " + Path), SDL_GetError() );
	}
}

std::shared_ptr< TTF_Font > Texture::pFont(nullptr);
std::shared_ptr< SDL_Surface > Texture::pLoadedSurface(nullptr);
std::shared_ptr< SDL_Texture > Texture::pTexture(nullptr);
SDL_Color Texture::Color = {0, 0, 0};

} // SDL2
} // Objects2D
} // Objects
} // Librepp
