#include <helper.hpp>
#include <logger.hpp>

#include <iostream>


using namespace CBake;

int main(int argc, char** argv)
{
    if(argc <= 1) {
        if(!Helper::doesFileExist("CBakefile")) {
            Logger::logError("FileNotFoundError", "No CBakefile found in current directory.");
            return 1;
        }

        

        return 0;
    }
    return 0;
}