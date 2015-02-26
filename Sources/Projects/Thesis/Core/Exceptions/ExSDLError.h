#ifndef ___EX_SDL_ERROR__H___
#define ___EX_SDL_ERROR__H___

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: SDL based Exceptions
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *
\********************************************/

#include <exception>
#include <string>

namespace Core
{
    namespace Exceptions
    {
        class ExSDLError : public std::exception
        {
        public:
            ExSDLError(const std::string Problem, const std::string Error);
            const char* what() const noexcept;

        private:
            std::string mWhat;
        };
    }
}

#endif // ___EX_SDL_ERROR__H___
