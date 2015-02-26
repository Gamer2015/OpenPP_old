#include <iostream>

template <typename T>
class Vector2
{
public:
	Vector2() : _mX(0), _mY(0) {}
	Vector2(T _x, T _y) { set(_x, _y); }

	void set(T _x, T _y) { _mX = _x; _mY = _y; }

	T x() const { return _mX; }
	T y() const { return _mY; }

private:
	T _mX;
	T _mY;
};

class LObject
{
public:
	LObject(LObject* parent = nullptr, int PropertyId = -1) :
		_mParent(parent),
		_mId(PropertyId)
	{ }

	virtual void PropertyChanged(int _propertyId)
	{
		std::cout << _propertyId << std::endl;
	}

protected:
	LObject* const parent() const { return _mParent; }
	int id() const { return _mId; }

private:
	LObject* _mParent;
	int _mId;
};

class Property : protected LObject
{
public:
	Property(LObject* parent = nullptr, int PropertyId = -1) :
		LObject(parent, PropertyId)
	{}
};

template <typename T>
class Position : protected Property
{
public:
	Position(LObject* parent = nullptr, int PropertyId = -1) :
		Property(parent, PropertyId)
	{}
	Position(T _x, T _y, LObject* parent = nullptr, int PropertyId = -1) :
		Property(parent, PropertyId),
		_mPosition(_x, _y)
	{}

	void set(T _x, T _y)
	{
		_mPosition.set(_x, _y);

		if(parent() != nullptr)
			parent()->PropertyChanged(id());
	}

	Vector2<T> operator()() const { return _mPosition; }

private:
	Vector2<T> _mPosition;
};

template <typename T>
class Origin : protected Property
{
public:
	Origin(LObject* parent = nullptr, int PropertyId = -1) :
		Property(parent, PropertyId)
	{}
	Origin(T _x, T _y, LObject* parent = nullptr, int PropertyId = -1) :
		Property(parent, PropertyId),
		_mOrigin(_x, _y)
	{}

	void set(T _x, T _y)
	{
		_mOrigin.set(_x, _y);

		if(parent() != nullptr)
			parent()->PropertyChanged(id());
	}

	Vector2<T> operator()() const { return _mOrigin; }

private:
	Vector2<T> _mOrigin;
};

class Angle : protected Property
{
public:
	Angle(LObject* parent = nullptr, int PropertyId = -1) :
		Property(parent, PropertyId)
	{}
	Angle(float __Angle, LObject* parent = nullptr, int PropertyId = -1) :
		Property(parent, PropertyId),
		_mAngle(__Angle)
	{}

	void set(float __Angle)
	{
		_mAngle = __Angle;

		if(parent() != nullptr)
			parent()->PropertyChanged(id());
	}

	float operator()() const { return _mAngle; }

private:
	float _mAngle;
};

template <typename T>
class BaseObject2D : public LObject
{
public:
	BaseObject2D() :
		position(this, SetId()),
		origin(this, SetId()),
		angle(this, SetId())
	{
	}

	Position<T> position;
	Origin<T> origin;
	Angle angle;

	virtual void PropertyChanged(int _propertyId) { std::cout << _propertyId << std::endl; }

private:
	int _mPropertyCount;
	int SetId() { return _mPropertyCount++; }
};

int main(void)
{
	BaseObject2D<float> obj;
	obj.position.set(50, 20);
	obj.origin.set(-1, 1);
	obj.angle.set(180);

	return 0;
}
