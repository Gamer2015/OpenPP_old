#ifndef OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_SCREENS_SCREENS_HPP_
#define OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_SCREENS_SCREENS_HPP_

#include "StartScreen.hpp"

namespace Screens
{

StartScreen gStartScreen;

void Initialize()
{
	gStartScreen.Initialize();
}

} // Screens

#endif // OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_SCREENS_SCREENS_HPP_
