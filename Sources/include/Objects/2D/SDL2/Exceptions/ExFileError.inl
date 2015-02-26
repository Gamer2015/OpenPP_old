#include "ExFileError.h"

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

ExFileError::ExFileError(const std::string& FileName)
	: mFileName(FileName)
{
	mWhat = "File Error Occured (" + mFileName + ")";
}

ExFileError::ExFileError(const std::string& FileName, const std::string& Error)
	: mFileName(FileName)
{
	mWhat = "File Error Occured (" + mFileName + "): " + Error;
}

const char* ExFileError::what() const noexcept
{
	return mWhat.c_str();
}

} // Exceptions
} // SDL2
} // Objects2D
} // Objects
} // Openpp
