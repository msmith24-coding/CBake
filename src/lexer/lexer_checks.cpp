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

#include <lexer.h>

// +
// | any characters that the lexer should skip over
// | goes here.
// +
bool Lexer::shouldIgnoreCharacter()
{
    return this->currentChar == ' ' || this->currentChar == '\t';
}

// +
// | Is the character a new line character?
// +
bool Lexer::isNewLine()
{
    return this->currentChar == '\n';
}

// + 
// | Generic function for comparing two characters.
// +
bool Lexer::checkCharacter(char p_charToCheck)
{
    return this->currentChar == p_charToCheck;
}

// +
// | Is the character a prefix for a variable?
// +
bool Lexer::isVariable()
{
    return this->currentChar == '$';
}

// +
// | Is the character is a double quote?
// +
bool Lexer::isString()
{
    return this->currentChar == '"';
}