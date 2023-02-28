#include "../../includes/lexer.h"

/* Functions */
void Lexer::advance() /* Advances to the next character. */
{
    this->pos++;
    if(this->pos < this->src.length()) { /* Checks if the pos is within the size of the source. */
        this->currentChar = this->src.at(this->pos); // <-- Update the current character.
        return;
    }
    this->currentChar = 0; 
}

void Lexer::throwError(std::string message)
{
    std::cout << "[ERR] SyntaxError: " << message << std::endl;
    std::cout << "[ERR] SyntaxError: Line >> " << this->lineCount << std::endl;
    exit(1);
}