#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "../includes/lexer.h"
#include "../includes/parser.h"
#include "../includes/keywords.h"
#include "../includes/functions.h"

int main(int argc, char** argv)
{
    setupKeywords();
    setupFunctions();
    std::string path = "CBakefile";
    std::string action;

    std::ifstream file(path);
    std::string str;
    std::string src;

    if(!file) { // <-- No CBakefile?
        std::cout << "[ERR] No CBakefile located." << std::endl;
        return 1; 
    }

    if(argc <= 1) { // <-- No action?
        std::cout << "[ERR] No action provided." << std::endl;
        return 1;
    }

    action = argv[1]; //<-- Sets action equal to arg 1

    /* Reads the CBakefile line by line. */
    while(std::getline(file, str)) {
        src += str + "\n";
    }
    
    Lexer lex = Lexer(src);
    LexResult lexResult = lex.buildTokens();

    // for(Token token : lexResult.tokens) {
    //     std::cout << token.asString() << " ";
    // }
    
    Parser parse = Parser(lexResult.tokens);
    std::map<std::string, std::vector<std::string>> tree = parse.buildTree();

    for(size_t i = 0; i < tree.at(action).size(); i++) {
        const char *cmd = tree.at(action).at(i).c_str();
        std::system(cmd);
    }

    return 0;
}