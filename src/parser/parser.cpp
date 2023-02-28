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
    while(this->currentToken.getType() != TT_EOF) {
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
            if(this->currentToken.getType() == TT_ID) {
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
                if(std::holds_alternative<std::string>(this->varSymbols.at(this->currentToken.getValue()))) {
                    result += std::get<std::string>(this->varSymbols.at(this->currentToken.getValue()));
                } else {
                    this->throwError("Invalid type '" + this->currentToken.getType() + "'");
                }
                this->advance();
            } else {
                this->throwError("Unknown variable '" + this->currentToken.getValue() + "'");
            }
        }
        else if(this->isKeyToken("null")) {
            result += "";
            this->advance();
        }
        else if(this->currentToken.getType() == TT_PLUS) {
            result += "";
            this->advance();
        } else {
            this->throwError("Expected '" + endTokenType + "'");
        }
    }
    return result;
}

std::vector<std::string> Parser::makeStringArray()
{
    std::vector<std::string> result;
    while(this->currentToken.getType() != TT_RBRACKET) {
        if(this->nextToken.getType() == TT_RBRACKET) {
            result.push_back(this->makeStringArg(TT_RBRACKET));
        } 
        else if(this->nextToken.getType() == TT_COMMA) {
            result.push_back(this->makeStringArg(TT_COMMA));
            this->advance();
        } 
        else if(this->currentToken.getType() == TT_NL) {
            this->currentLine++;
            this->advance();
        }
        else if(this->nextToken.getType() == TT_NL) {
            result.push_back(this->makeStringArg(TT_NL));
            this->advance();
        } else {
            this->throwError("Expected ',' or ']'");
        }
    }
    return result;
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
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return "NULL";
}

std::string Parser::makeDelFunc()
{
    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {
        this->advance();
        std::string arg0 = this->makeStringArg(TT_RPAREN);
        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
            this->advance();

            #ifdef _WIN32
                return "del " + arg0;
            #endif

            #ifdef __APPLE__
                return "rm -rf " + arg0;
            #endif

            #ifdef __linux__
                return "rm -rf " + arg0;
            #endif

        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return "NULL";
}

std::string Parser::makePrintFunc()
{
    this->advance();
    if(this->currentToken.getType() == TT_LPAREN) {
        this->advance();
        std::string arg0 = this->makeStringArg(TT_RPAREN);
        this->advance();
        if(this->currentToken.getType() == TT_EOL) {
            this->advance();
            return arg0;
        } else {
            this->throwError("Expected ';'");
        }
    } else {
        this->throwError("Expected '('");
    }
    return "NULL";
}

Parser::Parser() {}
Parser::~Parser() {}