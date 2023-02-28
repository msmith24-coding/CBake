#include "../../includes/lexer.h"

/* Constructors */
Lexer::Lexer(std::string src_)
{
    this->src = src_;
    this->pos = -1;
    this->lineCount = 1;
    this->currentChar = 0;
    this->advance();
}

LexResult Lexer::buildTokens() /* Generates Tokens. */
{
    std::vector<Token> tokens;
    LexResult result;

    while(this->currentChar != 0) { /* Loop until no more characters. */
        if(this->currentChar == ' ' || this->currentChar == '\t') { /* Ignore spaces and tabs */
            this->advance();
        }
        else if(this->currentChar == '\n') { /* New line Token */
            tokens.push_back(Token(TT_NL));
            this->lineCount++;
            this->advance();
        }
        else if(this->currentChar == ';') { /* Checks if the currentChar is a certain token. */
            tokens.push_back(Token(TT_EOL)); // <-- Adds the token to a tokens vector.
            this->advance(); // <-- Advance to next character.
        }
        else if(this->currentChar == ':') {
            tokens.push_back(Token(TT_THEN));
            this->advance();
        }
        else if(this->currentChar == '<') {
            tokens.push_back(Token(TT_LTHAN));
            this->advance();
        }
        else if(this->currentChar == '>') {
            tokens.push_back(Token(TT_GTHAN));
            this->advance();
        }
        else if(this->currentChar == '[') {
            tokens.push_back(Token(TT_LBRACKET));
            this->advance();
        }
        else if(this->currentChar == ']') {
            tokens.push_back(Token(TT_RBRACKET));
            this->advance();
        }
        else if(this->currentChar == '+') {
            tokens.push_back(Token(TT_PLUS));
            this->advance();
        }
        else if(this->currentChar == ',') {
            tokens.push_back(Token(TT_COMMA));
            this->advance();
        }
        else if(this->currentChar == '(') {
            tokens.push_back(Token(TT_LPAREN));
            this->advance();
        }
        else if(this->currentChar == ')') {
            tokens.push_back(Token(TT_RPAREN));
            this->advance();
        }
        else if(this->currentChar == '$') {
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
