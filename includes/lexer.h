#ifndef LEXER_H_
#define LEXER_H_

#include <vector>

#include "token.h"

struct LexResult
{
    std::vector<Token> tokens;
};

class Lexer
{
    private:
        std::string src;
        int pos;
        char currentChar;
    public:
        /* Contructors */
        Lexer();
        Lexer(std::string src);

        /* Functions */
        void advance();
        LexResult makeTokens();
        
        Token makeVariable();
        Token makeEqual();
        Token makeString();
        Token makeFormattedString();
        Token makeWord();

        /* Destructors */
        ~Lexer();
};



#endif