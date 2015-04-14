#ifndef GAME_H
#define GAME_H

#include <Objects/2D/Vector2.hpp>
#include <cstring>
#include <vector>
#include <tuple>
#include "AI.h"

class Game {

public:
	static enum state{ PLAYING=0, PLAYER_1=1, PLAYER_2=2, DRAW=3 } game_state;
	enum { TILE_X=PLAYER_1, TILE_O=PLAYER_2 };

	static void reset() {
		game_state = PLAYING;
		memset(game_field, 0, 9*sizeof(int));
	}
	static void print() {
		for(int y = 0; y < 3; ++y) {
			for(int x = 0; x < 3; ++x)
				std::cout << game_field[3*x + y] << ' ';
			std::cout << std::endl;
		}
	}

	static bool set(int x, int y, int move)
	{
		if(game_state != PLAYING)
			return false;

		int field = 3*x + y;
		if(game_field[field] != 0)
			return false;

		game_field[field] = move;
		moves.push_back(std::tuple<int, float>(field, 2.0));
		check_game_state();

		return true;
	}

	static const int* game_data() { return &game_field[0]; }

private:
	friend class AI;
	static std::vector<std::tuple<int, float>> moves;

	static int game_field[9];
	static void check_game_state()
	{
		game_state = PLAYING;
		bool not_finished = false;
		for(int i = 0; i < 9; ++i)
			if(game_field[i] != 0)
				not_finished = true;

		int tile;
		bool finished;

		// columns
		for(int y = 0; y < 3; ++y)
		{
			tile = game_field[y];
			finished = true;

			for(int x = 0; x < 3; ++x)
				if(game_field[3*x + y] != tile)
					finished = false;

			if(finished == true && game_state == PLAYING)
				game_state = (state)tile;
		}
		// rows
		for(int x = 0; x < 3; ++x)
		{
			tile = game_field[3*x];
			finished = true;
			for(int y = 0; y < 3; ++y)
				if(game_field[3*x + y] != tile)
					finished = false;

			if(finished == true && game_state == PLAYING)
				game_state = (state)tile;
		}

		// Diagonal Tests
		tile = game_field[4];
		finished = true;
		for(int x = 0, y = 0; x < 3 && y < 3; ++x, ++y)
		{
			if(game_field[3*x + y] != tile)
				finished = false;
		}
		if(finished == true && game_state == PLAYING)
			game_state = (state)tile;

		finished = true;
		for(int x = 2, y = 0; x >= 0 && y < 3; --x, ++y)
		{
			if(game_field[3*x + y] != tile)
				finished = false;
		}
		if(finished == true && game_state == PLAYING)
			game_state = (state)tile;

		if(not_finished == false && game_state == PLAYING)
			game_state = DRAW;
	}
};

#endif // GAME_H
