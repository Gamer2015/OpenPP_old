#ifndef OPENPP_OBJECTS_2D_SDL2_SCREEN_H_
#define OPENPP_OBJECTS_2D_SDL2_SCREEN_H_

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

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{

class Screen
{
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
} // Openpp

#endif // OPENPP_OBJECTS_2D_SDL2_SCREEN_H_
