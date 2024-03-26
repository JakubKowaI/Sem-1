# Makefile

all: main

main: main.o
	clang -o main main.o 

main.o: main.c
	clang -c main.c

	
clean:
	rm -f main *.o *~