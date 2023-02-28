#include "../../includes/lexer.h"


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

Token Lexer::makeNumber()
{
    std::string num;
    bool isFloat = false;
    while(isdigit(this->currentChar) || this->currentChar == '.') {
        if(this->currentChar == '.') {
            if(isFloat) {
                this->throwError("Too many decimals.");
            }
            isFloat = true;
            num += '.';
        } else {
            num += this->currentChar;
        }
        this->advance();
    }
    if(isFloat) {
        return Token(TT_FLOAT, num);
    }
    return Token(TT_INT, num);
}
