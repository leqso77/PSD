main: main.o partita.o classifica.o 
	gcc -o main main.o partita.o classifica.o

main.o: main.c partita.c classifica.c
	gcc -c main.c partita.c classifica.c

partita.o: partita.c classifica.c
	gcc -c partita.c classifica.c

classifica.o: classifica.c partita.c
	gcc -c classifica.c partita.c

clean:
	rm -f *.m main