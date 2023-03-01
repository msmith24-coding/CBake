#include "../../includes/functions.h"

// +
// | Vector to store the function names.
// +
std::vector<std::string> functions;

// +
// | Function used to add all the function names to the functions vector.
// +
void setupFunctions()
{
    functions.push_back("call");
    functions.push_back("del");
    functions.push_back("run");
    functions.push_back("print");
    functions.push_back("simple_compile");
    functions.push_back("compile");
}
