all: randFunctions.o main.o
	gcc -o test_rand randFunctions.o main.o

main.o: main.c randHeaders.h
	gcc -c main.c

randFunction.o: randFunctions.c randHeaders.h
	gcc -c randFunctions.c

run:
	./test_rand

clean:
	rm *.o
	rm *~
