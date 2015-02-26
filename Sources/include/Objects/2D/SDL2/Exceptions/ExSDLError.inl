#include "ExSDLError.hpp"

namespace Librepp
{
namespace Objects
{
namespace Objects2D
{
namespace SDL2
{
namespace Exceptions
{

ExSDLError::ExSDLError(const std::string Problem, const std::string Error)
	: mWhat(Problem + ": " + Error)
{
}

const char* ExSDLError::what() const noexcept
{
	return mWhat.c_str();
}

} // Exceptions
} // SDL2
} // Objects2D
} // Objects
} // Librepp
