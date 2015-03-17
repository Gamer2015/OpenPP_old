#include "Game/Init.h"
#include <Objects/2D/SDL2/Text.hpp>
#include <Objects/2D/SDL2/Sprite.tpp>
#include <Objects/2D/SDL2/Button.hpp>
#include <Objects/2D/SDL2/Globals.hpp>

#include <iostream>

namespace OO = Openpp::Objects;
namespace OO2 = OO::Objects2D;
namespace SDL = OO2::SDL2;

void close()
{
	SDL::Globals::WindowIsOpen = false;
}

class TWrapper : public LSDL2::Text
{
public:
	TWrapper(OO::OObject* const _pParent = nullptr) :
		SDL::Text(_pParent)
	{}

	virtual void ChildChanged(int _childId)
	{
		SDL::Text::ChildChanged(_childId);

		std::cout << "Text Id: " << _childId << ": ";
		if(_childId == selfId())
		{
			std::cout << "Self changed!";
		}
		if(_childId == angle.id())
		{
			std::cout << "angle changed!";
		}
		if(_childId == height.id())
		{
			std::cout << "size changed!";
		}
		if(_childId == position.id())
		{
			std::cout << "position changed!";
		}
		if(_childId == origin.id())
		{
			std::cout << "origin changed!";
		}
		if(_childId == size().id())
		{
			std::cout << "size changed!";
		}
		std::cout << std::endl;
	}
};

class SWrapper : public LSDL2::Sprite<float>
{
public:
	SWrapper(OO::OObject* const _pParent = nullptr) :
		SDL::Sprite<float>(_pParent)
	{}

	virtual void ChildChanged(int _childId)
	{
		SDL::Sprite<float>::ChildChanged(_childId);

		std::cout << "Sprite Id: " << _childId << ": ";
		if(_childId == selfId())
		{
			std::cout << "Self changed!";
		}
		if(_childId == angle.id())
		{
			std::cout << "angle changed!";
		}
		if(_childId == size.id())
		{
			std::cout << "size changed!";
		}
		if(_childId == position.id())
		{
			std::cout << "position changed!";
		}
		if(_childId == origin.id())
		{
			std::cout << "origin changed!";
		}
		std::cout << std::endl;
	}
};

class BWrapper : public SDL::Button
{
public:
	BWrapper(OO::OObject* const _pParent = nullptr) :
		SDL::Button(_pParent)
	{}

	virtual void ChildChanged(int _childId)
	{
		SDL::Button::ChildChanged(_childId);

		std::cout << "Button Id: " << _childId << ": ";
		if(_childId == selfId())
		{
			std::cout << "Self changed!";
		}
		else if(_childId == angle.id())
		{
			std::cout << "angle changed!";
		}
		else if(_childId == text.id())
		{
			std::cout << "text changed!";
		}
		else if(_childId == position.id())
		{
			std::cout << "position changed!";
		}
		else if(_childId == size.id())
		{
			std::cout << "Size changed!";
		}
		else if(_childId == origin.id())
		{
			std::cout << "origin changed!";
		}
		else if(_childId == textures[0].id())
		{
			std::cout << "texture[0] changed";
		}
		else if(_childId == textures[1].id())
		{
			std::cout << "texture[1] changed";
		}
		std::cout << std::endl;
	}
};

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	Game::Init::Init();

	SWrapper sprite;
	sprite.set("Red.png");
	sprite.position.set(0, 0);
	sprite.origin.set(-1, -1);
	sprite.size.set(50, 50);

	TWrapper text;
	text.origin.set(1, 1);
	text.height = 32;
	text.set("Hello1");
	std::cout << "create Button" << std::endl;
	text.position = Game::Globals::Window;

	std::cout << "create Button" << std::endl;
	BWrapper button;
	button.textures[0].set("Red.png");
	button.textures[1].set("green.png");
	button.origin.set(0, 0);
	button.size.set(200, 100);

	button.text.height.set(64);
	button.angle = M_PI / 2;
	button.text.set("Hallo2");
	button.text.origin.set(-1, -1);
	button.position = Game::Globals::Window / 2;

	O2D::Vector2<int> mouse;

	int Time;
	int i = 0;
	int textureNumber = 0;

	std::cout << text.rect().x << '|' << text.rect().y << ' ' << text.rect().w << 'x' << text.rect().h << std::endl;

	while( SDL::Globals::WindowIsOpen )
	{
		Time = SDL_GetTicks();

		SDL_Event event;
		while(SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
			{
				SDL::Globals::WindowIsOpen = false;
			}

			if(event.type == SDL_MOUSEMOTION)
			{
				mouse.set(event.motion.x, event.motion.y);
			}
		}

		SDL_RenderClear( SDL::Globals::Renderer() );

		if(button.isInside(mouse.x, mouse.y))
			textureNumber = 1;
		else
			textureNumber = 0;

		button.Render(textureNumber);
		sprite.Render();
		text.Render();

		button.angle += 0.05;

		SDL_RenderPresent( SDL::Globals::Renderer() );

		while(SDL_GetTicks() - Time < 1000.0/60);
	}

	return 0;
}
