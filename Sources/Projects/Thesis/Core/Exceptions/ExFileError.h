#ifndef ___EX_FILE_ERROR__H___
#define ___EX_FILE_ERROR__H___

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

namespace Core
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
    }
}

#endif // ___EX_FILE_ERROR__H___
