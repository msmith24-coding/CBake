#include "../../includes/parser.h"

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
            else if(this->isFuncToken("print")) {
                std::string out = this->makePrintFunc();
                result.push_back("echo " + out);
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