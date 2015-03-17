#ifndef OPENPP_PROJECTS_TILEMAP_EDITOR_INITIALIZE_HPP_
#define OPENPP_PROJECTS_TILEMAP_EDITOR_INITIALIZE_HPP_

#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/Texture.hpp>
#include "Editor/Screens/Screens.hpp"
#include "Globals.hpp"

namespace OO = Openpp::Objects;
namespace O2D = OO::Objects2D;
namespace SDL = O2D::SDL2;

void Initialize()
{
	SDL::Globals::Init(Globals::Title(), Globals::Window());

	SDL::Texture::LoadFont("Media/Font.ttf", 128);

	Globals::pButtonTextures[Globals::BUTTON_DEFAULT] = SDL::Texture::Get("Media/ButtonDefault.png");
	Globals::pButtonTextures[Globals::BUTTON_HOVER] = SDL::Texture::Get("Media/ButtonHover.png");

	Globals::pBackground = SDL::Texture::Get("Media/Background.jpg");

	Screens::Initialize();
}

#endif // OPENPP_PROJECTS_TILEMAP_EDITOR_INITIALIZE_HPP_
