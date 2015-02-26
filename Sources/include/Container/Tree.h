#ifndef Openpp_CONTAINER_TREE_H_
#define Openpp_CONTAINER_TREE_H_

#include <map>

namespace Openpp
{
namespace Container
{

template <typename I, typename T>
class Tree : public std::map<I, Tree<I, T>>
{
public:
	Tree() {}
	Tree(T val) { mValue = val; }

	T operator=(const T& rhs) { return mValue = rhs; }
	using std::map<I, Tree<I, T>>::operator=;
	T value() { return mValue; }

private:
	T mValue;
};

} // Container
} // Openpp

#endif // Openpp_CONTAINER_TREE_H_
