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

#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

#include <tokentype.h>

class Token
{
    private:
        TokenType type;
        std::string value;
    public:
        Token(TokenType p_type);
        Token(TokenType p_type, std::string p_value);

        std::string asString();

        TokenType getType();
        std::string getValue();

        Token();
        ~Token();
};


#endif