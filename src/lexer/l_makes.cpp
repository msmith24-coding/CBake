#include "../../includes/lexer.h"

// +
// | Builds the variable name.
// | Returns a variable token with the value of the name.
// +
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

// + 
// | Checks if the next character is also an equal sign.
// | Return the EQEQ or EQ based if it is == or =
// + 
Token Lexer::makeEqual() 
{
    this->advance();
    if(this->currentChar == '=') {
        return Token(TT_EQEQ);
    }
    return Token(TT_EQ);
}

// +
// | Loops until the character is a quote.
// | Adds any character found between the two quotes.
// | Returns a String token with the value it built between the quotes.
// +
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

// + 
// | Loops while the character is valid.
// | Build a word if it's valid.
// | Check if it is a key or built in func.
// | Return the type.
// +
Token Lexer::makeWord()
{
    std::string word;
    while((isalpha(this->currentChar) || this->currentChar == '_') && this->currentChar != ' ') { /* Is the character valid. */
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

    // It's an identified.
    return Token(TT_ID, word);

}

// +
// | Loops until it is no longer a number or  decimal.
// | Checks if there is a decimal -> return a float or
// | return an int.
// +
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
