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

// +
// | A variable type that has multiple
// | string values. A list combines all the
// | values into a singular string. 
// +
std::vector<std::string> Parser::makeStringList()
{
    std::vector<std::string> result;
    while(this->currentToken.getType() != TokenType::RBRACKET) {
        if(this->nextToken.getType() == TokenType::RBRACKET) {
            result.push_back(this->makeStringArg(TokenType::RBRACKET));
        } 
        else if(this->nextToken.getType() == TokenType::COMMA) {
            result.push_back(this->makeStringArg(TokenType::COMMA));
            this->advance();
        } 
        else if(this->currentToken.getType() == TokenType::NEW_LINE) {
            this->currentLine++;
            this->advance();
        }
        else if(this->nextToken.getType() == TokenType::NEW_LINE) {
            result.push_back(this->makeStringArg(TokenType::NEW_LINE));
            this->advance();
        } else {
            this->throwError("Expected ',' or ']'");
        }
    }
    return result;
}