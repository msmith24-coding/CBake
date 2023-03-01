#include "../../includes/lexer.h"

bool Lexer::shouldIgnoreCharacter()
{
    return this->currentChar == ' ' || this->currentChar == '\t';
}

bool Lexer::checkCharacter(char toCheck)
{
    return this->currentChar == toCheck;
}

bool Lexer::isVariable()
{
    return this->currentChar == '$';
}