#ifndef TOKEN_TYPE_H_
#define TOKEN_TYPE_H_

#include <string>

enum class TokenType
{
    /* Formatting Tokens */
    END_OF_FILE, END_OF_LINE, NEW_LINE,
    /* Mathimatical Tokens */
    PLUS, MINUS, MUL, DIV,
    /* Parentheses, Brackets, Less Than & Greater Than */
    LPAREN, RPAREN,
    LBRACKET, RBRACKET, 
    GTHAN, LTHAN,
    /* Synbols Tokens */
    EQ, EQEQ, THEN, COMMA,
    /* Type Tokens */
    STR, INT, FLOAT,
    /* Utility Tokens */
    KEY, FUNC, ID, VAR
};

std::string TokenAsString(TokenType type_);

#endif