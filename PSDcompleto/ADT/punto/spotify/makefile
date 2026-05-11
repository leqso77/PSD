main: main.o stack.o item.o
	gcc -o main main.o stack.o item.o

main.o: main.c stack.h item.h
	gcc -c main.c

stack.o: stack.c stack.h item.h
	gcc -c stack.c

item.o: item.c item.h
	gcc -c item.c

clean:
	rm -f *.o main