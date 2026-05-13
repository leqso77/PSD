main: main.o ordine.o drivethru.o
	gcc -o main main.o ordine.o drivethru.o

main.o: main.c ordine.c drivethru.c
	gcc -c main.c ordine.c drivethru.c

ordine.o: ordine.c
	gcc -c ordine.c

drivethru.o: drivethru.c ordine.c
	gcc -c drivethru.c ordine.c

clean:
	rm -f *.o main