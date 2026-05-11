main: main.o elemento.o spesa.o
	gcc -o main main.o elemento.o spesa.o

main.o: main.c spesa.c elemento.c
	gcc -c main.c

elemento.o: elemento.c spesa.c
	gcc -c elemento.c

spesa.o: spesa.c spesa.c elemento.c
	gcc -c spesa.c

clean:
	rm -f *.o main 