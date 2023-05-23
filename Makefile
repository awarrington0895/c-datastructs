CC=clang
CFLAGS=-Wall -Wextra -std=c2x -pedantic

linkedlist: list.c
	$(CC) $(CFLAGS) -o list.out list.c
