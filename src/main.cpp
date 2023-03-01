/*
 * Project Styling Guide:
 *   - Constants: Upper Snake Case (MY_EXAMPLE_CONSTANT)
 *   - Functions: Camel Case (myExampleFunction)
 *   - Variables: Camel Case (myExampleVariable)
 * 
 * Project Braces Guide:
 *   - Functions: Next line 
 *   - If Statements: Same line
 *   - While/For Loops: Same line
 * 
 * Project Commenting Guide:
 *   - Function Comments:
 *       // +
 *       // | Function explaination here.
 *       // +
 *       void myExampleFunction() { ... }
 *   - If Statement Comments:
 *       // Explaination here.
 *       if(true) { ... } 
 *   - While/For Loops Comments:
 *       // Explaination here.
 *       while(true) { ... }
 *   - TODO Comments:
 *       int a = 1; // TODO: This is an example TODO. (First Name)
 */

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "../includes/lexer.h"
#include "../includes/parser.h"
#include "../includes/keywords.h"
#include "../includes/functions.h"

const bool DEBUG_LEXER = false; 
const bool DEBUG_PARSER = false;

int main(int argc, char** argv)
{
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

    action = argv[1]; // <-- Sets the action equal to the first argument after the cbake command. 

    setupKeywords();
    setupFunctions();

    /* Loops the entire file and builds a source code string. */
    while(std::getline(file, str)) {
        src += str + "\n"; // <-- Adds \n at the end to declare a new line.
    }
    
    Lexer lex = Lexer(src);
    LexResult lexResult = lex.buildTokens();

    /* Debugging code to output the generated tokens. */
    if(DEBUG_LEXER) {
        for(Token token : lexResult.tokens) {
            std::cout << token.asString() << " ";
        }
    }
    
    Parser parse = Parser(lexResult.tokens);
    std::map<std::string, std::vector<std::string>> tree = parse.buildTree();

    for(size_t i = 0; i < tree.at(action).size(); i++) {
        const char *cmd = tree.at(action).at(i).c_str();
        /* Debugging code to output the command that is being ran. */
        if(DEBUG_PARSER) {
            std::cout << cmd << std::endl;
        }

        std::system(cmd);
    }
    return 0; 
}