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

#include "../../includes/parser.h"

std::vector<std::string> Parser::makeSimpleCompileFunc()
{
    std::vector<std::string> result;
    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {

        this->advance();
        std::string compiler = this->makeStringArg(TokenType::COMMA);
        if(compiler.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string objs = this->makeStringArg(TokenType::COMMA);

        if(objs.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string cFlags = this->makeStringArg(TokenType::COMMA);

        if(cFlags.empty()) {
            this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        std::string out = this->makeStringArg(TokenType::RPAREN);

        if(out.empty()) {
           this->throwError("simple_compile -> (compiler, objs, compiler_flags, out).");
        }

        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            result.push_back(compiler + " " + objs + " " + cFlags + " -o " + out);
            return result;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return result;
}