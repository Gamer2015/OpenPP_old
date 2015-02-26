#include "Input.h"

namespace Core
{
    namespace Input
    {

#if defined(USE_SFML_INPUT) || defined(USE_SDL_INPUT)
        unsigned short mOldButtons = 0;
        unsigned short mButtons = 0;
#endif

		void Read()
        {

#if defined(USE_SFML_INPUT) || defined(USE_SDL_INPUT)
            mOldButtons = mButtons;
#endif

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

                    case SDLK_j: mButtons |= (BUTTON_A);
                        break;
                    case SDLK_k: mButtons |= (BUTTON_B);
                        break;
                    case SDLK_i: mButtons |= (BUTTON_Y);
                        break;
                    case SDLK_l: mButtons |= (BUTTON_X);
                        break;

                    case SDLK_v: mButtons |= (BUTTON_MAIN);
                        break;
                    case SDLK_b: mButtons |= (BUTTON_SELECT);
                        break;
                    case SDLK_n: mButtons |= (BUTTON_START);
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

                    case SDLK_j: mButtons &= ~(BUTTON_A);
                        break;
                    case SDLK_k: mButtons &= ~(BUTTON_B);
                        break;
                    case SDLK_i: mButtons &= ~(BUTTON_Y);
                        break;
                    case SDLK_l: mButtons &= ~(BUTTON_X);
                        break;

                    case SDLK_v: mButtons &= ~(BUTTON_MAIN);
                        break;
                    case SDLK_b: mButtons &= ~(BUTTON_SELECT);
                        break;
                    case SDLK_n: mButtons &= ~(BUTTON_START);
                        break;

                    default:
                        break;
                    }
                }
            }

#elif defined(USE_RASPBERRY_INPUT)
            INPUT::RaspIO::Read();
#endif
		}

#if defined(USE_SFML_INPUT) || defined(USE_SDL_INPUT)
        bool KeyWasPressed(INPUT::EButton button)
        {
            return (mOldButtons & button);
        }
#endif

        bool KeyIsPressed(INPUT::EButton button)
		{
#if defined(USE_SFML_INPUT) || defined(USE_SDL_INPUT)
            return (mButtons & button);
#elif defined(USE_RASPBERRY_INPUT)
            return INPUT::RaspIO::KeyIsPressed(button);
#endif
        }

        bool KeyDown(INPUT::EButton button)
        {
#if defined(USE_SFML_INPUT) || defined(USE_SDL_INPUT)
			if( KeyWasPressed(button) == false && KeyIsPressed(button) == true )
			{
				return true;
			}
			return false;
#else
            return INPUT::RaspIO::KeyDown(button);
#endif
		}
        bool KeyUp(INPUT::EButton button)
        {
#if defined(USE_SFML_INPUT) || defined(USE_SDL_INPUT)
			if( KeyWasPressed(button) == true && KeyIsPressed(button) == false)
			{
				return true;
			}
			return false;
#else
            return INPUT::RaspIO::KeyUp(button);
#endif
		}
	}
}
