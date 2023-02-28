#include "../../includes/parser.h"

std::string Parser::makeCallFunc()
{
    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {
        this->advance();
        std::string arg0 = this->makeStringArg(TT_RPAREN);
        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
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