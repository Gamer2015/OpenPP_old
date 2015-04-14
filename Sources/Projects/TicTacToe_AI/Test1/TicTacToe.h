#ifndef TIC_TAC_TOE_H_
#define TIC_TAC_TOE_H_

#include <Objects/2D/Vector2.hpp>
#include <cstring>
#include <vector>
#include <random>
#include <fstream>
#include "Tree.h"
#include <ctime>

void merge(Tree<int>& data, const std::vector<int>& moves);

class TicTacToe
{
public:
    enum { TILE_X = 1, TILE_O = 2 };

    static void reset() { memset(game_field, 0, 9*sizeof(int)); }
	static bool set(int x, int y, int tile)
	{
        if(check_winner() != 0)
            return false;

        bool success = true;

        tile = 3*x + y;
        if(game_field[tile] == 0) {
            game_field[tile] = tile;
            moves.push_back(tile);
        }
        else
            success = false;

        return success;
	}

    static const int* game_data() { return &game_field[0]; }
	static void print() {
		for(int y = 0; y < 3; ++y)
		{
			for(int x = 0; x < 3; ++x)
                std::cout << game_field[3*x + y] << ' ';
			std::cout << std::endl;
		}
	}

    static bool learn_move()
    {
        int move;
        bool tried;
        bool tried_all = false;
        bool _set;
        std::vector<int> positions;

        do {
            _set = false;
            move = rand() % 9;

            tried = false;
            for(int i = 0; i < positions.size(); ++i) {
                if(positions[i] == move)
                    tried = true;
            }

            if(!tried)
                positions.push_back(move);

            if(positions.size() == 9)
                tried_all = true;

            bool move_tried = false;
            if(current_move->size() != 9)
                for(int i = 0; i < current_move->size(); ++i)
                    if(move == current_move[i].data)
                        move_tried = true;

            if(move_tried == false) {
                _set = set(move%3, move/3, TILE_O);
            }

        } while(_set || tried_all == false);

        return _set;
    }
    static void read_data()
    {
        std::ifstream is("AI/data.txt");
        is >> data;
        is.close();
    }
    static int check_winner()
    {
        bool not_finished = false;

        for(int i = 0; i < 9; ++i)
            if(game_field[i] != 0)
                not_finished = true;

        int tile;
        bool finished;
        for(int y = 0; y < 3; ++y)
        {
            tile = game_field[y];
            finished = true;

            for(int x = 0; x < 3; ++x)
                if(game_field[3*x + y] != tile)
                    finished = false;

            if(finished == true)
                return tile;
        }
        for(int x = 0; x < 3; ++x)
        {
            tile = game_field[3*x];
            finished = true;
            for(int y = 0; y < 3; ++y)
                if(game_field[3*x + y] != tile)
                    finished = false;

            if(finished == true)
                return tile;
        }
        tile = game_field[4];
        finished = true;
        for(int x = 0, y = 0; x < 3 && y < 3; ++x, ++y)
        {
            if(game_field[3*x + y] != tile)
                finished = false;
        }
        if(finished == true)
            return tile;

        finished = true;
        for(int x = 2, y = 0; x >= 0 && y < 3; --x, ++y)
        {
            if(game_field[3*x + y] != tile)
                finished = false;
        }
        if(finished == true)
            return tile;

        if(not_finished == false)
            return 2;

        return 0;
    }

    static void save_game()
    {
        merge(data, moves);
        std::cout << data << std::endl;

        std::ofstream os("AI/data.txt");
        os << data;
        os.close();

        reset();
    }

private:
    static int game_field[9];
    static Tree<int> data;
    static Tree<int>* current_move;
    static std::vector<int> moves;

	TicTacToe() = delete;
};

#endif // TIC_TAC_TOE_H_
