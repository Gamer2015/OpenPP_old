#include "TicTacToe.h"

int TicTacToe::game_field[9];
Tree<int> TicTacToe::data;
Tree<int>* TicTacToe::current_move = &data;
std::vector<int> TicTacToe::moves;


void merge(Tree<int>& data, const std::vector<int>& moves)
{
    Tree<int>* move;
    bool move_exists = false;

    for(int i = 0; i < data.size(); ++i)
        if(moves[0] == data[i].data) {
            move_exists == true;
            move = &data[i];
        }

    if(move_exists == false) {
        data.push_back(Tree<int>());
        move = &data.back();
    }
    move->data = moves[0];

    merge(*move, std::vector<int>(moves.begin()+1, moves.end()));
}
