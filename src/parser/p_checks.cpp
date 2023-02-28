#include "../../includes/parser.h"

bool Parser::isKeyToken(std::string value)
{
    if(Parser::currentToken.getType() == TT_KEY) {
        return Parser::currentToken.getValue() == value;
    }
    return false;
}

bool Parser::isFuncToken(std::string func)
{
    if(Parser::currentToken.getType() == TT_FUNC) {
        return Parser::currentToken.getValue() == func;
    }
    return false;
}

bool Parser::isVarToken()
{
    return this->currentToken.getType() == TT_VAR;
}

bool Parser::isNewLineToken()
{
    return this->currentToken.getType() == TT_NL;
}