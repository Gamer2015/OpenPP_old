#ifndef LIBREPP_OBJECTS_TEST_LOBJECT_HPP_
#define LIBREPP_OBJECTS_TEST_LOBJECT_HPP_

#include "../LObject.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace Librepp
{
namespace Objects
{
namespace Test
{

class Object : public LObject
{
public:
	Object(LObject* const _pParent=nullptr) :
		LObject(_pParent),
		count(0),
		selfcount(0)
	{
	}

	void change() { ChildChanged(selfId()); }
	int count;
	int selfcount;

	using LObject::selfId;
	using LObject::GenerateChildId;
	using LObject::parent;

protected:
	virtual void ChildChanged(int _childId)
	{
		++count;

		if(_childId == selfId())
		{
			++selfcount;
		}
	}
};
class Object2 : public LObject
{
public:
	Object2(LObject* const _pParent=nullptr) :
		LObject(_pParent),
		count(0),
		selfcount(0),
		obj(this)
	{
	}

	void change() { ChildChanged(selfId()); }
	int count;
	int selfcount;

	Object obj;

	using LObject::selfId;
	using LObject::GenerateChildId;
	using LObject::parent;

protected:
	virtual void ChildChanged(int _childId)
	{
		++count;

		if(_childId == selfId())
		{
			++selfcount;
		}
	}
};

bool ChildChangedTest()
{
	std::cout << "ChildChangedTest: ";

	Object obj;

	int count = 10;
	for(int i = 0; i < count; ++i)
		obj.change();

	bool success = (obj.count == obj.selfcount && obj.selfcount == count);

	if(success)
	{
		std::cout << success << std::endl;
	}
	else
	{
		std::cout << "ERROR:\n\tHaving: " << obj.count << " " << obj.selfcount
				  << "\n\tWanted: " << count << " " << count << std::endl;
	}
	return success;
}

bool IdAndselfIdTest()
{
	std::cout << "IdAndselfIdTest: ";

	Object2 obj;

	bool success = (obj.obj.id() == 1) && (obj.obj.selfId() == 0) && (obj.id() == -1);

	if(success)
	{
		std::cout << success << std::endl;
	}
	else
	{
		std::cout << "ERROR:\n - Having: " << obj.obj.id() << " " << obj.obj.selfId() << obj.id()
				  << " - Wanted: " << 1 << " " << 0 << " " << -1 << std::endl;
	}
	return success;
}

bool Test(std::string& rString)
{
	rString = "Sources/include/Objects/LObject.hpp";
	bool success = true;
	std::cout << "Testing " << rString << std::endl;
	std::vector< bool (*)() > functions;

	functions.push_back(&ChildChangedTest);
	functions.push_back(&IdAndselfIdTest);

	for(int i = 0; i < functions.size(); i++)
	{
		success = success & functions[i]();
	}
	return success;
}

} // Test
} // Objects
} // Librepp


#endif
