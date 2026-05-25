main: main.o item-string.o queue-array.o
	gcc -o main main.o item-string.o queue-array.o

main.o: main.c item-string.c queue-array.c
	gcc -c main.c item-string.c queue-array.c

item-string.o: item-string.c
	gcc -c item-string.c

queue-array.o: queue-array.c
	gcc -c queue-array.c

clean:
	rm -f *.o main