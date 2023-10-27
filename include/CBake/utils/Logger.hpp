#ifndef CBAKE_LOGGER_HPP_
#define CBAKE_LOGGER_HPP_

#include <string>

namespace CBake
{
    enum class LogType
    {
        CONSOLE,
        FILE,
        BOTH,
    };

    enum class LogLevel
    {
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    class Logger
    {
        private: /* Member Variables */
            LogType type;
        public: /* Constructor */
            Logger(LogType type);
            ~Logger() = default;
        public: /* Public Methods */
            void log(LogLevel level, std::string message);
        private: /* Member Methods */
            void logInfo(std::string message);
            void logWarn(std::string message);
            void logError(std::string message);
            void logFatal(std::string message);
            

    };
}

#endif