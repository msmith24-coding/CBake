#include "../../includes/functions.h"

std::vector<std::string> functions;

void setupFunctions()
{
    /* Adds a keyword into the keywords vector. */
    functions.push_back("call");
    functions.push_back("del");
    functions.push_back("run");
    functions.push_back("print");
    functions.push_back("simple_compile");
}
