#include <CBake/utils/Logger.hpp>

#include <cstdlib>
#include <iostream>

namespace CBake
{
    //
    //  Constructor
    //
    Logger::Logger(LogType type)
    {
        this->type = type;
    }

    //
    //  Public Methods
    //
    void Logger::log(LogLevel level, std::string message)
    {
        switch(level) {
            case LogLevel::INFO: 
                this->logInfo(message);
                break;
            case LogLevel::WARN:
                this->logWarn(message);
                break;
            case LogLevel::ERROR:
                this->logError(message);
                break;
            case LogLevel::FATAL:
                this->logFatal(message);
                break;
        }
    }

    //
    //  Utility methods
    //
    void Logger::logInfo(std::string message)
    {
        if(this->type == LogType::CONSOLE) {
            std::cout << "[INFO] : " << message << std::endl;
        }
    }

    void Logger::logWarn(std::string message)
    {
        if(this->type == LogType::CONSOLE) {
            std::cout << "[WARN] : " << message << std::endl;
        }
    }

    void Logger::logError(std::string message)
    {
        if(this->type == LogType::CONSOLE) {
            std::cerr << "[ERROR] : " << message << std::endl;
        }
    }

    void Logger::logFatal(std::string message)
    {
        if(this->type == LogType::CONSOLE) {
            std::cerr << "[FATAL] : " << message << std::endl;
        }
        exit(1);
    }

}