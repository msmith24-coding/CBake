#include "../../includes/token.h"

Token::Token(std::string type_)
{
    this->type = type_;
}

Token::Token(std::string type_, std::string value_)
{
    this->type = type_;
    this->value = value_;
}

/* Functions */
std::string Token::asString()
{
    if(!this->value.empty()) {
        return "[" + this->type + ":" + this->value + "]";
    }
    return "[" + this->type + "]";
}

/* Getters */
std::string Token::getType()
{
    return this->type;
}

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