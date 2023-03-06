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

#include <iostream>

#include <lexer.h>

// +
// | Constructor used to setup the lexer before it starts
// | building the tokens.
// +
Lexer::Lexer(std::string p_src)
{
    this->src = p_src;
    this->pos = -1;
    this->currentLine = 0;
    this->currentChar = 0;

    this->advance();
}

// +
// | The main function for building the tokens given 
// | the provided source code.
// +
LexResult Lexer::buildTokens()
{
    LexResult result;
    std::vector<Token> tokens;

    while(this->currentChar != 0) { /* Loops through every character in the source code. */
        if(this->shouldIgnoreCharacter()) {
            this->advance();
        }
        else if(this->isNewLine()) {
            tokens.push_back(Token(TokenType::NEW_LINE));
            this->nextLine();
        }
        else if(this->checkCharacter(';')) {
            tokens.push_back(Token(TokenType::END_OF_LINE));
            this->advance();
        }
        else if(this->checkCharacter(':')) {
            tokens.push_back(Token(TokenType::THEN));
            this->advance();
        }
        else if(this->checkCharacter('=')) {
            tokens.push_back(this->makeEqualToken());
            this->advance();
        }
        else if(this->isVariable()) {
            tokens.push_back(this->makeVariableToken());
        }
        else if(this->isString()) {
            tokens.push_back(this->makeStringToken());
        }
        else if(isalpha(this->currentChar)) {
            tokens.push_back(this->makeIDKeyOrFunc());   
        } else {
            std::cout << "TOKEN ERROR TODO" << std::endl;
            exit(1);
        }

    }

    /* Adds a token at the end to prevent unexpected end of file errors. */
    tokens.push_back(Token(TokenType::END_OF_FILE));

    /* Builds the result so both the tokens and error can be returned. */
    result.tokens = tokens;
    return result;

}

/* Constructors/Destructors that are not used. */
Lexer::Lexer() {}
Lexer::~Lexer() {}