/**
 * CBake is an open source project used as a build tool for C/C++ projects.
 * Copyright (C) 2023  CBake Foundation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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

    return Token(TokenType::VAR, varName);
}

// + 
// | Checks if the next character is also an equal sign.
// | Return the EQEQ or EQ based if it is == or =
// + 
Token Lexer::makeEqual() 
{
    this->advance();
    if(this->currentChar == '=') {
        return Token(TokenType::EQEQ);
    }
    return Token(TokenType::EQ);
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
    return Token(TokenType::STR, str);
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
        return Token(TokenType::KEY, word);
    }

    if(isFunction) {
        return Token(TokenType::FUNC, word);
    }

    // It's an identified.
    return Token(TokenType::ID, word);

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
        return Token(TokenType::FLOAT, num);
    }
    return Token(TokenType::INT, num);
}
