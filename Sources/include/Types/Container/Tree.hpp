#ifndef OPENPP_TYPES_CONTAINER_TREE_HPP_
#define OPENPP_TYPES_CONTAINER_TREE_HPP_

#include <map>

namespace Openpp
{
namespace Types
{
namespace Container
{

template <typename _identifier, typename _datatype>
class Tree : public std::map<_identifier, Tree<_identifier, _datatype>>
{
public:
	Tree() {}
    Tree(const _datatype& val) { _mValue = val; }

    _datatype operator=(const _datatype& rhs) { return _mValue = rhs; }
	using std::map<_identifier, Tree<_identifier, _datatype>>::operator=;

    _datatype* operator->() { return &_mValue; }
    _datatype get() const {return _mValue; }

private:
    _datatype _mValue;
};

template <typename _id, typename _type>
std::ostream& operator<<(std::ostream& cout, const Tree<_id, _type>& _rcTree)
{
    cout << _rcTree.get();
    return cout;
}

} // Container
} // Types
} // Openpp

#endif // OPENPP_TYPES_CONTAINER_TREE_HPP_
