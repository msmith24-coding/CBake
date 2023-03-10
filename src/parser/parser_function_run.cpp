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
#include <iostream>

std::string Parser::makeRunFunction()
{
    this->advance();
    if(this->currentToken.getType() != TokenType::LPAREN) {
        std::cout << "Expected '('" << std::endl;
        exit(1);
    }

    this->advance();
    std::string result = this->makeString(TokenType::RPAREN);

    if(this->currentToken.getType() != TokenType::END_OF_LINE) {
        std::cout << "Expected ';'" << std::endl;
        exit(1);
    }

    this->advance();
    return result;

}