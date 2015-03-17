#ifndef OPENPP_OBJECTS_ISCREEN_H_
#define OPENPP_OBJECTS_ISCREEN_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Screen Interface
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

namespace Openpp
{
namespace Objects
{

class IScreen
{
	friend class ScreenPointer;

public:
	/// Handle inputs of Screen
	virtual void HandleInputs() = 0;

	/// Update screen
	virtual void Update() = 0;

	/// Render screen
	virtual void Render() = 0;

protected:
	/// Called when leaving the Screen
	virtual void Leave() = 0;

	/// Called when entering the Screen
	virtual void Enter() = 0;
};


class ScreenPointer
{
public:
	ScreenPointer() : _mpCurrent(nullptr) { }

	/// Method to change Screens
	void operator=(IScreen* _screen)
	{
		if(_mpCurrent != nullptr)
			_mpCurrent->Leave();

		_mpCurrent = _screen;

		if(_mpCurrent != nullptr)
			_mpCurrent->Enter();
	}

	IScreen* operator->() { return _mpCurrent; }

private:
	IScreen* _mpCurrent;
};

} // Objects
} // Openpp

#endif // OPENPP_OBJECTS_ISCREEN_H_
