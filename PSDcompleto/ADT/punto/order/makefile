main: main.o item.o stack.o
	gcc -o main main.c item.c stack.c -lm
main.o: main.c item.c stack.c
	gcc -c main.c
item.o: item.c stack.c
	gcc -c item.c
stack.o: stack.c item.c
	gcc -c stack.c
clean:	
	rm -f *.o main	