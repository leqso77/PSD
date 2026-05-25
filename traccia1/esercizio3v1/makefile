main: main.o item-string.o stack.o
	gcc -o main main.o item-string.o stack.o

main.o: main.c item-string.c stack.c
	gcc -c main.c item-string.c stack.c

item-string.o: item-string.c
	gcc -c item-string.c

stack.o: stack.c
	gcc -c stack.c

clean:
	rm -f *.o main