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
        size_t pos;
        int lineCount;
        char currentChar;
    public:
        /* Contructors */
        Lexer();
        Lexer(std::string src);

        /* Functions */
        void advance();
        void throwError(std::string message);
        LexResult makeTokens();
        
        Token makeVariable();
        Token makeEqual();
        Token makeString();
        Token makeWord();
        Token makeNumber();

        /* Destructors */
        ~Lexer();
};



#endif