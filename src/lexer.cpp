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
void Lexer::advance() /* Advances to the next character. */
{
    this->pos++;
    if(this->pos < this->src.length()) { /* Checks if the pos is within the size of the source. */
        this->currentChar = this->src.at(this->pos); // <-- Update the current character.
        return;
    }
    this->currentChar = 0; 
}

LexResult Lexer::makeTokens() /* Generates Tokens. */
{
    std::vector<Token> tokens;
    LexResult result;

    while(this->currentChar != 0) { /* Loop until no more characters. */
        if(this->currentChar == ' ' || this->currentChar == '\t') { /* Ignore spaces and tabs */
            this->advance();
        }
        else if(this->currentChar == '\n') { /* New line Token */
            tokens.push_back(Token(TT_NL));
            this->advance();
        }
        else if(this->currentChar == ';') { /* Checks if the currentChar is a certain token. */
            tokens.push_back(Token(TT_EOL)); // <-- Adds the token to a tokens vector.
            this->advance(); // <-- Advance to next character.
        }
        else if(this->currentChar == ':') {
            tokens.push_back(Token(TT_THEN));
            this->advance();
        }
        else if(this->currentChar == '+') {
            tokens.push_back(Token(TT_PLUS));
            this->advance();
        }
        else if(this->currentChar == ',') {
            tokens.push_back(Token(TT_COMMA));
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
    /* Checks if the character is valid and is not a space. */
    while((isalpha(this->currentChar) || this->currentChar == '_') && (this->currentChar != ' ')) {
        varName += this->currentChar; // <-- Adds to the varName
        this->advance();
    }

    return Token(TT_VAR, varName); // <-- Returns the result.
}

Token Lexer::makeEqual() /* Returns if it is a = or == */
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

    while(this->currentChar != '"') { /* Loops until it reaches the end of the string. */
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

    while(this->currentChar != '`') { /* Loops until it reaches the end of the string. */
        str += this->currentChar;
        this->advance();
    }

    this->advance();
    return Token(TT_FSTR, str);
}

Token Lexer::makeWord()
{
    std::string word;
    while(isalpha(this->currentChar) || this->currentChar == '_') { /* Is the character valid. */
        word += this->currentChar;
        this->advance();
    }

    bool isKeyword = std::find(keywords.begin(), keywords.end(), word) != keywords.end();
    bool isFunction = std::find(functions.begin(), functions.end(), word) != functions.end();

    /* Is a keyword? */
    if(isKeyword) {
        return Token(TT_KEY, word);
    }

    /* Is a function? */
    if(isFunction) {
        return Token(TT_FUNC, word);
    }

    // It's an identified.
    return Token(TT_ID, word);

}

/* Unused */
Lexer::Lexer() {}
Lexer::~Lexer() {}
