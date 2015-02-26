#include "Game/Init.h"
#include <Objects/2D/LSDL2/Text.hpp>
#include <Objects/2D/LSDL2/Sprite.hpp>
#include <Objects/2D/LSDL2/Button.hpp>
#include <Objects/2D/LSDL2/Globals.hpp>

#include <iostream>

namespace OO = Openpp::Objects;
namespace OO2 = OO::Objects2D;
namespace LSDL2 = OO2::SDL2;
typedef LSDL2::Globals LSG;

void close()
{
	LSG::WindowIsOpen = false;
}

class TWrapper : public LSDL2::Text
{
public:
	TWrapper(OO::OObject* const _pParent = nullptr) :
		LSDL2::Text(_pParent)
	{}

	virtual void ChildChanged(int _childId)
	{
		LSDL2::Text::ChildChanged(_childId);

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
		LSDL2::Sprite<float>(_pParent)
	{}

	virtual void ChildChanged(int _childId)
	{
		LSDL2::Sprite<float>::ChildChanged(_childId);

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

class BWrapper : public LSDL2::Button
{
public:
	BWrapper(OO::OObject* const _pParent = nullptr) :
		LSDL2::Button(_pParent)
	{}

	virtual void ChildChanged(int _childId)
	{
		LSDL2::Button::ChildChanged(_childId);

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
	sprite.position.x = Game::Globals::WINDOW_X;
	sprite.position.y = Game::Globals::WINDOW_Y;
	sprite.origin.set(0, 0);
	sprite.size.set(50, 50);
	sprite.position /= 2;

	TWrapper text;
	text.origin.set(1, 1);
	text.height = 32;
	text.set("Hello1");

	BWrapper button;
	button.textures[1].set("Red.png");
	button.textures[0].set("Red.png");
	button.origin.set(-1, -1);
	button.size.set(200, 100);

	button.text.height.set(64);
	button.text.set("Hallo2");
	button.text.origin.set(-1, -1);
	button.position = text.position = sprite.position;

	int Time = SDL_GetTicks();

	std::cout << text.rect().x << '|' << text.rect().y << ' ' << text.rect().w << 'x' << text.rect().h << std::endl;

	while(LSG::WindowIsOpen)
	{
		SDL_Event Event;
		while(SDL_PollEvent(&Event) != 0)
		{
			if(Event.type == SDL_QUIT)
			{
				LSG::WindowIsOpen = false;
			}
		}

		SDL_RenderClear( LSG::Renderer() );


		button.Render();
		sprite.Render();
		text.Render();

//		text.angle += 0.05;
//		sprite.angle += 0.05;
//		button.angle += 0.05;

		SDL_RenderPresent( LSG::Renderer() );

		while(SDL_GetTicks() - Time < 1000.0/60);
		Time = SDL_GetTicks();
	}

	return 0;
}
