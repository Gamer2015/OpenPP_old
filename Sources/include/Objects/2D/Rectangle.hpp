#ifndef OPENPP_OBJECTS_2D_RECTANGLE_H_
#define OPENPP_OBJECTS_2D_RECTANGLE_H_

/********************************************\
 * Usage: 2D rectangle LObject
 * Date: 20th of February 2015
 * Author: Stefan Kreiner
 * _______________________________________________
 *
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include "BaseRectangle.hpp"
#include "Vector2.hpp"

namespace Openpp {
namespace Objects {
namespace Objects2D {

template <typename T>
class Rectangle : public BaseRectangle<T>
{
public:
    Rectangle(OObject* const _pParent = nullptr);

	Vector2<T> origin;
	Objects::Properties::OType<float> angle;
};

} // Objects2D
} // Objects
} // Openpp

#include "Rectangle.tpp"

#endif // OPENPP_OBJECTS_2D_RECTANGLE_H_
