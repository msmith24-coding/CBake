#include <CBake/utils/Logger.hpp>

#include <iostream>
#include <vector>

void outputHelp();
void checkForUpdate(CBake::Logger logger);
void outputVersion();

int main(int argc, char* argv[])
{
    CBake::Logger logger(CBake::LogType::CONSOLE);

    std::vector<std::string> args;
    for(int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    for(const std::string & arg : args) {
        if(arg == "--help" || arg == "-h") {
            outputHelp();
            return 0;
        } else if(arg == "--update" || arg == "-u") {
            checkForUpdate(logger);
        } else if(arg == "--version" || arg == "-v") {
            outputVersion();
            return 0;
        } else {
            logger.log(CBake::LogLevel::FATAL, "Unrecognized argument: " + arg + ".");
            return 1;
        }
    }

    return 0;
}

void outputHelp()
{
    std::cout << "Usage: cbake [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --help, -h    | Displays this help message." << std::endl;
    std::cout << "  --update, -u  | Checks if there is a newer version of CBake." << std::endl;
    std::cout << "  --version, -v | Displays the version of CBake." << std::endl;
}

void checkForUpdate(CBake::Logger logger)
{
    logger.log(CBake::LogLevel::ERROR, "Checking for updates is currently not supported.");
}

void outputVersion()
{
    std::cout << "CBake v1.0.0" << std::endl;
    std::cout << "License: GPL-3.0 License" << std::endl;
    std::cout << "GitHub Repository: https://github.com/msmith24-coding/CBake" << std::endl;
    std::cout << "Major Contributors:" << std::endl;
    std::cout << "  - Michael Smith (msmith@codecellgames.com)" << std::endl;

    std::cout << std::endl;
}