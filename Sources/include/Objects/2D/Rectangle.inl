#include "Rectangle.hpp"

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
Rectangle<T>::Rectangle(LObject* _pParent) :
	BaseRectangle<T>(_pParent),
	origin(this),
	angle(this)
{ }

} // Objects2D
} // Objects
} // Openpp
