#include "RaspIO.h"

namespace Raspberry
{
	namespace Input
    {
    unsigned short RaspIO::mOldButtons = 0;
    unsigned short RaspIO::mButtons = 0;
        void RaspIO::Read() // Does not function properly
        {
            mOldButtons = mButtons;

            // Read data from Input Pins
		}

		bool RaspIO::KeyDown(EButton button)
		{
            if( KeyWasPressed(button) == false && KeyIsPressed(button) == true )
			{
				return true;
			}
			return false;
		}
		bool RaspIO::KeyUp(EButton button)
		{
            if( KeyWasPressed(button) == true && KeyIsPressed(button) == false )
			{
				return true;
			}
			return false;
		}

		bool RaspIO::KeyIsPressed(EButton button)
		{
            return (mButtons & button);
		}
		bool RaspIO::KeyWasPressed(EButton button)
		{
            return (mOldButtons & button);
		}
	}
}
