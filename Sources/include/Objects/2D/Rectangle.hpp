#ifndef Openpp_OBJECTS_2D_RECTANGLE_H_
#define Openpp_OBJECTS_2D_RECTANGLE_H_

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

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
class Rectangle : public BaseRectangle<T>
{
public:
	Rectangle(LObject* _pParent = nullptr);

	Vector2<T> origin;
	Objects::Properties::LType<float> angle;
};

} // Objects2D
} // Objects
} // Openpp

#include "Rectangle.inl"

#endif // Openpp_OBJECTS_2D_RECTANGLE_H_
