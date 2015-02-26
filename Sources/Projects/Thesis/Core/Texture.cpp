#include "Texture.h"

namespace CE = Core::Exceptions;
typedef Core::Texture CT;

namespace Core
{
    std::shared_ptr< TTF_Font > CT::pFont(nullptr);
    std::shared_ptr< SDL_Surface > CT::pLoadedSurface(nullptr);
    std::shared_ptr< SDL_Texture > CT::pTexture(nullptr);
    SDL_Color CT::Color = {0, 0, 0};

    std::shared_ptr<SDL_Texture> CT::LoadFromSurface(SDL_Surface* pSurface, SDL_Renderer* pRenderer)
    {
        pLoadedSurface.reset( pSurface, SDL_FreeSurface );

        pTexture.reset( SDL_CreateTextureFromSurface (pRenderer, pLoadedSurface.get()), SDL_DestroyTexture );
        if( pTexture == NULL )
        {
            throw CE::ExSDLError( std::string("Unable to create texture from Surface"), SDL_GetError() );
        }

        return pTexture;
    }

    std::shared_ptr<SDL_Texture> CT::LoadFromFile(const std::string Path, SDL_Renderer* pRenderer)
    {
        pLoadedSurface.reset( IMG_Load(Path.c_str()), SDL_FreeSurface );
        if( pLoadedSurface == NULL )
        {
            throw CE::ExSDLError( std::string("Unable to Load Image " + Path), IMG_GetError() );
        }

        pTexture.reset( SDL_CreateTextureFromSurface (pRenderer, pLoadedSurface.get()), SDL_DestroyTexture );
        if( pTexture == NULL )
        {
            throw CE::ExSDLError( std::string("Unable to create texture from " + Path), SDL_GetError() );
        }

        return pTexture;
    }

    std::shared_ptr<SDL_Texture> CT::LoadText(const std::string Text, const SDL_Color Color, SDL_Renderer* pRenderer)
    {
        pLoadedSurface.reset( TTF_RenderText_Solid(CT::pFont.get(), Text.c_str(), Color), SDL_FreeSurface );
        if( pLoadedSurface == NULL )
        {
            throw CE::ExSDLError( std::string("Unable to render text surface " + Text), TTF_GetError() );
        }

        pTexture.reset( SDL_CreateTextureFromSurface (pRenderer, pLoadedSurface.get()), SDL_DestroyTexture );
        if( pTexture == NULL )
        {
            throw CE::ExSDLError( "Unable to create texture from from rendered text", SDL_GetError() );
        }

        return pTexture;
    }

    Vector2<int> CT::GetTextSize(std::string Text)
    {
        static Vector2<int> Size;

        //if( TTF_SizeText(pFont.get(), Text.c_str(), (int*), (int*)) != 0 )
        if( TTF_SizeText(pFont.get(), Text.c_str(), (&Size.x), (&Size.y)) != 0 )
        {
            throw CE::ExSDLError( std::string("Unable to get Size of Text " + Text), TTF_GetError() );
        }

        return Size;
    }

    void CT::LoadTextFont(const std::string Path)
    {
        pFont.reset( TTF_OpenFont( Path.c_str(), 128 ), TTF_CloseFont );
        if( pFont == NULL )
        {
            throw CE::ExSDLError( std::string("Unable to load Font " + Path), SDL_GetError() );
        }
    }
}
