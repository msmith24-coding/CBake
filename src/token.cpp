#include "../includes/token.hpp"

Token::Token(std::string type)
{
    this->type = type;
}

Token::Token(std::string type, std::string value)
{
    this->type = type;
    this->value = value;
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