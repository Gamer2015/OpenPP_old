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
	Tree(const _datatype& val) { mValue = val; }

	_datatype operator=(const _datatype& rhs) { return mValue = rhs; }
	using std::map<_identifier, Tree<_identifier, _datatype>>::operator=;
	_datatype value() const { return mValue; }

private:
	_datatype mValue;
};

} // Container
} // Types
} // Openpp

#endif // OPENPP_TYPES_CONTAINER_TREE_HPP_
