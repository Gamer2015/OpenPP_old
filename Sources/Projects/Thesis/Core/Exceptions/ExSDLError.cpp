#include "ExSDLError.h"
#include "../Logger.h"

typedef Core::Logger Logger;

namespace Core
{
    namespace Exceptions
    {

        ExSDLError::ExSDLError(const std::string Problem, const std::string Error)
            : mWhat(Problem + ": " + Error)
        {
            Logger::LogMessage(Core::LogLevel::Error, mWhat);
        }

        const char* ExSDLError::what() const noexcept
        {
            return mWhat.c_str();
        }
    }
}
