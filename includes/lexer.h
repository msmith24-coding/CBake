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

#ifndef LEXER_H_
#define LEXER_H_

#include <string>
#include <vector>

#include <token.h>

struct LexResult
{
    std::vector<Token> tokens;
};

class Lexer
{
    private:
        std::string src;
        int pos;
        unsigned int currentLine;
        char currentChar;
    public:
        /* lexer.cpp */
        Lexer(std::string p_src);
        LexResult buildTokens();

        /* lexer_checks.cpp */
        bool shouldIgnoreCharacter();
        bool isNewLine();
        bool checkCharacter(char p_charToCheck);
        bool isVariable();
        bool isString();

        /* lexer_makes.cpp */
        Token makeEqualToken();
        Token makeVariableToken();
        Token makeStringToken();
        Token makeIDKeyOrFunc();

        /* lexer_utils.cpp */
        void advance();
        void nextLine();

        Lexer();
        ~Lexer();
};

#endif