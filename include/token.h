#ifndef HINGE_TOKEN_H
#define HINGE_TOKEN_H

typedef enum {
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_STRING,
    TOKEN_IDENTIFIER,
    TOKEN_PRINT,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    const char *lexeme;
    int line;
} Token;

void print_token(Token token);

#endif
