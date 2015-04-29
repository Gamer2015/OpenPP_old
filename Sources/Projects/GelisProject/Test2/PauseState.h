#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <Objects/IScreen.hpp>
#include "Globals.h"
#include "../Core/Input.h"
#include <Objects/2D/SDL2/Text.hpp>

class PauseState : public Openpp::IScreen
{
    PauseState();
    PauseState(const PauseState&) = delete;
    void operator=(const PauseState&) = delete;

public:
    static PauseState& Get() { static PauseState state; return state; }


    void HandleInputs();

    void Update();

    void Render();

protected:
    void Leave() {}
    void Enter() {}

private:
    std::shared_ptr<SDL_Texture> mBackground;
    SDL::Text mText;
};

#endif // PAUSESTATE_H
