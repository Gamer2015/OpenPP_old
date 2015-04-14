#ifndef TREE_H_
#define TREE_H_

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
            pos = whitespaces.find_first_not_of(' ');

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

#endif // TREE_H_
