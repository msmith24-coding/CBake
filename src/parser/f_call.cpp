#include "../../includes/parser.h"

std::string Parser::makeCallFunc()
{
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {
        this->advance();
        std::string arg0 = this->makeStringArg(TokenType::RPAREN);
        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            return arg0;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return "NULL";
}