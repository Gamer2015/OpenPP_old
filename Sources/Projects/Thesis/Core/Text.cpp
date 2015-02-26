#include "Text.h"

typedef Core::Globals CG;

namespace Core
{

    void Text::SetText(const std::string Text)
    {
        mText = Text;
        mpTextTexture = Core::Texture::LoadText(Text);
        mTextSize = Core::Texture::GetTextSize(Text);

        CalcTextRenderRect();
    }
    std::string const& Text::GetText() const
    {
        return mText;
    }
    void Text::SetTextHeight(float y)
    {
        mTextHeight = y;

        CalcTextRenderRect();
    }
    Vector2i const& Text::GetTextSize() const
    {
        return mTextSize;
    }
    SDL_Rect const& Text::GetTextRect() const
    {
        return mTextRect;
    }

    void Text::SetTextOrigin(float x, float y)
    {
        mTextOrigin.x = x;
        mTextOrigin.y = y;

        CalcTextRenderRect();
    }

    Vector2f const& Text::GetTextOrigin() const
    {
        return mTextOrigin;
    }

    void Text::SetPosition(float X, float Y)
    {
        mPosition.Set(X, Y);

        CalcTextRenderRect();
    }
    void Text::Move(float X, float Y)
    {
        mPosition.Add(X, Y);

        CalcTextRenderRect();
    }
    Vector2f const& Text::GetPosition() const
    {
        return mPosition;
    }

    void Text::Render() const
    {
        if(GetTextTexture() != NULL)
            SDL_RenderCopy( CG::GetRenderer(), GetTextTexture().get(), NULL, &GetTextRect());
    }
    void Text::Render(float OffsetX, float OffsetY) const
    {
        mDummyRect.x = GetTextRect().x + OffsetX;
        mDummyRect.y = GetTextRect().y + OffsetY;

        if(GetTextTexture() != NULL)
            SDL_RenderCopy(CG::GetRenderer(), GetTextTexture().get(), NULL, &mDummyRect);
    }

    std::shared_ptr< SDL_Texture > const& Text::GetTextTexture() const
    {
        return mpTextTexture;
    }

    void Text::CalcTextRenderRect()
    {
        if(GetTextSize().y != 0 && mTextHeight != 0)
            mTextSize.Set( GetTextSize().x * mTextHeight / GetTextSize().y, mTextHeight);

        mTextRect.w = mTextSize.x;
        mTextRect.h = mTextSize.y;

        mTextRect.x = GetPosition().x - ceil(mTextSize.x / 2.0 * (GetTextOrigin().x + 1));
        mTextRect.y = GetPosition().y - ceil(mTextSize.y / 2.0 * (GetTextOrigin().y + 1));
    }
}
