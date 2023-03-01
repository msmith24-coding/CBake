#include "../../includes/lexer.h"

// +
// | Sets default values for the lexer.
// | Advances to the first token.
// +
Lexer::Lexer(std::string src_)
{
    this->src = src_;
    this->pos = -1;
    this->lineCount = 1;
    this->currentChar = 0;
    this->advance();
}

// +
// | Loops while there is a character.
// | Advances after the token has been added
// | to the tokens vector.
// +
LexResult Lexer::buildTokens()
{
    std::vector<Token> tokens;
    LexResult result;

    while(this->currentChar != 0) { 
        if(this->shouldIgnoreCharacter()) { 
            this->advance();
        }
        else if(this->checkCharacter('\n')) { 
            tokens.push_back(Token(TT_NL));
            this->lineCount++;
            this->advance();
        }
        else if(this->checkCharacter(';')) { 
            tokens.push_back(Token(TT_EOL)); 
            this->advance(); 
        }
        else if(this->checkCharacter(':')) {
            tokens.push_back(Token(TT_THEN));
            this->advance();
        }
        else if(this->checkCharacter('<')) {
            tokens.push_back(Token(TT_LTHAN));
            this->advance();
        }
        else if(this->checkCharacter('>')) {
            tokens.push_back(Token(TT_GTHAN));
            this->advance();
        }
        else if(this->checkCharacter('[')) {
            tokens.push_back(Token(TT_LBRACKET));
            this->advance();
        }
        else if(this->checkCharacter(']')) {
            tokens.push_back(Token(TT_RBRACKET));
            this->advance();
        }
        else if(this->checkCharacter('+')) {
            tokens.push_back(Token(TT_PLUS));
            this->advance();
        }
        else if(this->checkCharacter(',')) {
            tokens.push_back(Token(TT_COMMA));
            this->advance();
        }
        else if(this->checkCharacter('(')) {
            tokens.push_back(Token(TT_LPAREN));
            this->advance();
        }
        else if(this->checkCharacter(')')) {
            tokens.push_back(Token(TT_RPAREN));
            this->advance();
        }
        else if(this->isVariable()) {
            tokens.push_back(this->makeVariable());
        } 
        else if(this->currentChar == '=') {
            tokens.push_back(this->makeEqual());
        } 
        else if(this->currentChar == '"') {
            tokens.push_back(this->makeString());
        }
        else if(isdigit(this->currentChar)) {

        }
        else if(isalpha(this->currentChar)) {
            tokens.push_back(this->makeWord());
        } else {
            std::string errorStr = "";
            errorStr += this->currentChar;
            this->throwError("Invalid character '" + errorStr + ".");
        }
    }

    tokens.push_back(Token(TT_EOF));

    result.tokens = tokens;

    return result;
}

/* Unused */
Lexer::Lexer() {}
Lexer::~Lexer() {}
