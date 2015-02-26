#ifndef Openpp_OBJECTS_2D_SDL2_EXCEPTIONS_SDL_ERROR_H_
#define Openpp_OBJECTS_2D_SDL2_EXCEPTIONS_SDL_ERROR_H_

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

namespace Openpp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
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

} // Exceptions
} // SDL2
} // Objects2D
} // Objects
} // Openpp

#include "ExSDLError.inl"

#endif // Openpp_OBJECTS_2D_SDL2_EXCEPTIONS_SDL_ERROR_H_
