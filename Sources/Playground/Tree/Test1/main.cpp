#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

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
        std::string whitespaces;
        std::getline(is, whitespaces);
        int pos = whitespaces.find_first_not_of(' ');

        std::stringstream ss;
        ss.str(whitespaces.substr(pos));

        ss >> this->data;

        //while(is)
        for(int i = 0; i < 20; ++i)
        {
            std::getline(is, whitespaces);
            int pos = whitespaces.find_first_not_of(' ');

            std::stringstream ss;
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

int main(void)
{
    Tree<int> tree;
    tree.data = 10;
    tree.push_back(Tree<int>(5));
    tree[0].push_back(Tree<int>(6));
    tree[0][0].push_back(Tree<int>(6));
    tree[0][0].push_back(Tree<int>(7));
    tree[0][0].push_back(Tree<int>(8));
    tree[0][0].push_back(Tree<int>(9));
    tree[0].push_back(Tree<int>(7));
    tree[0][1].push_back(Tree<int>(6));
    tree[0][1].push_back(Tree<int>(7));
    tree[0][1].push_back(Tree<int>(8));
    tree[0][1].push_back(Tree<int>(9));
    tree[0].push_back(Tree<int>(8));
    tree[0][2].push_back(Tree<int>(6));
    tree[0][2].push_back(Tree<int>(7));
    tree[0][2].push_back(Tree<int>(8));
    tree[0][2].push_back(Tree<int>(9));
    tree[0].push_back(Tree<int>(9));
    tree[0][3].push_back(Tree<int>(6));
    tree[0][3].push_back(Tree<int>(7));
    tree[0][3].push_back(Tree<int>(8));
    tree[0][3].push_back(Tree<int>(9));

    tree.push_back(Tree<int>(5));
    tree[1].push_back(Tree<int>(6));
    tree[1][0].push_back(Tree<int>(6));
    tree[1][0].push_back(Tree<int>(7));
    tree[1][0].push_back(Tree<int>(8));
    tree[1][0].push_back(Tree<int>(9));
    tree[1].push_back(Tree<int>(7));
    tree[1][1].push_back(Tree<int>(6));
    tree[1][1].push_back(Tree<int>(7));
    tree[1][1].push_back(Tree<int>(8));
    tree[1][1].push_back(Tree<int>(9));
    tree[1].push_back(Tree<int>(8));
    tree[1][2].push_back(Tree<int>(6));
    tree[1][2].push_back(Tree<int>(7));
    tree[1][2].push_back(Tree<int>(8));
    tree[1][2].push_back(Tree<int>(9));
    tree[1].push_back(Tree<int>(9));
    tree[1][3].push_back(Tree<int>(6));
    tree[1][3].push_back(Tree<int>(7));
    tree[1][3].push_back(Tree<int>(8));
    tree[1][3].push_back(Tree<int>(9));

    std::ofstream ofile("Tree.txt");
    ofile << tree;
    ofile.close();

    Tree<int> tree1;
    std::ifstream ifile("Tree.txt");
    ifile >> tree1;
    ifile.close();

    std::cout << tree1;

    return 0;
}
