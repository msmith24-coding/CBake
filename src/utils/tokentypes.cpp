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

#include "../../includes/tokentypes.h"

// +
// | A function to format a token name to a string.
// +
std::string TokenAsString(TokenType type_)
{
    switch(type_)
    {
        /* Formatting Tokens */
        case TokenType::END_OF_FILE : return "END_OF_FILE";
        case TokenType::END_OF_LINE : return "END_OF_LINE";
        case TokenType::NEW_LINE    : return "NEW_LINE";

        /* Mathimatical Tokens */
        case TokenType::PLUS        : return "PLUS";
        case TokenType::MINUS       : return "MINUS";
        case TokenType::MUL         : return "MUL";
        case TokenType::DIV         : return "DIV";

        /* Parentheses, Brackets, Less Than & Greater Than */
        case TokenType::LPAREN      : return "LPAREN";
        case TokenType::RPAREN      : return "RPAREN";
        case TokenType::LBRACKET    : return "LBRACKET";
        case TokenType::RBRACKET    : return "RBRACKET";
        case TokenType::LTHAN       : return "LTHAN";
        case TokenType::GTHAN       : return "GTHAN";

        /* Synbols Tokens */
        case TokenType::EQ          : return "EQ";
        case TokenType::EQEQ        : return "EQEQ";
        case TokenType::THEN        : return "THEN";
        case TokenType::COMMA       : return "COMMA";

        /* Type Tokens */
        case TokenType::STR         : return "STR";
        case TokenType::INT         : return "INT";
        case TokenType::FLOAT       : return "FLOAT";

        /* Utility Tokens */
        case TokenType::KEY         : return "KEY";
        case TokenType::FUNC        : return "FUNC";
        case TokenType::ID          : return "ID";
        case TokenType::VAR         : return "VAR";

        default: 
            return "INVALID TOKEN TYPE";
    }
}