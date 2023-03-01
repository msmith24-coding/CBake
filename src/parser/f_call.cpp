#include "../../includes/parser.h"

// + 
// | Returns what action should be called
// | based on it's arguments.
// +
std::string Parser::makeCallFunc()
{
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {
        this->advance();
        
        // +
        // | Reads the string argument 
        // | for the action name. Returns 
        // | the action name.
        // +
        std::string action = this->makeStringArg(TokenType::RPAREN);

        // +
        // | Advances to the last token.
        // | Checks if it ends with a semi-colon.
        // | Returns the action name.
        // +
        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            return action;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return "NULL";
}