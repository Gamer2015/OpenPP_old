#ifndef LIBREPP_OBJECTS_2D_BASE_OBJECT_H_
#define LIBREPP_OBJECTS_2D_BASE_OBJECT_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: 2D base object class
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <Objects/LObject.hpp>

#include "Vector2.hpp"

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
class BaseObject2 : protected LObject
{
protected:
	BaseObject2(LObject* _pParent = nullptr);

public:
	Vector2<T> position;
};

} // Objects2D
} // Objects
} // Librepp

#include "BaseObject2D.inl"

#endif // LIBREPP_OBJECTS_2D_BASE_OBJECT_H_
