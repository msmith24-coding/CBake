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