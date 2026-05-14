main: main.o ticket.o centralino.o
	gcc -o main main.o ticket.o centralino.o

main.o: main.c ticket.c centralino.c
	gcc -c main.c ticket.c centralino.c

ticket.o: ticket.c
	gcc -c ticket.c

centralino.o: centralino.c ticket.c
	gcc -c centralino.c ticket.c

clean:
	rm -f *.o main