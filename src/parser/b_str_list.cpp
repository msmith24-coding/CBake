#include "../../includes/parser.h"

std::vector<std::string> Parser::makeStringList()
{
    std::vector<std::string> result;
    while(this->currentToken.getType() != TokenType::RBRACKET) {
        if(this->nextToken.getType() == TokenType::RBRACKET) {
            result.push_back(this->makeStringArg(TokenType::RBRACKET));
        } 
        else if(this->nextToken.getType() == TokenType::COMMA) {
            result.push_back(this->makeStringArg(TokenType::COMMA));
            this->advance();
        } 
        else if(this->currentToken.getType() == TokenType::NEW_LINE) {
            this->currentLine++;
            this->advance();
        }
        else if(this->nextToken.getType() == TokenType::NEW_LINE) {
            result.push_back(this->makeStringArg(TokenType::NEW_LINE));
            this->advance();
        } else {
            this->throwError("Expected ',' or ']'");
        }
    }
    return result;
}