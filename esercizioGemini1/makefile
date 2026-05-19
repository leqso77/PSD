main: main.o item.o list.o carrello.o prodotto.o
	gcc -o main.exe main.o item.o list.o carrello.o prodotto.o

main.o: main.c item.c list.c carrello.c prodotto.c
	gcc -c main.c item.c list.c carrello.c prodotto.c

item.o: item.c prodotto.c
	gcc -c item.c prodotto.c

list.o: list.c item.c
	gcc -c list.c item.c

carrello.o: carrello.c list.c prodotto.c
	gcc -c carrello.c list.c prodotto.c

prodotto.o: prodotto.c
	gcc -c prodotto.c

clean:
	rm -f *.o main.exe