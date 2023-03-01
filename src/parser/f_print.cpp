#include "../../includes/parser.h"

// + 
// | Builds the command for outputting
// | to command line.
// +
std::string Parser::makePrintFunc()
{
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {
        this->advance();
        std::string out = this->makeStringArg(TokenType::RPAREN);
        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            
            //TODO: May need to make compatible for a different OS (Michael)
            return "echo " + out;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return "NULL";
}