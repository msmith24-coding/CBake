#include "../../includes/parser.h"

std::string Parser::makeStringArg(std::string endTokenType)
{
    std::string result;
    while(this->currentToken.getType() != endTokenType) {
        if(this->currentToken.getType() == TT_STR) {
            result += this->currentToken.getValue();
            this->advance();
        }
        else if(this->currentToken.getType() == TT_VAR) {
            if(this->varSymbols.count(this->currentToken.getValue())) {
                if(std::holds_alternative<std::string>(this->varSymbols.at(this->currentToken.getValue()))) {
                    result += std::get<std::string>(this->varSymbols.at(this->currentToken.getValue()));
                } else {
                    this->throwError("Invalid type '" + this->currentToken.getType() + "'");
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
        else if(this->currentToken.getType() == TT_PLUS) {
            result += "";
            this->advance();
        } else {
            this->throwError("Expected '" + endTokenType + "'");
        }
    }
    return result;
}