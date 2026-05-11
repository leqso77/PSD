main: main.o libro.o catalogo.o
	gcc -o main main.o libro.o catalogo.o
main.o: main.c libro.c catalogo.c
	gcc -c main.c libro.c catalogo.c

libro.o: libro.c catalogo.c
	gcc -c libro.c catalogo.c

catalogo.o: catalogo.c libro.c
	gcc -c catalogo.c libro.c

clean:
	rm -f *.o main