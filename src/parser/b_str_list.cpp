#include "../../includes/parser.h"

std::vector<std::string> Parser::makeStringList()
{
    std::vector<std::string> result;
    while(this->currentToken.getType() != TT_RBRACKET) {
        if(this->nextToken.getType() == TT_RBRACKET) {
            result.push_back(this->makeStringArg(TT_RBRACKET));
        } 
        else if(this->nextToken.getType() == TT_COMMA) {
            result.push_back(this->makeStringArg(TT_COMMA));
            this->advance();
        } 
        else if(this->currentToken.getType() == TT_NL) {
            this->currentLine++;
            this->advance();
        }
        else if(this->nextToken.getType() == TT_NL) {
            result.push_back(this->makeStringArg(TT_NL));
            this->advance();
        } else {
            this->throwError("Expected ',' or ']'");
        }
    }
    return result;
}