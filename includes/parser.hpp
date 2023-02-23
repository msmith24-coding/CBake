#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include <map>

#include "../includes/token.hpp"

class Parser
{
    private:
        std::vector<Token> tokens;  
        std::map<std::string, std::string> varSymbols;
        std::map<std::string, std::string> actionMap;
        int position;
        int currentLine;
        Token currentToken;
    public:
        Parser(std::vector<Token> tokens);

        void advance();
        std::map<std::string, std::string> buildTree();

        void makeVariable();

        std::string makeStringArg(std::string endTokenType);
        std::string makeAction();
        std::string makeRunFunc();
        std::string makeCallFunc();

        bool isKeyToken(std::string value);
        bool isFuncToken(std::string func);

        Parser();
        ~Parser();
};

#endif