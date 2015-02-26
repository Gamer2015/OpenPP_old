#ifndef LIBREPP_OBJECTS_LOBJECT_H_
#define LIBREPP_OBJECTS_LOBJECT_H_

/********************************************\
 * usage: base class for all objects
 * date: 20th of February 2015
 * author: Stefan Kreiner
 * _______________________________________________
 *
 * notes:
 *  - not tested
 *
\********************************************/

namespace Librepp
{
namespace Objects
{

class LObject
{
public:
	LObject(LObject* const _pParent = nullptr) :
		_mpParent(_pParent),
		_mChildrenCount(0),
		_mChildId(-1) // id() with no parent
	{
		if(parent() != nullptr)
			_mChildId = parent()->GenerateChildId();
	}

	int id() const { return _mChildId; }

protected:
	LObject* const parent() const { return _mpParent; }
	int selfId() const { return 0; }
	int GenerateChildId() const { return ++_mChildrenCount; }

	virtual void ChildChanged(int _childId)
	{
		if(parent() != nullptr)
			parent()->ChildChanged(id());
	}
	virtual void ChildChanged() const
	{
		if(parent() != nullptr)
			parent()->ChildChanged(id());
	}

private:
	LObject* const _mpParent;
	int _mChildId;
	mutable int _mChildrenCount;
};

} // Objects
} // Librepp

#endif // LIBREPP_OBJECTS_LOBJECT_H_
