#include "Texture.hpp"

namespace Openpp {
namespace Objects {
namespace SDL2 {

Texture::Info Texture::Get(SDL_Surface* pSurface, SDL_Renderer* pRenderer)
{
    Info info;
    info.texture.reset( SDL_CreateTextureFromSurface (pRenderer, pSurface), SDL_DestroyTexture );
    if( info.texture == nullptr )	{
		throw ExSDLError( std::string("Unable to create texture from Surface"), SDL_GetError() );
	}
    int w, h;
    if( SDL_QueryTexture(info.texture.get(), NULL, NULL, &w, &h)) {
		throw ExSDLError( std::string("Unable to Query Texture"), SDL_GetError() );
    }
    info.size.x = w;
    info.size.y = h;

    return info;
}

Texture::Info Texture::Get(const std::string& rcPath, SDL_Renderer* pRenderer)
{
    std::shared_ptr<SDL_Surface> pLoadedSurface( IMG_Load(rcPath.c_str()), SDL_FreeSurface );
	if( pLoadedSurface == nullptr )
	{
		throw ExSDLError( std::string("Unable to Load Image " + rcPath), IMG_GetError() );
	}

    Info info;
    info.texture.reset( SDL_CreateTextureFromSurface (pRenderer, pLoadedSurface.get()), SDL_DestroyTexture );
    if( info.texture == nullptr )
	{
		throw ExSDLError( std::string("Unable to create texture from " + rcPath), SDL_GetError() );
	}

    int w, h;
    if( SDL_QueryTexture(info.texture.get(), NULL, NULL, &w, &h)) {
		throw ExSDLError( std::string("Unable to Query Texture"), SDL_GetError() );
    }
    info.size.x = w;
    info.size.y = h;

    return info;
}

Texture::Info Texture::GetText(const std::string& rcText, int _height, SDL_Renderer* pRenderer, const SDL_Color Color)
{
    text_height = _height;
    pFont.reset( TTF_OpenFont( strFont.c_str(), text_height ), TTF_CloseFont );
    if( pFont == nullptr )
    {
		throw ExSDLError( std::string("Unable to load Font " + strFont), SDL_GetError() );
    }

	if(rcText.length() == 0)
        return Texture::Info();

    std::shared_ptr< SDL_Surface > pLoadedSurface( TTF_RenderText_Solid(Texture::pFont.get(), rcText.c_str(), Color), SDL_FreeSurface );
	if( pLoadedSurface == nullptr )
	{
		throw ExSDLError( std::string("Unable to render text surface " + rcText), TTF_GetError() );
	}

    Texture::Info info;
    info.texture.reset( SDL_CreateTextureFromSurface (pRenderer, pLoadedSurface.get()), SDL_DestroyTexture );
    if( info.texture == nullptr )
	{
		throw ExSDLError( "Unable to create texture from from rendered text", SDL_GetError() );
	}
    int w, h;
    if( TTF_SizeText(pFont.get(), rcText.c_str(), &w, &h) != 0 )
    {
		throw ExSDLError( std::string("Unable to get Size of Text " + rcText), TTF_GetError() );
    }
    info.size.x = w;
    info.size.y = h;


    return info;
}

void Texture::SetFont(const std::string& Path)
{
    strFont = Path;
}

std::string Texture::strFont;
std::shared_ptr< TTF_Font > Texture::pFont(nullptr);
int Texture::text_height(32);
SDL_Color Texture::Color = {0, 0, 0};

} // SDL2

} // Objects
} // Openpp
