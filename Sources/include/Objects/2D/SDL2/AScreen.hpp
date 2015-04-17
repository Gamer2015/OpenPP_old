#ifndef OPENPP_OBJECTS_2D_SDL2_SCREEN_HPP_
#define OPENPP_OBJECTS_2D_SDL2_SCREEN_HPP_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Level Screen in SDL based Games
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  - Not Finished!
 *  - Needs to be Ported!
 *
\********************************************/

#include <SDL.h>
#include "../../IScreen.hpp"

namespace OO = Openpp::Objects;

namespace Openpp {

namespace Objects {
namespace SDL2 {

class AScreen : public IScreen
{
public:
	virtual void HandleInputs()
	{
		SDL_Event event;

		while(SDL_PollEvent(&event) != 0)
		{
			HandleInputs(event);
		}
	}

	virtual void HandleInputs(const SDL_Event &event) = 0;

	virtual void Update() = 0;

	virtual void Render() = 0;

protected:
	SDL_Texture* _mBackground;
};

} // SDL2

} // Objects
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_SCREEN_HPP_
