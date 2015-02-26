#ifndef ___LOGGER__H___
#define ___LOGGER__H___

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

namespace Core
{
    namespace LogLevel
    {
        enum ELogLevel
        {
            Debug,
            Info,
            Warning,
            Error
        };
    }

    class Logger
    {
    public:
        static void LogMessage(const LogLevel::ELogLevel Level, const std::string& Message, const std::ios_base::openmode mode = std::ofstream::out|std::ofstream::app);

    private:
        static std::ofstream FileStream;
        static std::string LogPath;
        static std::string LogType;
        static std::time_t Time;
        static struct tm TimeData;
        static char Buffer[32];
    };
}

#endif // ___LOGGER__H___
