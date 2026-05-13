main: main.o cliente.o eliminacode.o
	gcc -o main main.o cliente.o eliminacode.o

main.o: main.c cliente.c eliminacode.c
	gcc -c main.c cliente.c eliminacode.c

cliente.o: cliente.c 
	gcc -c cliente.c

eliminacode.o: eliminacode.c cliente.c
	gc -c eliminacode.c cliente.c

clean: 
	rm -f *.o main