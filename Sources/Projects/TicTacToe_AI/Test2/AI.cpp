#include "AI.h"
#include "Game.h"

Tree<int> AI::data;


void AI::save(int result) {

	if(result != 0) {
		if(result == Game::PLAYER_1)
			Game::moves.back().ratio = 0;
		else if(result == Game::PLAYER_2)
			Game::moves.back().ratio = 1;
		else if(result == Game::DRAW)
			Game::moves.back().ratio = 0.5;
	}

	merge(data, Game::moves);

	std::ofstream os("data.txt");
	os << data;
	os.close();
}
void AI::load() {
	std::ifstream is("data.txt");
	is >> data;
	is.close();
}

std::ostream& operator<<(std::ostream& os, const AI::Move& move)
{
	os << move.move << ' ' << move.ratio;
	return os;
}
std::istream& operator>>(std::istream& is, AI::Move& move)
{
	is >> move.move >> move.ratio;
	return is;
}
