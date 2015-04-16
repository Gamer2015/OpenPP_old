#include "ExFileError.hpp"

namespace Openpp {
namespace Objects {
namespace Objects2D {
namespace SDL2 {

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

} // SDL2
} // Objects2D
} // Objects
} // Openpp
