#include "../../includes/parser.h"

std::vector<std::string> Parser::makeRunFunc() 
{
    std::vector<std::string> result;

    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {
        this->advance();

        std::string cmd = this->makeStringArg(TT_RPAREN);
        if(cmd.empty()) {
            this->throwError("run -> (cmd).");
        }

        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
            this->advance();
            result.push_back(cmd);
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return result;
}