#ifndef OPENPP_OBJECTS_PROPERTIES_TEST_LTYPE_HPP_
#define OPENPP_OBJECTS_PROPERTIES_TEST_LTYPE_HPP_

#include "../OType.tpp"
#include <string>
#include <vector>
#include <iostream>

namespace Openpp
{
namespace Objects
{
namespace Properties
{
namespace Test
{

template <typename T>
class Object : public OObject
{
public:
	Object(OObject* const _pParent=nullptr):
		OObject(_pParent),
		property(this),
		changed(false),
		success(true)
	{}

    OType<T> property;
	bool changed;
	bool success;

protected:
	virtual void ChildChanged(int _childId)
	{
		changed = true;

        OObject::ChildChanged(); // should do nothing
	}
};

template <typename T>
void Test(bool& success, std::string name, bool term, Object<T>& obj, bool plannedResult)
{
    success &= term;
	std::cout << name << " Test: " << ((term)?"success":"ERROR") << std::endl;
    obj.success &= (obj.changed==plannedResult);
    obj.changed = false;
}
bool OTypeAndPropertyTest(std::string& rString)
{
	rString = "OTypeAndPropertyTest: ";
	std::cout << rString << std::endl;
	bool success = true;
    Object<int> obj;

    OType<int> value = 5;
    Test(success, "move", value == 5, obj, false);

	/// set
    obj.property.set(5, false);
    Test(success, "set", (obj.property==5), obj, false);

    Test(success, "operator()", (obj.property==5), obj, false);
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

	std::cout << "ChildChangedTest: " << (obj.success?"success":"ERROR")<< std::endl;

	return success && obj.success;
}

bool OTypeTest(std::string& rString)
{
	rString = "Sources/include/Objects/Properties/OType.tpp";
	bool success = true;

	std::cout << "Testing: " << rString << std::endl;
	std::vector< bool (*)(std::string&) > functions;
	functions.push_back(&OTypeAndPropertyTest);

	std::vector<std::string> Names;
	std::string Name;
	std::vector< bool > Results;

	for(int i = 0; i < functions.size(); i++)
	{
		Results.push_back(functions[i](Name));
		Names.push_back(Name);
		success &= Results.back();

		std::cout << std::endl;
	}

	std::cout << "Function Summary:" << std::endl;
	for(int i = 0; i < Results.size(); ++i)
	{
		std::cout << Names[i];
		if(Results[i])
			std::cout << "success";
		else
			std::cout << "ERROR!";
		std::cout << std::endl;
	}
	return success;
}

}
}
}
}

#endif // OPENPP_OBJECTS_PROPERTIES_TEST_LVECTOR_HPP_
