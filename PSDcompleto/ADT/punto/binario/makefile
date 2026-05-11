main: main.o stack.o item.o
	gcc -o main main.c stack.c item.c -lm

main.o: main.c stack.c item.c
	gcc -c main.c

stack.o: stack.c item.c
	gcc -c stack.c item.c

item.o: item.c stack.c
	gcc -c item.c stack.c

clean:
	rm -f *.o main