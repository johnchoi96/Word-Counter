CC = gcc
CFLAGS = -Wall -std=c99 -g
counter: counter.o
counter.o: counter.c

clean:
	rm -f *.o
