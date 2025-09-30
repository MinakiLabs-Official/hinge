#include <stdio.h>
#include "token.h"

void print_token(Token token) {
    printf("[TOKEN] Type: %d, Lexeme: %s, Line: %d\n", token.type, token.lexeme, token.line);
}
