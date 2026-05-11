spotify_app: main.o spotify.o
	gcc main.o spotify.o -o spotify_app

main.o: main.c spotify.h
	gcc -c main.c

spotify.o: spotify.c spotify.h
	gcc -c spotify.c

clean:
	rm *.o spotify_app	