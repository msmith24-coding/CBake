#include "../../includes/parser.h"

std::string Parser::makeDelFunc()
{
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {
        this->advance();
        std::string arg0 = this->makeStringArg(TokenType::RPAREN);
        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();

            #ifdef _WIN32
                return "del " + arg0;
            #endif

            #ifdef __APPLE__
                return "rm -rf " + arg0;
            #endif

            #ifdef __linux__
                return "rm -rf " + arg0;
            #endif

        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return "NULL";
}