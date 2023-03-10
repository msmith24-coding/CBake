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

#include <parser.h>
#include <iostream>

void Parser::makeDef()
{
    std::string defName;
    std::vector<std::string> result;

    this->advance();

    if(this->currentToken.getType() != TokenType::ID) {
        std::cout << "Expected identifer" << std::endl;
        exit(1);
    }

    defName = this->currentToken.getValue();
    this->advance();

    if(this->currentToken.getType() != TokenType::THEN) {
        std::cout << "Expected ':'" << std::endl;
        exit(1);
    }
    
    this->advance();

    while(this->currentToken.getType() != TokenType::KEY && this->currentToken.getValue() != keywords.at(Keywords::END)) {
        if(this->isNewLineToken()) {
            this->nextLine();
        }
        else if(this->isKeyToken()) {
            if(this->currentToken.getValue() == keywords.at(Keywords::CONST)) {
                this->makeConst();
            }
        }
        else if(this->isFuncToken()) {
            if(this->currentToken.getValue() == functions.at(Functions::RUN)) {
                result.push_back(this->makeRunFunction());
            }
        }
    }

    this->parseResult.insert({defName, result});
    this->advance();
}