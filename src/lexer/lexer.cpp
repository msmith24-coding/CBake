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
// | Sets default values for the lexer.
// | Advances to the first token.
// +
Lexer::Lexer(std::string src_)
{
    this->src = src_;
    this->pos = -1;
    this->lineCount = 1;
    this->currentChar = 0;
    this->advance();
}

// +
// | Loops while there is a character.
// | Advances after the token has been added
// | to the tokens vector.
// +
LexResult Lexer::buildTokens()
{
    std::vector<Token> tokens;
    LexResult result;

    while(this->currentChar != 0) { 
        if(this->shouldIgnoreCharacter()) { 
            this->advance();
        }
        else if(this->checkCharacter('\n')) { 
            tokens.push_back(Token(TokenType::NEW_LINE));
            this->lineCount++;
            this->advance();
        }
        else if(this->checkCharacter(';')) { 
            tokens.push_back(Token(TokenType::END_OF_LINE)); 
            this->advance(); 
        }
        else if(this->checkCharacter(':')) {
            tokens.push_back(Token(TokenType::THEN));
            this->advance();
        }
        else if(this->checkCharacter('<')) {
            tokens.push_back(Token(TokenType::LTHAN));
            this->advance();
        }
        else if(this->checkCharacter('>')) {
            tokens.push_back(Token(TokenType::GTHAN));
            this->advance();
        }
        else if(this->checkCharacter('[')) {
            tokens.push_back(Token(TokenType::LBRACKET));
            this->advance();
        }
        else if(this->checkCharacter(']')) {
            tokens.push_back(Token(TokenType::RBRACKET));
            this->advance();
        }
        else if(this->checkCharacter('+')) {
            tokens.push_back(Token(TokenType::PLUS));
            this->advance();
        }
        else if(this->checkCharacter(',')) {
            tokens.push_back(Token(TokenType::COMMA));
            this->advance();
        }
        else if(this->checkCharacter('(')) {
            tokens.push_back(Token(TokenType::LPAREN));
            this->advance();
        }
        else if(this->checkCharacter(')')) {
            tokens.push_back(Token(TokenType::RPAREN));
            this->advance();
        }
        else if(this->isVariable()) {
            tokens.push_back(this->makeVariable());
        } 
        else if(this->currentChar == '=') {
            tokens.push_back(this->makeEqual());
        } 
        else if(this->currentChar == '"') {
            tokens.push_back(this->makeString());
        }
        else if(isdigit(this->currentChar)) {

        }
        else if(isalpha(this->currentChar)) {
            tokens.push_back(this->makeWord());
        } else {
            //TODO (Michael): Implement an object for better error handling.
            std::string errorStr = "";
            errorStr += this->currentChar;
            this->throwError("Invalid character '" + errorStr + ".");
        }
    }

    tokens.push_back(Token(TokenType::END_OF_FILE));

    result.tokens = tokens;

    return result;
}

/* Unused */
Lexer::Lexer() {}
Lexer::~Lexer() {}
