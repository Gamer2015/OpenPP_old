#include "BaseObject2D.tpp"

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
BaseObject2<T>::BaseObject2(OObject* const _pParent) :
	OObject(_pParent),
	position(this)
{

}

} // Objects2D
} // Objects
} // Openpp
