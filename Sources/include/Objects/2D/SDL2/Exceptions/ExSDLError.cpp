#include "ExSDLError.hpp"

namespace Openpp {

namespace Objects {
namespace SDL2 {

ExSDLError::ExSDLError(const std::string Problem, const std::string Error)
	: mWhat(Problem + ": " + Error)
{
}

const char* ExSDLError::what() const noexcept
{
	return mWhat.c_str();
}

} // SDL2

} // Objects
} // Openpp
