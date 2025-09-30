#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

#include "lexer.h"

void run_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
        exit(1);
    }

    char buffer[2048];
    size_t total = fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[total] = '\0';

    fclose(file);

    TokenArray tokens = scan_tokens(buffer);
    for (int i = 0; i < tokens.count; i++) {
        print_token(tokens.tokens[i]);
    }
    free_tokens(&tokens);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <script.hinge>\n", argv[0]);
        return 1;
    }

    run_file(argv[1]);
    return 0;
}
