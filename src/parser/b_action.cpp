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
// | Loops until it reaches an end and adds command line output to 
// | a vector for processing later if said action is called from command line.
// +
std::vector<std::string> Parser::makeAction()
{
    std::vector<std::string> result;
    if(this->currentToken.getType() == TokenType::THEN) {
        this->advance();
        while(!this->isKeyToken("end")) {
            if(this->currentToken.getType() == TokenType::NEW_LINE) {
                this->currentLine++;
                this->advance();
            }
            else if(this->isFuncToken("run")) {
                std::vector<std::string> runResult = this->makeRunFunc();
            }
            else if(this->isFuncToken("del")) {
                result.push_back(this->makeDelFunc());
            }
            else if(this->isFuncToken("unit_test")) {
                std::vector<std::string> blockResult = this->makeUnitTestFunc();

                for(std::string str : blockResult) {
                    result.push_back(str);
                }
            }
            else if(this->isFuncToken("simple_compile")) {
                std::vector<std::string> blockResult = this->makeSimpleCompileFunc();

                for(std::string str : blockResult) {
                    result.push_back(str);
                }
            }
            else if(this->isFuncToken("compile")) {
                std::vector<std::string> blockResult = this->makeCompileFunc();

                for(std::string str : blockResult) {
                    result.push_back(str);
                }
            }
            else if(this->isFuncToken("simple_archive")) {
                std::vector<std::string> blockResult = this->makeSimpleArchiveFunc();

                for(std::string str : blockResult) {
                    result.push_back(str);
                }
            }
            else if(this->isFuncToken("print")) {
                std::string printResult = this->makePrintFunc();
                result.push_back(printResult);
            }
            else if(this->isFuncToken("call")) {
                std::string actionToCall = this->makeCallFunc();
                if(!this->actionMap.count(actionToCall)){
                    std::cout << "[ERR] Action could not be found." << std::endl;
                    exit(1);
                }
                for(std::string str : this->actionMap.at(actionToCall)) {
                    result.push_back(str);
                }
            } else {
                this->throwError("Unknown identifier '" + this->currentToken.getValue() + "'");
            }
        }
    } else {
        this->throwError("Expected ':'");
    }

    return result;
}