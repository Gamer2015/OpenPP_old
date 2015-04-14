#ifndef TTT_AI_H
#define TTT_AI_H

#include "Tree.h"

class AI {

public:
	struct Move { int move; float ratio; };
	static void save(int result);

	static void load();

private:
	static Tree< Move > data;

	template <typename T>
	void merge(Tree<T>& tree, const std::vector<T>& vector)
	{
		Tree<T>* current = &tree;
		bool move_exists;

		for(typename std::vector<T>::const_iterator iter = vector.begin(); iter != vector.end(); ++iter) {
			move_exists = false;
			for(int i = 0; i < current->size(); ++i) {
				if(*iter == (*current)[i].data) {
					move_exists = true;
					current = &(*current)[i];
					break;
				}
			}

			if(move_exists == false) {
				current->push_back(Tree<T>(*iter));
				current = &current->back();
			}
		}
	}
};

std::ostream& operator<<(std::ostream& os, const AI::Move& move);
std::istream& operator>>(std::istream& is, AI::Move& move);

#endif // TTT_AI_H
