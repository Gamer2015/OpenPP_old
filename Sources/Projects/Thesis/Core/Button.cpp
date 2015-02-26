#include "Button.h"
#include "Texture.h"

namespace Core
{
    Button::Button()
    {
    }

    void Button::SetFunction(const FunctionPointer Function)
    {
        mFunction = Function;
    }
    FunctionPointer Button::GetFunction() const
    {
        return mFunction;
    }
    void Button::CallFunction() const
    {
        if(mFunction != NULL)
            mFunction();
    }

    template <>
    void Button::AddTexture<SDL_Texture>(const std::shared_ptr<SDL_Texture> Texture)
    {
        mpTextures.push_back(Texture);
    }
    void Button::AddTexture(const std::string Path)
    {
        mpTextures.push_back(Core::Texture::LoadFromFile(Path));
    }

    template <>
    void Button::SetTexture<SDL_Texture>(const std::shared_ptr<SDL_Texture> Texture, int Index)
    {
        if(Index >= mpTextures.size())
        {
            mpTextures.resize(Index + 1, std::shared_ptr<SDL_Texture>(nullptr));
        }

        mpTextures[Index] = Texture;
    }
    void Button::SetTexture(std::string const Path, int Index)
    {
        if(Index >= mpTextures.size())
        {
            mpTextures.resize(Index + 1, std::shared_ptr<SDL_Texture>(nullptr));
        }

        mpTextures[Index] = Core::Texture::LoadFromFile(Path);
    }

    std::shared_ptr<SDL_Texture> const& Button::GetTexture(int Index) const
    {
        return mpTextures[Index];
    }
    int Button::GetTextureCount() const
    {
        return mpTextures.size();
    }

    void Button::SetPosition(float X, float Y)
    {
        SDL_Rectangle::SetPosition(X, Y);
        Text::SetPosition(X, Y);

        CalcRenderRect();
    }
    void Button::Move(float X, float Y)
    {
        SDL_Rectangle::Move(X, Y);
        Text::Move(X, Y);

        CalcRenderRect();
    }
    Vector2f const& Button::GetPosition() const
    {
        SDL_Rectangle::GetPosition();
    }

    bool Button::PointIsInside(float X, float Y) const
    {
        if(X < GetPosition().x - GetOrigin().x)
            return false;
        if(X > GetPosition().x - GetOrigin().x + GetSize().x)
            return false;

        if(Y < GetPosition().y - GetOrigin().y)
            return false;
        if(Y > GetPosition().y - GetOrigin().y + GetSize().y)
            return false;

        return true;
    }

    void Button::Render(int Index) const
    {
        if(mpTextures[Index] != NULL)
            SDL_RenderCopy(CG::gpRenderer, mpTextures[Index].get(), NULL, &SDL_Rectangle::GetRenderRect());

        Text::Render();
    }
    void Button::Render(float OffsetX, float OffsetY, int Index) const
    {
        mDummyRect.w = SDL_Rectangle::GetRenderRect().w;
        mDummyRect.h = SDL_Rectangle::GetRenderRect().h;
        mDummyRect.x = SDL_Rectangle::GetRenderRect().x + OffsetX;
        mDummyRect.y = SDL_Rectangle::GetRenderRect().y + OffsetY;

        if(mpTextures[Index] != NULL)
           SDL_RenderCopy(CG::gpRenderer, mpTextures[Index].get(), NULL, &mDummyRect);

        Text::Render(OffsetX, OffsetY);
    }

    void Button::CalcRenderRect()
    {
        SDL_Rectangle::CalcRenderRect();
        CalcTextRenderRect();
    }
    void Button::CalcTextRenderRect()
    {
        Text::CalcTextRenderRect();
        mTextRect.x = GetRenderRect().x + GetSize().x / 2.0 *(GetTextOrigin().x + 1) - GetTextSize().x / 2.0 * (GetTextOrigin().x + 1);
        mTextRect.y = GetRenderRect().y + GetSize().y / 2.0 *(GetTextOrigin().y + 1) - GetTextSize().y / 2.0 * (GetTextOrigin().y + 1);
    }
}
