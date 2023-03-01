#include "../../includes/parser.h"

/*
    Syntax:
        $VAR : <str, int, float> = <value>;
*/

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