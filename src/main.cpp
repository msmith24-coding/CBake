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

const bool DEBUG_LEXER = false; 
const bool DEBUG_PARSER = false;

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
        std::cout << "[ERR] No action provided." << std::endl;
        return 1;
    }

    action = argv[1]; // <-- Sets the action equal to the first argument after the cbake command. 

    /* Loops the entire file and builds a source code string. */
    while(std::getline(file, str)) {
        src += str + "\n"; // <-- Adds \n at the end to declare a new line.
    }
    
    std::cout << src << std::endl;

    return 0; 
}