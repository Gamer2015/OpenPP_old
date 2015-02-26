#ifndef _____ABC___H___
#define _____ABC___H___

#include "D.h"

class A
{
	const Base* __mParent;
	int __mID;

public:
	A(const Base* parent = NULL, int __PropertyId = 0) : __mID(__PropertyId)
	{
		 __mParent = parent;
	}

	void set() { __mParent->PropertyChanged(__mID); }
};
class B
{
	const Base* __mParent;
	int __mID;

public:
	B(const Base* parent = NULL, int __PropertyId = 0) : __mID(__PropertyId)
	{
		 __mParent = parent;
	}

	void set() { __mParent->PropertyChanged(__mID); }
};
class C
{
	const Base* __mParent;
	int __mID;

public:
	C(const Base* parent = NULL, int __PropertyId = 0) : __mID(__PropertyId)
	{
		 __mParent = parent;
	}

	void set() { __mParent->PropertyChanged(__mID); }
};

#endif // _____ABC___H___
