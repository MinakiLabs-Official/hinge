#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lexer.h"

#define TOKEN_ARRAY_INIT_CAPACITY 8

void add_token(TokenArray *array, TokenType type, const char *lexeme, int line) {
    if (array->count >= array->capacity) {
        array->capacity *= 2;
        array->tokens = realloc(array->tokens, array->capacity * sizeof(Token));
    }

    Token token;
    token.type = type;
    token.lexeme = strdup(lexeme); // WARNING: strdup memory must be freed
    token.line = line;

    array->tokens[array->count++] = token;
}

TokenArray scan_tokens(const char *source) {
    TokenArray array;
    array.count = 0;
    array.capacity = TOKEN_ARRAY_INIT_CAPACITY;
    array.tokens = malloc(array.capacity * sizeof(Token));

    int line = 1;

    while (*source != '\0') {
        if (strncmp(source, "print", 5) == 0) {
            add_token(&array, TOKEN_PRINT, "print", line);
            source += 5;
        } else if (*source == '(') {
            add_token(&array, TOKEN_LEFT_PAREN, "(", line);
            source++;
        } else if (*source == ')') {
            add_token(&array, TOKEN_RIGHT_PAREN, ")", line);
            source++;
        } else if (*source == '"') {
            source++;
            const char *start_str = source;
            while (*source != '"' && *source != '\0') source++;
            int len = source - start_str;
            char *str = malloc(len + 1);
            strncpy(str, start_str, len);
            str[len] = '\0';
            add_token(&array, TOKEN_STRING, str, line);
            free(str);
            source++; // Skip closing quote
        } else {
            source++; // skip unknown characters for now
        }
    }

    add_token(&array, TOKEN_EOF, "EOF", line);
    return array;
}

void free_tokens(TokenArray *array) {
    for (int i = 0; i < array->count; i++) {
        free((char *)array->tokens[i].lexeme);
    }
    free(array->tokens);
}
