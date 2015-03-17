#ifndef OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_SCREENS_START_SCREEN_HPP_
#define OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_SCREENS_START_SCREEN_HPP_

#include <Objects/2D/SDL2/AScreen.hpp>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Button.hpp>
#include <iostream>
#include "../../Globals.hpp"

namespace OO = Openpp::Objects;
namespace O2D = OO::Objects2D;
namespace SDL = O2D::SDL2;

class StartScreen : public SDL::AScreen
{
public:
	/// Create StartScreen
	StartScreen();

	/// Initializes StartScreen
	void Initialize();

	/// Handle inputs of Screen
	virtual void HandleInputs(const SDL_Event& event);

	/// Update screen
	virtual void Update();

	/// Render screen
	virtual void Render();

protected:
	/// Called when leaving the Screen
	virtual void Leave();

	/// Called when entering the Screen
	virtual void Enter();

private:
	enum Buttons{ BUTTON_START, BUTTON_LOAD, BUTTON_OPTIONS, BUTTON_QUIT, BUTTON_COUNT };
	SDL::Button _mButtons[BUTTON_COUNT];

	O2D::Vector2<int> _mMouse;
};

#endif // OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_SCREENS_START_SCREEN_HPP_
