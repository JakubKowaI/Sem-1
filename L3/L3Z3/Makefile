# Makefile

all: main

main: main.o phi.o NWD.o
	clang -o main main.o phi.o NWD.o

main.o: main.c
	clang -c main.c

phi.o: phi.c
	clang -c phi.c

NWD.o: NWD.c
	clang -c NWD.c
	
clean:
	rm -f main *.o *~