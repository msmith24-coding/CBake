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
// | This function adds to the position, then checks if the 
// | it is within the bounds of the source code.
// | Either set the current character to the source code character or
// | set it to a null character.
// +
void Lexer::advance()
{
    this->pos++;
    if(this->pos < this->src.length()) {
        this->currentChar = this->src.at(this->pos);
    } else {
        this->currentChar = 0;
    }
}

// +
// | This function adds to the line count for error pointing.
// | The it advances to the next token.
// +
void Lexer::nextLine()
{
    this->currentLine++;
    this->advance();
}