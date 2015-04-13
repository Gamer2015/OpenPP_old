#ifndef OPENPP_OBJECTS_LOBJECT_HPP_
#define OPENPP_OBJECTS_LOBJECT_HPP_

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

namespace Openpp
{
namespace Objects
{

class OObject
{
public:
    OObject(OObject* const _pParent = nullptr) :
		_mpParent(_pParent),
		_mChildrenCount(0),
		_mChildId(-1) // id() with no parent
	{
		if(parent() != nullptr)
			_mChildId = parent()->GenerateChildId();
	}

	int id() const { return _mChildId; }

protected:
    OObject* const parent() const { return _mpParent; }
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
    OObject* const _mpParent;
	int _mChildId;
    mutable int _mChildrenCount;
};

} // Objects
} // Openpp

namespace OO = Openpp::Objects;

#endif // OPENPP_OBJECTS_LOBJECT_HPP_
