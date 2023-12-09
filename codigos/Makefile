all: cliente

cliente: cliente.o bignumber.o
	gcc cliente.o bignumber.o -lm -o cliente

cliente.o: cliente.c bignumber.h
	gcc -std=c99 -Wall -Werror -c cliente.c

bignumber.o: bignumber.c bignumber.h 
	gcc -std=c99 -Wall -Werror -c bignumber.c