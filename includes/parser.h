#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "token.h"
#include "tokentypes.h"

class Parser
{
    private:
        std::vector<Token> tokens;  
        std::map<std::string, std::variant<std::string, int, float>> varSymbols;
        std::map<std::string, std::vector<std::string>> actionMap;
        int position;
        int currentLine;
        Token currentToken;
        Token nextToken;
    public:
        Parser(std::vector<Token> tokens);

        std::map<std::string, std::vector<std::string>> buildTree();

        void advance();
        void throwError(std::string message);
        void makeVariable();

        std::string makeStringArg(std::string endTokenType);
        std::vector<std::string> makeStringArray();
        std::vector<std::string> makeAction();

        std::vector<std::string> makeRunFunc();
        std::string makeCallFunc();
        std::string makeDelFunc();
        std::string makePrintFunc();
        std::vector<std::string> makeSimpleCompileFunc();

        bool isKeyToken(std::string value);
        bool isFuncToken(std::string func);
        bool isVarToken();
        bool isNewLineToken();

        Parser();
        ~Parser();
};

#endif