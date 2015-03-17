#include "Globals.hpp"

std::shared_ptr<SDL_Texture> Globals::pButtonTextures[];
std::shared_ptr<SDL_Texture> Globals::pBackground;

const std::string Globals::_title("Open Map Editor");
const O2D::Vector2<int> Globals::_window_size(640, 480);
const int Globals::_fps = 60;

OO::ScreenPointer Globals::gpCurrentScreen;

