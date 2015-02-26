#include "Sprite.h"

typedef Core::Globals CG;

#define RAD_GRAD 57.295779513082320876798154814105

namespace Core
{
    template <>
    void Sprite::SetTexture<SDL_Texture>(const std::shared_ptr<SDL_Texture> Texture)
    {
        mTexture = Texture;
    }
    void Sprite::SetTexture(std::string const Path)
    {
        mTexture = Core::Texture::LoadFromFile(Path);
    }

    void Sprite::Render() const
    {
        static SDL_Point Point;
        Point.x = ceil(GetSize().x / 2.0 * (GetOrigin().x + 1));
        Point.y = ceil(GetSize().y / 2.0 * (GetOrigin().y + 1));

        SDL_RenderCopyEx( CG::GetRenderer(), mTexture.get(), NULL, &GetRenderRect(), GetAngle() * RAD_GRAD, &Point, SDL_FLIP_NONE);
    }
}
