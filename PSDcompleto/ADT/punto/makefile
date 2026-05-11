main: main.o punto.o
	gcc -o main main.o punto.o -lm

main.o: main.c punto.h
	gcc -c main.c

punto.o: punto.c punto.h
	gcc -c punto.c

clean:
	rm -f *.o main

