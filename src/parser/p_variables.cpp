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

void Parser::makeVariable()
{
    std::string varName;
    if(!this->currentToken.getValue().empty()) {
        varName = this->currentToken.getValue();
        this->advance();
        if(this->currentToken.getType() == TokenType::THEN) {
            this->advance();
            if(this->isKeyToken("str")) {
                this->advance();
                if(this->currentToken.getType() == TokenType::EQ) {
                    this->advance();
                    if(this->currentToken.getType() == TokenType::STR) {
                        std::string value = this->currentToken.getValue();
                        this->advance();
                        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
                            this->varSymbols.insert({varName, value});
                            this->advance();
                        } else {
                            this->throwError("Expected ';'");
                        }
                    } else {
                        this->throwError("Invalid assignment '" + TokenAsString(this->currentToken.getType()) + "'");
                    }
                } else {
                    this->throwError("Expected '='");
                }
            }
            else if(this->isKeyToken("int")) {
                this->advance();
                if(this->currentToken.getType() == TokenType::EQ) {
                    this->advance();
                    if(this->currentToken.getType() == TokenType::INT) {
                        int value = std::stoi(this->currentToken.getValue());
                        this->advance();
                        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
                            this->varSymbols.insert({varName, value});
                            this->advance();
                        } else {
                            this->throwError("Expected ';'");
                        }
                    } else {
                        this->throwError("Invalid assignment '" + TokenAsString(this->currentToken.getType()) + "'");
                    }
                } else {
                    this->throwError("Expected '='");
                }
            }
            else if(this->isKeyToken("float")) {
                this->advance();
                if(this->currentToken.getType() == TokenType::EQ) {
                    this->advance();
                    if(this->currentToken.getType() == TokenType::FLOAT) {
                        float value = std::stof(this->currentToken.getValue());
                        this->advance();
                        if(this->currentToken.getType() == TokenType::END_OF_LINE) {
                            this->varSymbols.insert({varName, value});
                            this->advance();
                        } else {
                            this->throwError("Expected ';'");
                        }
                    } else {
                        this->throwError("Invalid assignment '" + TokenAsString(this->currentToken.getType()) + "'");
                    }
                } else {
                    this->throwError("Expected '='");
                }
            }
            else if(this->isKeyToken("list")) { 
                this->advance();
                if(this->currentToken.getType() == TokenType::LTHAN) {
                    this->advance();
                    if(this->isKeyToken("str")) {
                        this->advance();
                        if(this->currentToken.getType() == TokenType::GTHAN) {
                            this->advance();
                            if(this->currentToken.getType() == TokenType::EQ) {
                                this->advance();
                                if(this->currentToken.getType() == TokenType::LBRACKET) {
                                    this->advance();

                                    std::vector<std::string> list = this->makeStringList();

                                    this->advance();
                                    if(this->currentToken.getType() == TokenType::END_OF_LINE) {
                                        std::string value;
                                        for(std::string str : list) {
                                            value += str + " ";
                                        }
                                        this->varSymbols.insert({varName, value});
                                        this->advance();
                                    } else {
                                        this->throwError("Expected ';'");
                                    }
                                } else {
                                    this->throwError("Expected '['");
                                }
                            } else {
                                this->throwError("Expected '='");
                            }
                        } else {
                            this->throwError("Expected '>'");
                        }
                    }
                } else {
                    this->throwError("Expected '<'");
                }
            } else {
                this->throwError("Expected <str, int, float, list>");
            }
        } else {
            this->throwError("Expected ':'");
        }
    } 
}