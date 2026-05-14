main: main.o auto.o autolavaggio.o
	gcc -o main main.o auto.o autolavaggio.o

main.o: main.c auto.c autolavaggio.c
	gcc -c main.c auto.c autolavaggio.c

auto.o: auto.c
	gcc -c auto.c

autolavaggio.o: autolavaggio.c auto.c
	gcc -c autolavaggio.c auto.c

clean:
	rm -f *.o main