#include "BaseObject2D.hpp"

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
BaseObject2<T>::BaseObject2(LObject* _pParent) :
	LObject(_pParent),
	position(this)
{

}

} // Objects2D
} // Objects
} // Openpp
