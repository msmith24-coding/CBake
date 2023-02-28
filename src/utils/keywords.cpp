#include "../../includes/keywords.h"

std::vector<std::string> keywords;

void setupKeywords()
{
    /* Adds a keyword into the keywords vector. */
    keywords.push_back("action");
    keywords.push_back("end");

    /* Types */
    keywords.push_back("str");
    keywords.push_back("int");
    keywords.push_back("float");
    keywords.push_back("list");

    keywords.push_back("null");
}