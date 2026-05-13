main: main.o documento.o stampante.o
	gcc -o main main.o documento.o stampante.o

main.o: main.c documento.c stampante.c
	gcc -c main.c documento.c stampante.c

documento.o: documento.c
	gcc -c documento.c

stampante.o: stampante.c documento.c
	gcc -c stampante.c documento.c

clean: 
	rm -f *.o main