#ifndef LIBREPP_OBJECTS_2D_SDL2_SCREEN_H_
#define LIBREPP_OBJECTS_2D_SDL2_SCREEN_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Screen Class for Games
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

class Screen
{
private:
	Screen() = delete;

public:
	/// Handle inputs of Screen
	virtual void HandleInputs() = 0;

	/// Update screen
	virtual void Update() = 0;

	/// Render screen
	virtual void Render() = 0;
};

} // SDL2
} // Objects2D
} // Objects
} // Librepp

#include "Screen.inl"

#endif // LIBREPP_OBJECTS_2D_SDL2_SCREEN_H_
