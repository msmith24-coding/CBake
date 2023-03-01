#include "../../includes/parser.h"

std::vector<std::string> Parser::makeRunFunc() 
{
    std::vector<std::string> result;

    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {
        this->advance();

        std::string cmd = this->makeStringArg(TokenType::RPAREN);
        if(cmd.empty()) {
            this->throwError("run -> (cmd).");
        }

        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
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