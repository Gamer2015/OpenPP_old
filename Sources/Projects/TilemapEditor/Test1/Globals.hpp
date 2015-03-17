#ifndef OPENPP_PROJECTS_TILEMAP_EDITOR_GLOBALS_HPP_
#define OPENPP_PROJECTS_TILEMAP_EDITOR_GLOBALS_HPP_

#include <SDL.h>
#include <string>
#include <vector>
#include <memory>
#include <Objects/2D/Vector2.tpp>
#include <Objects/IScreen.hpp>

namespace OO = Openpp::Objects;
namespace O2D = OO::Objects2D;

class Globals
{
public:
	static const std::string Title() { return _title; }
	static const O2D::Vector2<int> Window() { return _window_size; }

	static const int FPS() { return _fps; }

	static OO::ScreenPointer gpCurrentScreen;

	enum ButtonTextures { BUTTON_DEFAULT, BUTTON_HOVER, TEXTURES_COUNT };
	static std::shared_ptr<SDL_Texture> pButtonTextures[TEXTURES_COUNT];
	static std::shared_ptr<SDL_Texture> pBackground;

private:
	static const std::string _title;
	static const O2D::Vector2<int> _window_size;

	static const int _fps;
};

#endif // OPENPP_PROJECTS_TILEMAP_EDITOR_GLOBALS_HPP_
