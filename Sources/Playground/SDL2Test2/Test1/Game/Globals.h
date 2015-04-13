#ifndef GAME_GLOBALS_H_
#define GAME_GLOBALS_H_

#include <SDL.h>
#include <memory>
#include <Objects/2D/SDL2/Globals.hpp>
#include <Objects/2D/SDL2/AScreen.hpp>
#include <Objects/2D/Vector2.tpp>

namespace OO = Openpp::Objects;
namespace O2D = OO::Objects2D;
namespace SDL = O2D::SDL2;

namespace Game
{
    class Globals
    {
        // Window Dimensions
    public:
		static const char TITLE[32];
		static const O2D::Vector2<int> Window;

        // Game Spezification
    public:
        static int FPS;
        static int TICKS_FPS;
        static bool GAME_RUNNING;

        // Media
    public:
        static std::shared_ptr< SDL_Texture > gpLoadingTexture;
    };
}

#include "Globals.inl"

#endif // ___GAME_GLOBALS__H___
