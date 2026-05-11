main: main.o prodotto.o carrello.o
	gcc -o main main.o prodotto.o carrello.o

main.o: main.c prodotto.c carrello.c
	gcc -c main.c prodotto.c carrello.c

prodotto.o: prodotto.c carrello.c
	gcc -c prodotto.c carrello.c

carrello.o: carrello.c prodotto.c
	gcc -c carrello.c prodotto.c

clean:
	rm -f *.o main