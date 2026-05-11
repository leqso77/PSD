main: main.o studente.o registro.o
	gcc -o main main.o studente.o registro.o 

main.o: main.c studente.c registro.c
	gcc -c main.c studente.c registro.c

studente.o: studente.c registro.c
	gcc -c studente.c registro.c

registro.o: registro.c studente.c
	gcc -c registro.c studente.c

clean:
	rm -f *.o main