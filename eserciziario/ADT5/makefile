main: main main.o contatto.o rubrica.o
	gcc -o main main.o contatto.o rubrica.o

main.o: main.c contatto.c rubrica.c
	gcc -c main.c contatto.c rubrica.c

contatto.o: contatto.c rubrica.c
	gcc -c contatto.c rubrica.c

rubrica.o: rubrica.c contatto.c
	gcc -c rubrica.c contatto.c

clean:
	rm -f *.o main