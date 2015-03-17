#include "StartScreen.hpp"

/// Initializes StartScreen
StartScreen::StartScreen() :
	AScreen(),
	_mMouse()
{
}

void StartScreen::Initialize()
{
	for(int i = 0; i < BUTTON_COUNT; ++i)
	{
		_mButtons[i].textures[Globals::BUTTON_DEFAULT].set(Globals::pButtonTextures[Globals::BUTTON_DEFAULT]);
		_mButtons[i].textures[Globals::BUTTON_HOVER].set(Globals::pButtonTextures[Globals::BUTTON_HOVER]);

		_mButtons[i].origin.set(0, -1);
		_mButtons[i].size.set(400, 80);
		_mButtons[i].position.set( Globals::Window().x / 2, 0.1 * Globals::Window().y + i * 100);

		_mButtons[i].text.height = 32;
	}

	_mButtons[BUTTON_START].text.set("Start");
	_mButtons[BUTTON_LOAD].text.set("Load");
	_mButtons[BUTTON_OPTIONS].text.set("Options");
	_mButtons[BUTTON_QUIT].text.set("Quit");

	_mBackground = Globals::pBackground.get();
}

/// Handle inputs of Screen
void StartScreen::HandleInputs(const SDL_Event& event)
{
	SDL::Globals::WindowIsOpen = !(event.type == SDL_QUIT);

	switch(event.type)
	{
		case SDL_MOUSEMOTION: _mMouse.set(event.motion.x, event.motion.y);
			break;

		default:
			break;
	}
}

/// Update screen
void StartScreen::Update() {std::cout << "Update StartScreen" << std::endl;}

/// Render screen
void StartScreen::Render()
{
	SDL_RenderCopy(SDL::Globals::Renderer(), _mBackground, NULL, NULL);

	for(int i = 0; i < BUTTON_COUNT; ++i)
	{
		if(_mButtons[i].PointIsInside(_mMouse.x, _mMouse.y))
			_mButtons[i].Render(Globals::BUTTON_HOVER);
		else
			_mButtons[i].Render(Globals::BUTTON_DEFAULT);
	}
}

///// protected:
/// Called when leaving the Screen
void StartScreen::Leave() {std::cout << "Leave StartScreen" << std::endl;}

/// Called when entering the Screen
void StartScreen::Enter() {std::cout << "Enter StartScreen" << std::endl;}
