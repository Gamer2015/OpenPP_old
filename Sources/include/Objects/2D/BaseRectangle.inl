#include "BaseRectangle.hpp"

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
BaseRectangle<T>::BaseRectangle(LObject* _pParent) :
	BaseObject2<T>(_pParent),
	size(this)
{ }

} // Objects2D
} // Objects
} // Librepp
