#ifndef OPENPP_OBJECTS_2D_SDL2_EXCEPTIONS_FILE_ERROR_H_
#define OPENPP_OBJECTS_2D_SDL2_EXCEPTIONS_FILE_ERROR_H_

/********************************************\
 * Date: 18.01.2015
 * Author: Stefan Kreiner
 * Usage: FileIO Exceptions
 *
 * --------------------------------------------------
 * NOTES:
 *  - Not Tested
 *  - Not Finished!
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

class ExFileError : public std::exception
{
public:
	ExFileError(const std::string& FileName);
	ExFileError(const std::string& FileName, const std::string& Error);
	const char* what() const noexcept;
private:
	std::string mFileName;
	std::string mWhat;
};

} // Exceptions
} // SDL2
} // Objects2D
} // Objects
} // Openpp

#include "ExFileError.inl"

#endif // OPENPP_OBJECTS_2D_SDL2_EXCEPTIONS_FILE_ERROR_H_
