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

#include "../../includes/token.h"

// +
// | Sets up a token without a value.
// +
Token::Token(TokenType type_)
{
    this->type = type_;
}

// +
// | Sets up a token with a value.
// +
Token::Token(TokenType type_, std::string value_)
{
    this->type = type_;
    this->value = value_;
}

// +
// | Returns a formatted string to display
// | the token in a nice way.
// +
std::string Token::asString()
{
    if(!this->value.empty()) {
        return "[" + TokenAsString(this->type) + ":" + this->value + "]";
    }
    return "[" + TokenAsString(this->type) + "]";
}

// +
// | Returns the type.
// +
TokenType Token::getType()
{
    return this->type;
}

// +
// | Returns the value only if there
// | is a value to return. 
// +
std::string Token::getValue()
{
    if(!this->value.empty()) {
        return this->value;
    }
    return "NULL";
}

/* Unused */
Token::Token() {}
Token::~Token() {}