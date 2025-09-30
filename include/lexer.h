#ifndef HINGE_LEXER_H
#define HINGE_LEXER_H

#include "token.h"

typedef struct {
    Token *tokens;
    int count;
    int capacity;
} TokenArray;

TokenArray scan_tokens(const char *source);
void free_tokens(TokenArray *array);

#endif
