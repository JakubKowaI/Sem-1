# Makefile

all: main

main: main.o newagent.o North.o South.o East.o West.o distance.o 
	clang -o main main.o newagent.o North.o South.o East.o West.o distance.o 

main.o: main.c
	clang -c main.c
	
newagent.o: newagent.c
	clang -c newagent.c

North.o: North.c
	clang -c North.c

South.o: South.c
	clang -c South.c

East.o: East.c
	clang -c East.c

West.o: West.c
	clang -c West.c

distance.o: distance.c
	clang -c distance.c



clean:
	rm -f main *.o *~