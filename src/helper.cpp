#include <helper.hpp>
#include <fstream>

using namespace CBake;

Helper::Helper() = default;
Helper::~Helper() = default;

bool Helper::doesFileExist(std::string fileName)
{
    std::ifstream file(fileName);
    return file.good();
}