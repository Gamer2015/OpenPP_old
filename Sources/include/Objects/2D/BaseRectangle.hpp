#ifndef LIBREPP_OBJECTS_2D_BASE_RECTANGLE_H_
#define LIBREPP_OBJECTS_2D_BASE_RECTANGLE_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Base Rectangle Class
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include "BaseObject2D.hpp"
#include "Vector2.hpp"

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
class BaseRectangle : public BaseObject2<T>
{
public:
	BaseRectangle(LObject* _pParent = nullptr);

	Vector2<T> size;
};

} // Objects2D
} // Objects
} // Librepp

#include "BaseRectangle.inl"

#endif // LIBREPP_OBJECTS_2D_BASE_RECTANGLE_H_
