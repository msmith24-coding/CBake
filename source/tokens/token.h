#ifndef TOKEN_H_
#define TOKEN_H_

typedef enum
{
    TOKEN_SCALAR,
    TOKEN_MAPPING_START,
    TOKEN_MAPPING_END,
    TOKEN_SEQUENCE_START,
    TOKEN_SEQUENCE_END,
    TOKEN_LIST_ITEM,
    TOKEN_EOF
} TokenType;

typedef struct
{
    TokenType type;
    char *value;  
} Token;

#endif
