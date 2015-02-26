#include "ExFileError.h"
#include "../Logger.h"

typedef Core::Logger Logger;

namespace Core
{
    namespace Exceptions
    {

        ExFileError::ExFileError(const std::string& FileName)
            : mFileName(FileName)
        {
            mWhat = "File Error Occured (" + mFileName + ")";
            Logger::LogMessage(Core::LogLevel::Error, mWhat);
        }

        ExFileError::ExFileError(const std::string& FileName, const std::string& Error)
            : mFileName(FileName)
        {
            mWhat = "File Error Occured (" + mFileName + "): " + Error;

            Logger::LogMessage(Core::LogLevel::Error, mWhat);
        }

        const char* ExFileError::what() const noexcept
        {
            return mWhat.c_str();
        }
    }
}
