#include "Logger.h"

namespace Core
{
    std::ofstream Logger::FileStream;
    std::string Logger::LogPath = "Log.txt";
    std::string Logger::LogType;
    std::time_t Logger::Time;
    struct tm Logger::TimeData;
    char Logger::Buffer[32];

    void Logger::LogMessage(const LogLevel::ELogLevel Level, const std::string &Message, const std::ios_base::openmode mode)
    {
        Time = time(0);
        TimeData = *localtime(&Time);

        sprintf(Buffer, "%.2d.%.2d.%.4d %.2d:%.2d:%.2d", TimeData.tm_yday + 1, TimeData.tm_mon + 1, TimeData.tm_year + 1900, TimeData.tm_hour, TimeData.tm_min, TimeData.tm_sec);

        switch(Level)
        {
        case LogLevel::Debug: LogType = "Debug";
            break;
        case LogLevel::Info: LogType = "Info";
            break;
        case LogLevel::Warning: LogType = "Warning";
            break;
        case LogLevel::Error: LogType = "Error";
            break;
        }

        FileStream.open(LogPath.c_str(), std::ofstream::out | std::ofstream::app);

        FileStream << Buffer << " {" << LogType << "}: " << Message << std::endl;

        FileStream.close();
    }
}
