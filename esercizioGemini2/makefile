main: main.o item.o list.o film.o catalogo.o
	gcc -o main.exe main.o item.o list.o film.o catalogo.o

main.o: main.c catalogo.c film.c
	gcc -c main.c catalogo.c film.c

item.o: item.c film.c
	gcc -c item.c film.c

list.o: list.c item.c
	gcc -c list.c item.c

film.o: film.c
	gcc -c film.c

catalogo.o: catalogo.c list.c film.c
	gcc -c catalogo.c list.c film.c

clean:
	rm -f *.o main.exe