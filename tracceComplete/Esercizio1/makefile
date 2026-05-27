main: main.o item-paziente.o list.o prontosoccorso.o paziente.o
	gcc -o main main.o item-paziente.o list.o prontosoccorso.o paziente.o

main.o: main.c item-paziente.c prontosoccorso.c paziente.c
	gcc -c main.c item-paziente.c prontosoccorso.c paziente.c

item-paziente.o: item-paziente.c paziente.c
	gcc -c item-paziente.c paziente.c

list.o: list.c item-paziente.c
	gcc -c list.c item-paziente.c

prontosoccorso.o: prontosoccorso.c list.c paziente.c item-paziente.c
	gcc -c prontosoccorso.c list.c paziente.c item-paziente.c

paziente.o: paziente.c
	gcc -c paziente.c

clean:
	rm -f *.o main