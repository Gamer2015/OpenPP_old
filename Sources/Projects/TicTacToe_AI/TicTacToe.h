#ifndef TIC_TAC_TOE_H_
#define TIC_TAC_TOE_H_

#include <Objects/2D/Vector2.hpp>

class TicTacToe
{
public:
	enum { TILE_X = 1, TILE_O = 2 };
	struct Field { int data[3][3]; };

	static void reset() { memset(game_field.data, 0, 3*3*sizeof(int)); }
	static bool set(int x, int y, int tile)
	{
		if(game_field.data[x][y] == 0)
			game_field.data[x][y] = tile;
		else
			return false;
		return true;
	}

	static const Field& game_data() { return game_field; }
	static void print() {
		for(int y = 0; y < 3; ++y)
		{
			for(int x = 0; x < 3; ++x)
				std::cout << game_field.data[x][y] << ' ';
			std::cout << std::endl;
		}
	}

private:
	static Field game_field;

	TicTacToe() = delete;
};
TicTacToe::Field TicTacToe::game_field;

#endif // TIC_TAC_TOE_H_
