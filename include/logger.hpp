#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <string>

namespace CBake
{

    class Logger
    {

    public: // Constructors
        Logger();
        ~Logger();

    public: // Static Methods
        static void logInfo(std::string message);
        static void logError(std::string error, std::string message);
        
    };

} 


#endif