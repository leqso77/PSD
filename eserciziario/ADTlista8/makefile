main: main.o prenotazione.o registro.o
	gcc -o main main.o prenotazione.o registro.o 

main.o: main.c prenotazione.c registro.c
	gcc -c main.c prenotazione.c registro.c

prenotazione.o: prenotazione.c
	gcc -c prenotazione.c

registro.o: registro.c prenotazione.c
	gcc -c registro.c prentoazione.c

clean:
	rm -f *.m main