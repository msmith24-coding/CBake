#include "../../includes/parser.h"

std::string Parser::makeStringArg(TokenType endTokenType)
{
    std::string result;
    while(this->currentToken.getType() != endTokenType) {
        if(this->currentToken.getType() == TokenType::STR) {
            result += this->currentToken.getValue();
            this->advance();
        }
        else if(this->currentToken.getType() == TokenType::VAR) {
            if(this->varSymbols.count(this->currentToken.getValue())) {
                if(std::holds_alternative<std::string>(this->varSymbols.at(this->currentToken.getValue()))) {
                    result += std::get<std::string>(this->varSymbols.at(this->currentToken.getValue()));
                } else {
                    this->throwError("Invalid type '" + TokenAsString(this->currentToken.getType()) + "'");
                }
                this->advance();
            } else {
                this->throwError("Unknown variable '" + this->currentToken.getValue() + "'");
            }
        }
        else if(this->isKeyToken("null")) {
            result += "";
            this->advance();
        }
        else if(this->currentToken.getType() == TokenType::PLUS) {
            result += "";
            this->advance();
        } else {
            this->throwError("Expected '" + TokenAsString(endTokenType) + "'");
        }
    }
    return result;
}