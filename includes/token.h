#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include "tokentypes.h"

class Token
{
    private:
        TokenType type;
        std::string value;
    public:
        /* Contructors */
        Token();
        Token(TokenType type_);
        Token(TokenType type_, std::string value_);

        /* Functions */
        std::string asString();

        /* Getters */
        TokenType getType();
        std::string getValue();

        /* Destructors */
        ~Token();
};

#endif