#include "GameState.h"
#include "PauseState.h"

GameState::GameState() :
	mBackground(SDL::Texture::Get("Background.jpg").texture),
	mWorld(mWorld.Get())
{
	goal.set("Red.png");
	goal.position.set(50, 50);
	goal.size.set(120, 120);
	goal.origin.set(-1, -1);

	mWorld.CreateBox(0.0, 1.0, 80.0, 1.0);
	mWorld.CreateBox(0.0, 25.0, 80.0, 1.0);
	mWorld.CreateBox(-1.0, 25.0, 1.0, 80.0);
	mWorld.CreateBox(23.0, 25.0, 1.0, 80.0);

	mWorld.CreateBox(16.8, 10.0, 1.0, 1.0);
	mWorld.CreateBox(12.8, 15.0, 1.0, 1.0);

	enemy = mWorld.CreateBox(10, 10.0, 1.0, 1.0, 0.9);
	player = mWorld.CreateBox(14.3, 20.0, 1.0, 1.0, 0.99);

	mWorld.CreateCircle(8.0, 8.0, 1.0, 0.9);
}

void GameState::HandleInputs()
{
	if(Input::KeyDown(Input::BUTTON_MAIN))
		SDL::Globals::WindowIsOpen = false;
	if(Input::KeyDown(Input::BUTTON_START))
		Globals::gpCurrentScreen = PauseState::Get();

	if(Input::KeyDown(Input::BUTTON_UP))
		mWorld.SetGravity(0, 10);
	if(Input::KeyDown(Input::BUTTON_DOWN))
		mWorld.SetGravity(0, -10);
	if(Input::KeyDown(Input::BUTTON_LEFT))
		mWorld.SetGravity(-10, 0);
	if(Input::KeyDown(Input::BUTTON_RIGHT))
		mWorld.SetGravity(10, 0);

	b2Vec2 force;
	force.SetZero();
	if(Input::KeyIsPressed(Input::BUTTON_A)) // left
		force.x -= 100;
	if(Input::KeyIsPressed(Input::BUTTON_B)) // down
		force.y -= 100;
	if(Input::KeyIsPressed(Input::BUTTON_Y)) // up
		force.y += 100;
	if(Input::KeyIsPressed(Input::BUTTON_X)) // right
		force.x += 100;
	player->ApplyForce( force, player->GetWorldCenter(), true );
	player->SetAngularVelocity(player->GetAngularVelocity() * 0.995);

	float torque(0);
	if(Input::KeyIsPressed(Input::BUTTON_ROTATE_R))
		torque += 6;
	if(Input::KeyIsPressed(Input::BUTTON_ROTATE_L))
		torque -= 6;
	if(player->GetAngularVelocity() < 6 && player->GetAngularVelocity() > -6)
		player->ApplyAngularImpulse(torque, true);
}

void GameState::Update()
{
	mWorld.Step();

	bool inside = false;
	b2Fixture* fixture = enemy->GetFixtureList();
	b2PolygonShape* Shape = (b2PolygonShape*)fixture->GetShape();

	int vcount = Shape->GetVertexCount();
	for(int i = 0; i < vcount; ++i)
	{
		if(goal.isInside(Shape->GetVertex(i).x * Globals::Scaling + enemy->GetPosition().x * Globals::Scaling,
						 Globals::Window.y - (Shape->GetVertex(i).y * Globals::Scaling + enemy->GetPosition().y * Globals::Scaling)))
		{
			inside = true;
			break;
		}
	}
	if(inside)
		std::cout << "You Win!" << std::endl;
}

void GameState::Render()
{
	SDL_RenderCopy(SDL::Globals::Renderer(), mBackground.get(), NULL, NULL);
	goal.Render();

	mWorld.Render();
}
