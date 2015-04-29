#include "PauseState.h"
#include "GameState.h"
#include "Globals.h"

PauseState::PauseState() :
	mBackground(SDL::Texture::Get("Red.png").texture)
{
	mText.position.set(Globals::Window.x / 2, Globals::Window.y / 2);
	mText.height = 64;
	mText.set("Pause");
}

void PauseState::HandleInputs()
{
	if(Input::KeyDown(Input::BUTTON_START))
	Globals::gpCurrentScreen = GameState::Get();
}

void PauseState::Update()
{
}

void PauseState::Render()
{
	SDL_RenderCopy(SDL::Globals::Renderer(), mBackground.get(), NULL, NULL);
	mText.Render();
}
