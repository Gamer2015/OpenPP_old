#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <Objects/IScreen.hpp>
#include "Globals.h"
#include "../Core/Input.h"
#include "World.h"
#include <Objects/2D/SDL2/Sprite.hpp>

class GameState : public Openpp::IScreen
{
	GameState();
	GameState(const GameState&) = delete;
	void operator=(const GameState&) = delete;

public:
	static GameState& Get() { static GameState state; return state; }


	void HandleInputs();

	void Update();

	void Render();

protected:
	void Leave() {}
	void Enter() {}

private:
	World& mWorld;
	std::shared_ptr<SDL_Texture> mBackground;
	b2Body* player;
	b2Body* enemy;
	SDL::Sprite<int> goal;
};

#endif // GAMESTATE_H
