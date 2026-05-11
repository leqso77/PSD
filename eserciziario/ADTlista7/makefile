main: main.o transazione.o conto.o
	gcc -o main main.o transazione.o conto.o

main.o: main.c transazione.c conto.c
	gcc -c main.c transazione.c conto.c

transazione.o: transazione.c
	gcc -c trasnazione.c

conto.o: conto.c transazione.c
	gcc -c conto.c transazione.c

clean: 
	rm -f *.o main