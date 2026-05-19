main: main.o item.o list.o task.o progetto.o
	gcc -o main.exe main.o item.o list.o task.o progetto.o

main.o: main.c progetto.c task.c
	gcc -c main.c progetto.c task.c

item.o: item.c task.c
	gcc -c item.c task.c

list.o: list.c item.c
	gcc -c list.c item.c

task.o: task.c
	gcc -c task.c

progetto.o: progetto.c list.c task.c
	gcc -c progetto.c list.c task.c

clean:
	rm -f *.o main.exe