#ifndef LIBREPP_OBJECTS_PROPERTIES_TEST_LTYPE_HPP_
#define LIBREPP_OBJECTS_PROPERTIES_TEST_LTYPE_HPP_

#include "../LType.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace Librepp
{
namespace Objects
{
namespace Properties
{
namespace Test
{

template <typename T>
class Object : public LObject
{
public:
	Object(LObject* const _pParent=nullptr):
		LObject(_pParent),
		property(this),
		changed(false),
		success(true)
	{}

	LType<T> property;
	bool changed;
	bool success;

protected:
	virtual void ChildChanged(int _childId)
	{
		changed = true;

		LObject::ChildChanged(); // should do nothing
	}
};

template <typename T>
void Test(bool& success, std::string name, bool term, Object<T>& obj, bool plannedResult)
{
	success &= term;
	std::cout << name << " Test: " << ((term)?"1":"ERROR") << std::endl;
	obj.success &= (obj.changed==plannedResult);
	obj.changed = false;
}
bool LTypeAndPropertyTest()
{
	std::cout << "LTypeAndPropertyTest:\n";
	bool success = true;
	Object<int> obj;

	/// set
	obj.property.set(5, false);
	Test(success, "set", (obj.property()==5), obj, false);

	Test(success, "operator()", (obj.property()==5), obj, false);
	Test(success, "operator-", (+obj.property==5), obj, false);
	Test(success, "operator+", (-obj.property==-5), obj, false);
	Test(success, "operatorU()", ((float)obj.property==5.0), obj, false);

	/// arithmetic
	Test(success, "operator=", ((obj.property = 5) == 5), obj, true);
	Test(success, "operator+", ((obj.property + 5) == 10), obj, false);
	Test(success, "operator-", ((obj.property - 5) == 0), obj, false);
	Test(success, "operator*", ((obj.property * 5) == 25), obj, false);
	Test(success, "operator/", ((obj.property / 5) == 1), obj, false);
	Test(success, "operator%", ((obj.property % 5) == 0), obj, false);
	Test(success, "operator++", (obj.property++ == 5), obj, true);
	Test(success, "++operator", (++obj.property == 7), obj, true);
	Test(success, "operator--", (obj.property-- == 7), obj, true);
	Test(success, "--operator", (--obj.property == 5), obj, true);

	/// comparison
	Test(success, "operator==", (obj.property == 5), obj, false);
	Test(success, "operator!=", (obj.property != 5) == false, obj, false);
	Test(success, "operator<", (obj.property < 5) == false, obj, false);
	Test(success, "operator>", (obj.property > 5) == false, obj, false);
	Test(success, "operator<=", (obj.property <= 5), obj, false);
	Test(success, "operator>=", (obj.property >= 5), obj, false);

	/// logic
	Test(success, "operator!", (!obj.property == false), obj, false);
	Test(success, "operator&&", (obj.property && 0) == false, obj, false);
	Test(success, "operator||", (obj.property || 1) == true, obj, false);

	/// bit operations
	Test(success, "operator~", (~obj.property == ~5), obj, false);
	Test(success, "operator&", (obj.property & 2) == (5 & 2), obj, false);
	Test(success, "operator|", (obj.property | 2) == (5 | 2), obj, false);
	Test(success, "operator^", (obj.property ^ 2) == (5 ^ 2), obj, false);
	Test(success, "operator<<", (obj.property << 2) == (5 << 2), obj, false);
	Test(success, "operator>>", (obj.property >> 2) == (5 >> 2), obj, false);

	/// compound assignment
	Test(success, "operator+=", (obj.property += 2) == 7, obj, true);
	Test(success, "operator-=", (obj.property -= 2) == 5, obj, true);
	Test(success, "operator*=", (obj.property *= 2) == 10, obj, true);
	Test(success, "operator/=", (obj.property /= 2) == 5, obj, true);
	Test(success, "operator<<=", (obj.property <<= 2) == (5 << 2), obj, true);
	Test(success, "operator>>=", (obj.property >>= 2) == ((5<<2) >> 2), obj, true);

	std::cout << "ChildChangedTest: " << (obj.success?"1":"ERROR")<< std::endl;

	return success && obj.success;
}

bool LTypeTest(std::string& rString)
{
	rString = "Sources/include/Objects/Properties/LType.hpp";
	bool success = true;
	std::cout << "Testing: " << rString << std::endl;
	std::vector< bool (*)() > functions;

	functions.push_back(&LTypeAndPropertyTest);

	for(int i = 0; i < functions.size(); i++)
	{
		success = success & functions[i]();
	}
	return success;
}

}
}
}
}

#endif // LIBREPP_OBJECTS_PROPERTIES_TEST_LVECTOR_HPP_
