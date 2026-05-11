main: main.o stack.o
	gcc -o main main.o stack.o -lm

main.o: main.c stack.h item.h
	gcc -c main.c

stack.o: stack.c stack.h item.h
	gcc -c stack.c

clean:
	rm -f *.o main