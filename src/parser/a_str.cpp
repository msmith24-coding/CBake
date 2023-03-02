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
// | Loops and add valid arguments to a string
// | until it reaches a certain end token.
// +
std::string Parser::makeStringArg(TokenType endTokenType)
{
    std::string result;
    while(this->currentToken.getType() != endTokenType) {
        if(this->currentToken.getType() == TokenType::STR) {
            result += this->currentToken.getValue();
            this->advance();
        }
        else if(this->currentToken.getType() == TokenType::VAR) {
            if(this->varSymbols.count(this->currentToken.getValue())) {
                if(std::holds_alternative<std::string>(this->varSymbols.at(this->currentToken.getValue()))) {
                    result += std::get<std::string>(this->varSymbols.at(this->currentToken.getValue()));
                } else {
                    this->throwError("Invalid type '" + TokenAsString(this->currentToken.getType()) + "'");
                }
                this->advance();
            } else {
                this->throwError("Unknown variable '" + this->currentToken.getValue() + "'");
            }
        }
        else if(this->isKeyToken("null")) {
            result += "";
            this->advance();
        }
        else if(this->currentToken.getType() == TokenType::PLUS) {
            result += "";
            this->advance();
        } else {
            this->throwError("Expected '" + TokenAsString(endTokenType) + "'");
        }
    }
    return result;
}