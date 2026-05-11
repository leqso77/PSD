main: main.o canzone.o playlist.o
	gcc main.o canzone.o playlist.o -o main.exe

main.o: main.c canzone.c playlist.c
	gcc -c main.c

canzone.o: canzone.c playlist.c
	gcc -c canzone.c

playlist.o: playlist.c canzone.c
	gcc -c playlist.c

clean:
	rm -f *.exe *.o