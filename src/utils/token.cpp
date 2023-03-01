#include "../../includes/token.h"

// +
// | Sets up a token without a value.
// +
Token::Token(TokenType type_)
{
    this->type = type_;
}

// +
// | Sets up a token with a value.
// +
Token::Token(TokenType type_, std::string value_)
{
    this->type = type_;
    this->value = value_;
}

// +
// | Returns a formatted string to display
// | the token in a nice way.
// +
std::string Token::asString()
{
    if(!this->value.empty()) {
        return "[" + TokenAsString(this->type) + ":" + this->value + "]";
    }
    return "[" + TokenAsString(this->type) + "]";
}

// +
// | Returns the type.
// +
TokenType Token::getType()
{
    return this->type;
}

// +
// | Returns the value only if there
// | is a value to return. 
// +
std::string Token::getValue()
{
    if(!this->value.empty()) {
        return this->value;
    }
    return "NULL";
}

/* Unused */
Token::Token() {}
Token::~Token() {}