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

#include "../../includes/parser.h"

void Parser::advance()
{
    this->position++;
    this->currentToken = this->tokens.at(this->position);
    if(this->currentToken.getType() != TokenType::END_OF_FILE) {
        this->nextToken = this->tokens.at(this->position + 1);
    }
}

void Parser::throwError(std::string message)
{
    std::cout << "[ERR] ParserError: " << message << std::endl;
    std::cout << "[ERR] ParserError: Line >> " << this->currentLine << std::endl;
    exit(1);
}