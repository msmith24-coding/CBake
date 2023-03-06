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
#include <tokentype.h>

std::string tokenTypeAsString(TokenType p_type)
{
    switch (p_type)
    {
        case TokenType::END_OF_FILE : return "END_OF_FILE";
        case TokenType::END_OF_LINE : return "END_OF_LINE";
        case TokenType::NEW_LINE    : return "NEW_LINE";
        case TokenType::THEN        : return "THEN";
        case TokenType::EQ          : return "EQ";
        case TokenType::EQEQ        : return "EQEQ";
        case TokenType::VAR         : return "VAR";
        case TokenType::STR         : return "STR";
        case TokenType::ID          : return "ID";
        case TokenType::KEY         : return "KEY";
        case TokenType::FUNC        : return "FUNC";      
        default:
            break;
    }
}