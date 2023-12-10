CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wvla -g -D_GNU_SOURCE
LDFLAGS = -lm

all: cliente

cliente: cliente.o bignumber.o
	$(CC) $(CFLAGS) -o cliente cliente.o bignumber.o $(LDFLAGS)

%.o: %.c bignumber.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f cliente *.o
