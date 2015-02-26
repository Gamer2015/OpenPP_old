#ifndef ___SCREEN__H___
#define ___SCREEN__H___

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: Screen Class for Games
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

namespace Core
{
    class Screen
	{
    public:
        virtual void HandleInputs() = 0;

        virtual void Update() = 0;

        virtual void Render() = 0;
	};
}

#endif // ___C_SCREEN__H___
