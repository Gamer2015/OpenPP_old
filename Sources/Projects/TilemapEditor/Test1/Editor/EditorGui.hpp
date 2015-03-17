#ifndef OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_EDITOR_GUI_HPP_
#define OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_EDITOR_GUI_HPP_

#include <iostream>
#include <Objects/IScreen.hpp>
#include "Screens/Screens.hpp"

class EditorGui
{
public:
	/// Initialize the Gui
	EditorGui()
	{
		_mCurrentScreen = &Screens::gStartScreen;
	}

	OO::IScreen* operator->() { return _mCurrentScreen.operator->(); }

private:
	OO::ScreenPointer _mCurrentScreen;
};

#endif // OPENPP_PROJECTS_TILEMAP_EDITOR_EDITOR_EDITOR_GUI_HPP_
