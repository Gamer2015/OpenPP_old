namespace Openpp {
namespace Objects {

template <typename T>
Rectangle<T>::Rectangle(OObject* const _pParent) :
	BaseRectangle<T>(_pParent),
	origin(this),
	angle(this)
{ }


} // Objects
} // Openpp
