#include "Globals.h"

// Window Dimewnsions
const char Globals::Title[16] = "Test 2";
const OO::Vector2<int> Globals::Window(720, 720);

// Game Spezification
const int Globals::FPS = 50;
const int Globals::TICKS_FPS = 40;
bool Globals::GAME_RUNNING = false;

// Current State
Openpp::ScreenPointer Globals::gpCurrentScreen;

// box2d->sdl scaling
int Globals::Scaling(30);
