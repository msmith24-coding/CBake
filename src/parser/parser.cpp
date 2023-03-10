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

#include <parser.h>
#include <error.h>
#include <iostream>

Parser::Parser(std::vector<Token> p_tokens)
{
    this->tokens = p_tokens;
    this->pos = -1;
    this->currentLine = 1;
    this->advance();
}

std::map<std::string, std::vector<std::string>> Parser::buildTree()
{
    while(this->currentToken.getType() != TokenType::END_OF_FILE) {
        if(this->isNewLineToken()) {
            this->nextLine();
        }
        else if(this->isKeyToken()) {
            if(this->currentToken.getValue() == keywords.at(Keywords::CONST)) {
                this->makeConst();
            }
            else if(this->currentToken.getValue() == keywords.at(Keywords::DEF)) {
                this->makeDef();
            }
        } 
        else if(this->isFuncToken()) {
            Error::throwError(currentLine, "Functions must be declared in a definition.");
        }
    }
    return this->parseResult;
}

Parser::Parser() {}
Parser::~Parser() {}