#ifndef LEXER_H_
#define LEXER_H_

#include "../tokens/token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void makeTokens(FILE *file);
Token advance(FILE *file);

#endif
