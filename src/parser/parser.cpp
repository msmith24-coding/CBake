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

Parser::Parser(std::vector<Token> tokens_)
{
    this->tokens = tokens_;
    this->position = -1;
    this->currentLine = 1;
    this->advance();
}

std::map<std::string, std::vector<std::string>> Parser::buildTree()
{
    while(this->currentToken.getType() != TokenType::END_OF_FILE) {
        //std::cout << this->currentToken.asString() << std::endl;
        if(this->isNewLineToken()) {
            this->currentLine++;
            this->advance();
        }
        else if(this->isVarToken()) {
            this->makeVariable();
        }
        else if(this->isKeyToken("action")) {
            this->advance();
            if(this->currentToken.getType() == TokenType::ID) {
                std::string actionName = this->currentToken.getValue();
                this->advance();
                std::vector<std::string> body = this->makeAction();
                this->actionMap.insert({ actionName, body });
                this->advance();
            }
        } else {
            this->throwError("Unknown token '" + this->currentToken.asString());
        }
    }
    return this->actionMap;
}

Parser::Parser() {}
Parser::~Parser() {}