#ifndef LEXER_H_
#define LEXER_H_

#include <vector>
#include <algorithm>
#include <iostream>

#include "token.h"
#include "tokentypes.h"
#include "keywords.h"
#include "functions.h"

struct LexResult
{
    std::vector<Token> tokens;
};

class Lexer
{
    private:
        std::string src;
        size_t pos;
        int lineCount;
        char currentChar;
    public:
        /* Contructors */
        Lexer();
        Lexer(std::string src_);

        /* Functions */
        void advance();
        void throwError(std::string message);
        LexResult buildTokens();
        
        Token makeVariable();
        Token makeEqual();
        Token makeString();
        Token makeWord();
        Token makeNumber();

        /* Destructors */
        ~Lexer();
};



#endif