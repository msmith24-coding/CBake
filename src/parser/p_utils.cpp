#include "../../includes/parser.h"

void Parser::advance()
{
    this->position++;
    this->currentToken = this->tokens.at(this->position);
    if(this->currentToken.getType() != TT_EOF) {
        this->nextToken = this->tokens.at(this->position + 1);
    }
}

void Parser::throwError(std::string message)
{
    std::cout << "[ERR] SyntaxError: " << message << std::endl;
    std::cout << "[ERR] SyntaxError: Line >> " << this->currentLine << std::endl;
    exit(1);
}