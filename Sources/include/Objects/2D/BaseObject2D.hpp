#ifndef OPENPP_OBJECTS_2D_BASE_OBJECT_H_
#define OPENPP_OBJECTS_2D_BASE_OBJECT_H_

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

#include "../OObject.hpp"

#include "Vector2.hpp"

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{

template <typename T>
class BaseObject2 : public OObject
{
protected:
    BaseObject2(OObject* const _pParent = nullptr);

public:
	Vector2<T> position;
};

} // Objects2D
} // Objects
} // Openpp

#include "BaseObject2D.tpp"

#endif // OPENPP_OBJECTS_2D_BASE_OBJECT_H_
