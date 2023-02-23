#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "../includes/lexer.hpp"
#include "../includes/parser.hpp"
#include "../includes/keywords.hpp"
#include "../includes/functions.hpp"

int main(int argc, char** argv)
{
    setupKeywords();
    setupFunctions();
    std::string path = "CBakefile";
    std::string action;

    std::ifstream file(path);
    std::string str;
    std::string src;

    if(!file) {
        std::cout << "[ERR] No CBakefile located." << std::endl;
        return 1; 
    }

    if(argc <= 1) {
        std::cout << "[ERR] No action provided." << std::endl;
        return 1;
    }

    action = argv[1];

    while(std::getline(file, str)) {
        src += str + "\n";
    }
    
    Lexer lex = Lexer(src);
    LexResult lexResult = lex.makeTokens();

    // for(Token token : lexResult.tokens) {
    //     std::cout << token.asString() << " ";
    // }
    
    Parser parse = Parser(lexResult.tokens);
    std::map<std::string, std::string> tree = parse.buildTree();

    const char *cmd = tree.at(action).c_str();
    std::system(cmd);

    return 0;
}