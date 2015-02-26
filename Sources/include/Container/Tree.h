#ifndef ___LIBREPP_CONTAINER_TREE__H___
#define ___LIBREPP_CONTAINER_TREE__H___

#include <map>

namespace Librepp
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
} // Librepp

#endif // ___LIBREPP_CONTAINER_TREE__H___
