#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
class Tree : public std::vector<Tree<T>>
{
public:
	Tree() : data() {}
	Tree(T data) : data(data) {}
	T data; // 0xF = Tile | 0xF0 = position

	void print(std::ostream& os, const std::string& prefix="") const
	{
		os << prefix << this->data << std::endl;
		for(int i = 0; i < this->size(); ++i)
			this->operator[](i).print(os, prefix + " ");
	}
	void set(std::istream& is)
	{
		this->clear();
		this->data = T();

		std::string whitespaces;
		std::getline(is, whitespaces);
		int pos = whitespaces.find_first_not_of(' ');

		std::stringstream ss;
		if(pos < whitespaces.size())
			ss.str(whitespaces.substr(pos));

		T data;
		ss >> data;

		while(std::getline(is, whitespaces))
		{
			int pos = whitespaces.find_first_not_of(' ');

			std::stringstream ss;
			if(pos < whitespaces.size())
				ss.str(whitespaces.substr(pos));

			T data;
			ss >> data;


			Tree<T>* last = this;
			for(int i = 0; i < pos - 1; ++i)
			{
				if(last->size() == 0)
					this->push_back(Tree<T>());
				last = &last->back();
			}

			last->push_back(Tree<T>(data));
		}
	}
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& tree)
{
	tree.print(os);
	return os;
}
template <typename T>
std::istream& operator>>(std::istream& is, Tree<T>& tree)
{
	tree.set(is);
	return is;
}

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


int main(void)
{
	Tree<int> tree;

	std::vector<int> moves = { 1, 2, 3 };
	merge(tree, moves);
	merge(tree, moves);
	merge(tree, moves);

	std::vector<int> moves2 = { 1, 3, 4 };
	merge(tree, moves2);
	merge(tree, moves2);

	std::ofstream os("test.txt");
	os << tree;
	os.close();
	std::cout << tree << "\n\n\n" << std::endl;

	Tree<int> tree1;
	std::ifstream is("test.txt");
	is >> tree1;
	is.close();
	std::cout << tree1 << std::endl;

    return 0;
}
