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

// +
// | Returns the command to compile the code
// | based on it's provided arguments.
// +
std::vector<std::string> Parser::makeCompileFunc()
{
    std::vector<std::string> result;

    this->advance();
    if(this->currentToken.getType() == TokenType::LPAREN) {

        // +
        // | Reads all the arguments.
        // +
        this->advance();
        std::string compiler = this->makeStringArg(TokenType::COMMA);
        if(compiler.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string objs = this->makeStringArg(TokenType::COMMA);
        if(objs.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string includes = this->makeStringArg(TokenType::COMMA);
        if(includes.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string libraries = this->makeStringArg(TokenType::COMMA);
        if(libraries.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string compilerFlags = this->makeStringArg(TokenType::COMMA);
        if(compilerFlags.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string linkerFlags = this->makeStringArg(TokenType::COMMA);
        if(linkerFlags.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }

        this->advance();
        std::string out = this->makeStringArg(TokenType::RPAREN);
        if(out.empty()) {
            this->throwError("compile -> (compiler, objs, includes, libraries, compiler_flags, linker_flags, out).");
        }


        // +
        // | Advances to the last token.
        // | Checks if it ends with a semi-colon.
        // | Build the command and return the result.
        // +
        this->advance();
        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
            this->advance();
            
            result.push_back(compiler + " " + compilerFlags + " "  + objs + " " + includes + " " + libraries + " " + linkerFlags + " -o " + out);
            return result;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return result;
}