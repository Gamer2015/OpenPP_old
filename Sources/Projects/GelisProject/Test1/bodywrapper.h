#ifndef BODYWRAPPER_H_
#define BODYWRAPPER_H_

#include <Box2D/Box2D.h>

class Body : public b2Body
{
public:
	int type;
};

#endif