main: main.o paziente.o triage.o
	gcc -o main main.o paziente.o triage.o 

main.o: main.c paziente.c triage.c
	gcc -c main.c paziente.c triage.c

paziente.o: paziente.c triage.c
	gcc -c paziente.c triage.c

triage.o: triage.c paziente.c
	gcc -c triage.c paziente.c

clean:
	rm -f *.m main