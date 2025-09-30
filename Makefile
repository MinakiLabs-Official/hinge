CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/main.c src/token.c src/lexer.c
OUT = hinge

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

