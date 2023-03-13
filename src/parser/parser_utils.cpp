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
#include <parser.h>

void Parser::advance()
{
    this->pos++;
    this->currentToken = this->tokens.at(this->pos);
    if(this->currentToken.getType() != TokenType::END_OF_FILE) {
        this->nextToken = this->tokens.at(this->pos + 1);
        if(this->isNewLineToken()) {
            this->currentLine++;
        }
    }
}

void Parser::nextLine()
{
    this->advance();
}

std::string Parser::makeString(TokenType endTokenType)
{
    std::string value;
    while(this->currentToken.getType() != endTokenType) {
        if(this->currentToken.getType() == TokenType::END_OF_FILE) {
            std::cout << "Missing '\"'" << std::endl;
            exit(1);
        }
        if(this->currentToken.getType() == TokenType::STR) {
            value += this->currentToken.getValue();
            this->advance();
        }
        else if(this->currentToken.getType() == TokenType::ID) {
            if(this->constSymbols.count(this->currentToken.getValue())) {
                value += this->constSymbols.at(this->currentToken.getValue());
                this->advance();
            }
            else if(this->varSymbols.count(this->currentToken.getValue())) {
                value += this->varSymbols.at(this->currentToken.getValue());
                this->advance();
            } else {
                std::cout << "Unknown symbol" << std::endl;
                exit(1);
            }
        }
        else if(this->currentToken.getType() == TokenType::PLUS) {
            this->advance();
        }
    }
    this->advance();
    return value;
}
