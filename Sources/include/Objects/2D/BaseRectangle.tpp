#ifndef OPENPP_OBJECTS_2D_BASE_RECTANGLE_H_
#define OPENPP_OBJECTS_2D_BASE_RECTANGLE_H_

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

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
class BaseRectangle : public BaseObject2<T>
{
public:
    BaseRectangle(OObject* const _pParent = nullptr);

	Vector2<T> size;
};

} // Objects2D
} // Objects
} // Openpp

#include "BaseRectangle.inl"

#endif // OPENPP_OBJECTS_2D_BASE_RECTANGLE_H_
