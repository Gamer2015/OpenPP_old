#include "Input.h"

/// public
void Input::Read()
{
	mOldButtons = mButtons;

#ifdef USE_SFML_INPUT

	static sf::Event Event;

	while( Core::Globals::gpWindow->pollEvent(Event) )
	{
		if( Event.type == sf::Event::KeyPressed )
		{
			switch(Event.key.code)
			{
				case sf::Keyboard::A: mButtons |= BUTTON_LEFT;
					break;
				case sf::Keyboard::S: mButtons |= BUTTON_DOWN;
					break;
				case sf::Keyboard::W: mButtons |= BUTTON_UP;
					break;
				case sf::Keyboard::D: mButtons |= BUTTON_RIGHT;
					break;

				case sf::Keyboard::J: mButtons |= BUTTON_A;
					break;
				case sf::Keyboard::K: mButtons |= BUTTON_B;
					break;
				case sf::Keyboard::I: mButtons |= BUTTON_Y;
					break;
				case sf::Keyboard::L: mButtons |= BUTTON_X;
					break;

				case sf::Keyboard::V: mButtons |= BUTTON_MAIN;
					break;
				case sf::Keyboard::B: mButtons |= BUTTON_SELECT;
					break;
				case sf::Keyboard::N: mButtons |= BUTTON_START;
					break;

				default:
					break;
			}
		}
		else if ( Event.type == sf::Event::KeyReleased )
		{
			switch(Event.key.code)
			{
				case sf::Keyboard::A: mButtons &= ~(BUTTON_LEFT);
					break;
				case sf::Keyboard::S: mButtons &= ~(BUTTON_DOWN);
					break;
				case sf::Keyboard::W: mButtons &= ~(BUTTON_UP);
					break;
				case sf::Keyboard::D: mButtons &= ~(BUTTON_RIGHT);
					break;

				case sf::Keyboard::J: mButtons &= ~(BUTTON_A);
					break;
				case sf::Keyboard::K: mButtons &= ~(BUTTON_B);
					break;
				case sf::Keyboard::I: mButtons &= ~(BUTTON_Y);
					break;
				case sf::Keyboard::L: mButtons &= ~(BUTTON_X);
					break;

				case sf::Keyboard::V: mButtons &= ~(BUTTON_MAIN);
					break;
				case sf::Keyboard::B: mButtons &= ~(BUTTON_SELECT);
					break;
				case sf::Keyboard::N: mButtons &= ~(BUTTON_START);
					break;

				default:
					break;
			}
		}
	}

#elif defined(USE_SDL_INPUT)

	static SDL_Event Event;

	while(SDL_PollEvent(&Event) != 0)
	{
		if (Event.type == SDL_KEYDOWN)
		{
			switch(Event.key.keysym.sym)
			{
				case SDLK_a: mButtons |= (BUTTON_LEFT);
					break;
				case SDLK_s: mButtons |= (BUTTON_DOWN);
					break;
				case SDLK_w: mButtons |= (BUTTON_UP);
					break;
				case SDLK_d: mButtons |= (BUTTON_RIGHT);
					break;

				case SDLK_LEFT: mButtons |= (BUTTON_A);
					break;
				case SDLK_DOWN: mButtons |= (BUTTON_B);
					break;
				case SDLK_UP: mButtons |= (BUTTON_Y);
					break;
				case SDLK_RIGHT: mButtons |= (BUTTON_X);
					break;

				case SDLK_k: mButtons |= (BUTTON_MAIN);
					break;
				case SDLK_b: mButtons |= (BUTTON_SELECT);
					break;
				case SDLK_p: mButtons |= (BUTTON_START);
					break;

				case SDLK_x: mButtons |= (BUTTON_ROTATE_R);
					break;
				case SDLK_y: mButtons |= (BUTTON_ROTATE_L);
					break;

				default:
					break;
			}
		}
		else if(Event.type == SDL_KEYUP)
		{
			switch(Event.key.keysym.sym)
			{
				case SDLK_a: mButtons &= ~(BUTTON_LEFT);
					break;
				case SDLK_s: mButtons &= ~(BUTTON_DOWN);
					break;
				case SDLK_w: mButtons &= ~(BUTTON_UP);
					break;
				case SDLK_d: mButtons &= ~(BUTTON_RIGHT);
					break;

				case SDLK_LEFT: mButtons &= ~(BUTTON_A);
					break;
				case SDLK_DOWN: mButtons &= ~(BUTTON_B);
					break;
				case SDLK_UP: mButtons &= ~(BUTTON_Y);
					break;
				case SDLK_RIGHT: mButtons &= ~(BUTTON_X);
					break;

				case SDLK_k: mButtons &= ~(BUTTON_MAIN);
					break;
				case SDLK_b: mButtons &= ~(BUTTON_SELECT);
					break;
				case SDLK_p: mButtons &= ~(BUTTON_START);
					break;

				case SDLK_x: mButtons &= ~(BUTTON_ROTATE_R);
					break;
				case SDLK_y: mButtons &= ~(BUTTON_ROTATE_L);
					break;

				default:
					break;
			}
		}
	}

#elif defined(USE_RASPBERRY_INPUT)


#endif
}

bool Input::KeyIsPressed(EButton button)
{
	return (mButtons & button);
}

bool Input::KeyDown(EButton button)
{
	if( KeyWasPressed(button) == false && KeyIsPressed(button) == true )
	{
		return true;
	}
	return false;
}
bool Input::KeyUp(EButton button)
{
	if( KeyWasPressed(button) == true && KeyIsPressed(button) == false)
	{
		return true;
	}
	return false;
}

/// private
bool Input::KeyWasPressed(EButton button)
{
	return (mOldButtons & button);
}

unsigned short Input::mOldButtons = 0;
unsigned short Input::mButtons = 0;
