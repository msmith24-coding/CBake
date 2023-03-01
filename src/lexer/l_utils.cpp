#include "../../includes/lexer.h"

// +
// | Increase the position by one.
// | Set the current character to the position it's at in the source.
// | or return an empty character.
// +
void Lexer::advance() 
{
    this->pos++;
    if(this->pos < this->src.length()) { 
        this->currentChar = this->src.at(this->pos); 
    } else {
        this->currentChar = 0; 
    }
}

// +
// | Throws an error with a message and what 
// | line the error occured on.
// | Closes the program with an error code of 1.
// +
void Lexer::throwError(std::string message)
{
    std::cout << "[ERR] LexerError: " << message << std::endl;
    std::cout << "[ERR] LexerError: Line >> " << this->lineCount << std::endl;
    exit(1);
}