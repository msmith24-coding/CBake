#include "lexer.h"

void makeTokens(FILE *file)
{
    Token token;
    while ((token = advance(file)).type != TOKEN_EOF) {
        if (token.type == TOKEN_SCALAR) {
            printf("Scalar: %s\n", token.value);
        } else if (token.type == TOKEN_MAPPING_START) {
            printf("Mapping Start\n");
        } else if (token.type == TOKEN_MAPPING_END) {
            printf("Mapping End\n");
        } else if (token.type == TOKEN_SEQUENCE_START) {
            printf("Sequence Start\n");
        } else if (token.type == TOKEN_SEQUENCE_END) {
            printf("Sequence End\n");
        } else if (token.type == TOKEN_LIST_ITEM) {
            printf("List Item\n");
        }

        if (token.value != NULL) {
            free(token.value);
        }
    }
    
}

Token advance(FILE *file)
{
    char buffer[256];
    char ch;
    int bufferIndex = 0;

    ch = fgetc(file);
    while(ch != EOF) {
        if(ch == ' ' || ch == '\t' || ch == '\n') {
            // Ignore Whitespace
        }
        else if (ch == '-') {
            Token token = {TOKEN_LIST_ITEM, NULL};
            return token;
        }
        else if(ch != ':' && ch != '[' && ch != ']' && ch != '{' && ch != '}') {
            buffer[bufferIndex++] = ch;
            ch = fgetc(file);
            while (ch != EOF && ch != ':' && ch != '[' && ch != ']' && ch != '{' && ch != '}' && ch != ' ' && ch != '\t' && ch != '\n') {
                buffer[bufferIndex++] = ch;
                ch = fgetc(file);
            }
            buffer[bufferIndex] = '\0';
            Token token = {TOKEN_SCALAR, strdup(buffer)};
            return token;
        }
        // Handle mapping start
        else if (ch == ':') {
            Token token = {TOKEN_MAPPING_START, NULL};
            return token;
        }
        // Handle mapping end
        else if (ch == '}') {
            Token token = {TOKEN_MAPPING_END, NULL};
            return token;
        }
        // Handle sequence start
        else if (ch == '[') {
            Token token = {TOKEN_SEQUENCE_START, NULL};
            return token;
        }
        // Handle sequence end
        else if (ch == ']') {
            Token token = {TOKEN_SEQUENCE_END, NULL};
            return token;
        }
        ch = fgetc(file);
    }
    Token token = {TOKEN_EOF, NULL};
    return token;
}
