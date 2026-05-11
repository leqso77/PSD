main: main.o canzone.o playlist.o
	gcc -o main main.c canzone.o playlist.o

main.o: main.c canzone.c playlist.c
	gcc -c main.c canzone.c playlist.c

canzone.o: canzone.c 
	gcc -c canzone.c

playlist.o: playlist.c canzone.c
	gcc -c playlist.c canzone.c

clean: 
	rm -f *.m main

