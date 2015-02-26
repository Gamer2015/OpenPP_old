#include "SDL_Rectangle.h"

namespace Core
{
    void SDL_Rectangle::SetPosition(float X, float Y)
    {
        FRectangle::SetPosition(X, Y);

        CalcRenderRect();
    }
    void SDL_Rectangle::Move(float X, float Y)
    {
        FRectangle::Move(X, Y);

        CalcRenderRect();
    }
    void SDL_Rectangle::SetSize(float X, float Y)
    {
        FRectangle::SetSize(X, Y);

        CalcRenderRect();
    }
    void SDL_Rectangle::SetOrigin(float X, float Y)
    {
        FRectangle::SetOrigin(X, Y);

        CalcRenderRect();
    }

    SDL_Rect const& SDL_Rectangle::GetRenderRect() const
    {
        return mRenderRect;
    }

    void SDL_Rectangle::CalcRenderRect()
    {
        mRenderRect.w = GetSize().x;
        mRenderRect.h = GetSize().y;

        mRenderRect.x = GetPosition().x - ceil(GetSize().x / 2.0 * (GetOrigin().x + 1));
        mRenderRect.y = GetPosition().y - ceil(GetSize().y / 2.0 * (GetOrigin().y + 1));
    }
}
