#include <logger.hpp>
#include <iostream>

using namespace CBake;

Logger::Logger() = default;
Logger::~Logger() = default;

void Logger::logInfo(std::string message)
{
    std::cout << "[INFO] : " << message << std::endl;
}

void Logger::logError(std::string error, std::string message)
{
    std::cerr << "[ERROR] | " << error << " | : " << message << std::endl;
}
