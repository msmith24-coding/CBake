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

#include <lexer.h>
#include <keywords.h>
#include <functions.h>

// +
// | Checks if the next token is also an equal sign. Then
// | return a double equal token or return a single equal token.
// +
Token Lexer::makeEqualToken()
{
    if(this->src.at(this->pos + 1) == '=') {
        this->advance();
        return Token(TokenType::EQEQ);
    }
    return Token(TokenType::EQ);
}

// +
// | Checks if a the character has valid characters for a variable.
// | Loops and adds the characters to a string to build the variable name.
// +
Token Lexer::makeVariableToken()
{
    this->advance();
    std::string varName;
    while((isalpha(this->currentChar) || this->checkCharacter('_')) && (!this->checkCharacter(' '))) {
        varName += this->currentChar;
        this->advance();
    }
    return Token(TokenType::VAR, varName);
}

// +
// | Loops through all the characters until it reaches another double quote.
// +
Token Lexer::makeStringToken()
{
    this->advance();
    std::string value;

    while(!this->checkCharacter('"')) {
        value += this->currentChar;
        this->advance();
    }
    this->advance();
    return Token(TokenType::STR, value);
}

// +
// | Builds a word given certain requirements.
// | Checks if the word is a keyword or a function.
// | If it is neither, then return an identifier.
// +
Token Lexer::makeIDKeyOrFunc()
{
    std::string word;
    while((isalpha(this->currentChar) || this->checkCharacter('_')) && (!this->checkCharacter(' '))) {
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

    return Token(TokenType::ID, word);
}