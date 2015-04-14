#include "TicTacToe.h"

int TicTacToe::game_field[9];
Tree<int> TicTacToe::data;
Tree<int>* TicTacToe::current_move = &data;
std::vector<int> TicTacToe::moves;
