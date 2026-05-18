main: main.o item-song.o list.o song.o playlist.o
	gcc -o main main.o item-song.o list.o song.o playlist.o

main.o: main.c item-song.c list.c song.c playlist.c
	gcc -c main.c item-song.c list.c song.c playlist.c

item-song.o: item-song.c
	gcc -c item-song.c

list.o: list.c
	gcc -c list.c

song.o: song.c
	gcc -c song.c

playlist.o: playlist.c
	gcc -c playlist.c

clean:
	rm -f *.o main