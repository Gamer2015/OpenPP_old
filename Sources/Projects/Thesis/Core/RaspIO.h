#ifndef OPENPP_PROJECTS_THESIS_CORE_RASPIO_H_
#define OPENPP_PROJECTS_THESIS_CORE_RASPIO_H_

namespace Raspberry
{
	namespace Input
    {
        enum EButton
        {
            BUTTON_UP = 0x01,
            BUTTON_DOWN = 0x02,
            BUTTON_LEFT = 0x04,
            BUTTON_RIGHT = 0x08,

            BUTTON_A = 0x10,
            BUTTON_B = 0x20,
            BUTTON_X = 0x40,
            BUTTON_Y = 0x80,

            BUTTON_SELECT = 0x100,
            BUTTON_START = 0x200,
            BUTTON_MAIN = 0x400
        };

		class RaspIO
		{
		protected:
            static unsigned short mOldButtons;
            static unsigned short mButtons;

            static bool KeyWasPressed(EButton button);

        public:
			// Read Current Data of Buttons
			static void Read();					// Does not function properly

			static bool KeyDown(EButton button);
            static bool KeyUp(EButton button);
			static bool KeyIsPressed(EButton button);
		};
	}
}

#include "RaspIO.inl"

#endif // OPENPP_PROJECTS_THESIS_CORE_RASPIO_H_
