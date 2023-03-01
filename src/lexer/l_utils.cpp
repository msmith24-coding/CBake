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

#include "../../includes/lexer.h"

// +
// | Increase the position by one.
// | Set the current character to the position it's at in the source.
// | or return an empty character.
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
// | Throws an error with a message and what 
// | line the error occured on.
// | Closes the program with an error code of 1.
// +
void Lexer::throwError(std::string message)
{
    std::cout << "[ERR] LexerError: " << message << std::endl;
    std::cout << "                : Line >> " << this->lineCount << std::endl;
    exit(1); //<-- (Michael): Research if using exit is bad practice. 
}