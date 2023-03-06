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

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include <lexer.h>
#include <keywords.h>

const bool FILE_READ_DEBUG = false;
const bool LEX_RESULT_DEBUG = true;

int main(int argc, char** argv)
{
    std::string path = "CBakefile";
    std::string action;

    std::ifstream file(path);
    std::string str;
    std::string src;

    if(!file) { 
        std::cout << "[ERR] No CBakefile located." << std::endl;
        return 1; 
    }

    if(argc <= 1) { 
        std::cout << "[ERR] No valid arguments provided." << std::endl;
        return 1;
    }

    if(argc == 2) {
        if((strcmp(argv[1], "--version") == 0) || (strcmp(argv[1], "-v") == 0)) {
            std::cout << "Currently using - CBake v1.0" << std::endl;
            std::cout << std::endl;
            std::cout << "CBake is under the GNU General Public License v3.0" << std::endl;
            return 0;
        } else {
            setupKeywords();
            action = argv[1]; 
        }
    }

    while(std::getline(file, str)) {
        src += str + "\n"; 
    }
    
    if(FILE_READ_DEBUG) {
        std::cout << src << std::endl;
    }

    Lexer lexer = Lexer(src);
    LexResult lexResult = lexer.buildTokens();

    if(LEX_RESULT_DEBUG) {
        for(Token token : lexResult.tokens) {
            std::cout << token.asString();
        }
    }

    return 0; 
}