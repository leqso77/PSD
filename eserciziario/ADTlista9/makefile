main: main.o veicolo.o officina.o
	gcc -o main main.o veicolo.o officina.o

main.o: main.c veicolo.c officina.c
	gcc -c main.c veicolo.c officina.c

veicolo.o: veicolo.c
	gcc -c veicolo.c

officina.o: officina.c veicolo.c
	gcc -c officina.c veicolo.c

clean:
	rm -f *.o main