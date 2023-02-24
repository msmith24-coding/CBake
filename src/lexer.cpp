#include "../includes/lexer.h"
#include "../includes/tokentypes.h"
#include "../includes/keywords.h"
#include "../includes/functions.h"

#include <iostream>
#include <algorithm>

/* Constructors */
Lexer::Lexer(std::string src)
{
    this->src = src;
    this->pos = -1;
    this->currentChar = 0;
    this->advance();
}

/* Functions */
void Lexer::advance()
{
    this->pos++;
    if(this->pos < this->src.length()) {
        this->currentChar = this->src.at(this->pos);
        return;
    }
    this->currentChar = 0;
}

LexResult Lexer::makeTokens()
{
    std::vector<Token> tokens;
    LexResult result;

    while(this->currentChar != 0) {
        if(this->currentChar == ' ' || this->currentChar == '\t') {
            this->advance();
        }
        else if(this->currentChar == '\n') {
            tokens.push_back(Token(TT_NL));
            this->advance();
        }
        else if(this->currentChar == ';') {
            tokens.push_back(Token(TT_EOL));
            this->advance();
        }
        else if(this->currentChar == ':') {
            tokens.push_back(Token(TT_THEN));
            this->advance();
        }
        else if(this->currentChar == '+') {
            tokens.push_back(Token(TT_PLUS));
            this->advance();
        }
        else if(this->currentChar == '(') {
            tokens.push_back(Token(TT_LPAREN));
            this->advance();
        }
        else if(this->currentChar == ')') {
            tokens.push_back(Token(TT_RPAREN));
            this->advance();
        }
        else if(this->currentChar == '$') {
            tokens.push_back(this->makeVariable());
        } 
        else if(this->currentChar == '=') {
            tokens.push_back(this->makeEqual());
        } 
        else if(this->currentChar == '"') {
            tokens.push_back(this->makeString());
        }
        else if(this->currentChar == '`') {
            tokens.push_back(this->makeFormattedString());
        }
        else if(isalpha(this->currentChar)) {
            tokens.push_back(this->makeWord());
        } else {
            
        }
    }

    tokens.push_back(Token(TT_EOF));

    result.tokens = tokens;

    return result;
}

Token Lexer::makeVariable()
{
    this->advance();
    std::string varName;
    while((isalpha(this->currentChar) || this->currentChar == '_') && (this->currentChar != ' ')) {
        varName += this->currentChar;
        this->advance();
    }

    return Token(TT_VAR, varName);
}

Token Lexer::makeEqual()
{
    this->advance();
    if(this->currentChar == '=') {
        return Token(TT_EQEQ);
    }
    return Token(TT_EQ);
}

Token Lexer::makeString()
{
    std::string str;
    this->advance();

    while(this->currentChar != '"') {
        str += this->currentChar;
        this->advance();
    }

    this->advance();
    return Token(TT_STR, str);
}

Token Lexer::makeFormattedString()
{
    std::string str;
    this->advance();

    while(this->currentChar != '`') {
        str += this->currentChar;
        this->advance();
    }

    this->advance();
    return Token(TT_FSTR, str);
}

Token Lexer::makeWord()
{
    std::string word;
    while(isalpha(this->currentChar) || this->currentChar == '_') {
        word += this->currentChar;
        this->advance();
    }

    bool isKeyword = std::find(keywords.begin(), keywords.end(), word) != keywords.end();
    bool isFunction = std::find(functions.begin(), functions.end(), word) != functions.end();

    if(isKeyword) {
        return Token(TT_KEY, word);
    }

    if(isFunction) {
        return Token(TT_FUNC, word);
    }

    return Token(TT_ID, word);

}

/* Unused */
Lexer::Lexer() {}
Lexer::~Lexer() {}
