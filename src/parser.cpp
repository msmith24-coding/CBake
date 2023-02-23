#include "../includes/parser.hpp"
#include "../includes/tokentypes.hpp"

#include <iostream>

Parser::Parser(std::vector<Token> tokens)
{
    this->tokens = tokens;
    this->position = -1;
    this->currentLine = 1;
    this->advance();
}

void Parser::advance()
{
    this->position++;
    this->currentToken = this->tokens.at(this->position);
}

std::map<std::string, std::string> Parser::buildTree()
{
    while(this->currentToken.getType() != TT_EOF) {
        if(this->currentToken.getType() == TT_NL) {
            this->currentLine++;
            this->advance();
        }
        else if(this->currentToken.getType() == TT_VAR) {
            this->makeVariable();
        }
        else if(this->isKeyToken("action")) {
            this->advance();
            if(this->currentToken.getType() == TT_ID) {
                std::string actionName = this->currentToken.getValue();
                this->advance();
                std::string body = this->makeAction();
                this->actionMap.insert({ actionName, body });
                this->advance();
            }
        } else {
            std::cout << "!!!" << this->currentToken.asString() <<  " " << this->position << std::endl;
        }
    }

    return this->actionMap;

}

void Parser::makeVariable()
{
    std::string varName;
    if(!this->currentToken.getValue().empty()) {
        varName = this->currentToken.getValue();
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
                    std::cout << "[ERR] SyntaxError: Expected ';' on line " << this->currentLine << "." << std::endl;
                    exit(1);
                }
            }
        } else {
            std::cout << "[ERR] SyntaxError: Expected '=' on line " << this->currentLine << "." << std::endl;
            exit(1);
        }
    } 
}

std::string Parser::makeStringArg(std::string endTokenType)
{
    std::string result;
    while(this->currentToken.getType() != endTokenType) {
        if(this->currentToken.getType() == TT_STR) {
            result += this->currentToken.getValue();
            this->advance();
        }
        else if(this->currentToken.getType() == TT_VAR) {
            if(this->varSymbols.count(this->currentToken.getValue())) {
                result += this->varSymbols.at(this->currentToken.getValue());
                this->advance();
            } else {
                std::cout << "[ERR] SymbolError: Unknown variable '" << this->currentToken.getValue() << " on line " << this->currentLine << "." << std::endl;
                exit(1);
            }
        }
        else if(this->currentToken.getType() == TT_PLUS) {
            result += "";
            this->advance();
        }   
    }
    return result;
}

std::string Parser::makeAction()
{
    std::string result;
    if(this->currentToken.getType() == TT_THEN) {
        this->advance();
        while(!this->isKeyToken("end")) {
            if(this->currentToken.getType() == TT_NL) {
                this->currentLine++;
                this->advance();
            }
            else if(this->isFuncToken("run")) {
                result += this->makeRunFunc();
            }
            else if(this->isFuncToken("call")) {
                std::string actionToCall = this->makeCallFunc();
                if(!this->actionMap.count(actionToCall)){
                    std::cout << "[ERR] Action could not be found." << std::endl;
                    exit(1);
                }
                result += this->actionMap.at(actionToCall);
            } else {
                std::cout << "!!!" << this->currentToken.asString() <<  " " << this->position << std::endl;
            }
        }
    }
    return result;
}

std::string Parser::makeRunFunc()
{
    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {
        this->advance();
        std::string arg0 = this->makeStringArg(TT_RPAREN);
        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
            this->advance();
            return arg0 + "\n";
        }
    }
    return "NULL";
}

std::string Parser::makeCallFunc()
{
    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {
        this->advance();
        std::string arg0 = this->makeStringArg(TT_RPAREN);
        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
            this->advance();
            return arg0;
        }
    }
    return "NULL";
}

bool Parser::isKeyToken(std::string value)
{
    if(Parser::currentToken.getType() == TT_KEY) {
        return Parser::currentToken.getValue() == value;
    }
    return false;
}

bool Parser::isFuncToken(std::string func)
{
    if(Parser::currentToken.getType() == TT_FUNC) {
        return Parser::currentToken.getValue() == func;
    }
    return false;
}

Parser::Parser() {}
Parser::~Parser() {}