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

#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include <map>
#include <string>
#include <variant>

#include <token.h>
#include <keywords.h>
#include <functions.h>

class Parser
{
    private:
        Token currentToken;
        Token nextToken;
        std::vector<Token> tokens;
        int pos;
        unsigned int currentLine;

        std::map<std::string, std::string> constSymbols;
        std::map<std::string, std::string> varSymbols;

        std::map<std::string, std::vector<std::string>> parseResult;
    public:
        Parser(std::vector<Token> p_tokens);
        
        /* parser.cpp */
        std::map<std::string, std::vector<std::string>> buildTree();

        /* parser_checks.cpp */
        bool isNewLineToken();
        bool isKeyToken();
        bool isFuncToken();

        /* parser_function_run.cpp */
        std::string makeRunFunction();

        /* parser_make_const.cpp */
        void makeConst();

        /* parser_make_def.cpp */
        void makeDef();

        /* parser_utils.cpp */
        void advance();
        void nextLine();
        std::string makeString(TokenType endTokenType);

        Parser();
        ~Parser();
};

#endif