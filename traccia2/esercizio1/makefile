main: main.o item.o list.o stack.o
	gcc -o main main.o item.o list.o stack.o

main.o: main.c item.c list.c stack.c
	gcc -c main.c item.c list.c stack.c

item.o: item.c
	gcc -c item.c

list.o: list.c item.c
	gcc -c list.c item.c

stack.o: stack.c item.c list.c
	gcc -c stack.c item.c list.c

clean: 
	rm -f *.o main