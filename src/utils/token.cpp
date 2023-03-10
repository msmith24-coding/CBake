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

#include <token.h>

Token::Token(TokenType p_type)
{
    this->type = p_type;
}

Token::Token(TokenType p_type, std::string p_value)
{
    this->type = p_type;
    this->value = p_value;
}

std::string Token::asString()
{
    if(!this->value.empty()) {
        return "[" + tokenTypeAsString(this->type) + ":" + this->value + "]";
    }
    return "[" + tokenTypeAsString(this->type) + "]";
}

TokenType Token::getType() 
{
    return this->type;
}

std::string Token::getValue()
{
    if(!this->value.empty()) {
        return this->value;
    }
    return "NULL";
}

// +
// | Not used constructors.
// +
Token::Token() {}
Token::~Token() {}
