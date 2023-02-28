#include "../../includes/parser.h"

/*
    run(command : string);
*/
std::vector<std::string> Parser::makeRunFunc() 
{
    std::vector<std::string> result;

    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {
        this->advance();

        std::string arg0 = this->makeStringArg(TT_RPAREN);

        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
            this->advance();
            result.push_back(arg0);
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return result;
}