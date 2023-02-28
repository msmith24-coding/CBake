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
        if(this->currentToken.getType() == TT_THEN) {
            this->advance();
            if(this->isKeyToken("str")) {
                this->advance();
                if(this->currentToken.getType() == TT_EQ) {
                    this->advance();
                    if(this->currentToken.getType() == TT_STR) {
                        std::string value = this->currentToken.getValue();
                        this->advance();
                        if(this->currentToken.getType() == TT_EOL) {
                            this->varSymbols.insert({varName, value});
                            this->advance();
                        } else {
                            this->throwError("Expected ';'");
                        }
                    } else {
                        this->throwError("Invalid assignment '" + this->currentToken.getType() + "'");
                    }
                } else {
                    this->throwError("Expected '='");
                }
            }
            else if(this->isKeyToken("int")) {
                this->advance();
                if(this->currentToken.getType() == TT_EQ) {
                    this->advance();
                    if(this->currentToken.getType() == TT_INT) {
                        int value = std::stoi(this->currentToken.getValue());
                        this->advance();
                        if(this->currentToken.getType() == TT_EOL) {
                            this->varSymbols.insert({varName, value});
                            this->advance();
                        } else {
                            this->throwError("Expected ';'");
                        }
                    } else {
                        this->throwError("Invalid assignment '" + this->currentToken.getType() + "'");
                    }
                } else {
                    this->throwError("Expected '='");
                }
            }
            else if(this->isKeyToken("float")) {
                this->advance();
                if(this->currentToken.getType() == TT_EQ) {
                    this->advance();
                    if(this->currentToken.getType() == TT_FLOAT) {
                        float value = std::stof(this->currentToken.getValue());
                        this->advance();
                        if(this->currentToken.getType() == TT_EOL) {
                            this->varSymbols.insert({varName, value});
                            this->advance();
                        } else {
                            this->throwError("Expected ';'");
                        }
                    } else {
                        this->throwError("Invalid assignment '" + this->currentToken.getType() + "'");
                    }
                } else {
                    this->throwError("Expected '='");
                }
            }
            else if(this->isKeyToken("array")) { 
                this->advance();
                if(this->currentToken.getType() == TT_LTHAN) {
                    this->advance();
                    if(this->isKeyToken("str")) {
                        this->advance();
                        if(this->currentToken.getType() == TT_GTHAN) {
                            this->advance();
                            if(this->currentToken.getType() == TT_EQ) {
                                this->advance();
                                if(this->currentToken.getType() == TT_LBRACKET) {
                                    this->advance();

                                    std::vector<std::string> array = this->makeStringArray();

                                    this->advance();
                                    if(this->currentToken.getType() == TT_EOL) {
                                        std::string value;
                                        for(std::string str : array) {
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
                this->throwError("Expected <str, int, float, array>");
            }
        } else {
            this->throwError("Expected ':'");
        }
    } 
}