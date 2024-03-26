# Makefile

all: main

main: main.o p.o
	clang -o main main.o p.o

main.o: main.c
	clang -c main.c

p.o: p.c
	clang -c p.c


clean:
	rm -f main *.o *~