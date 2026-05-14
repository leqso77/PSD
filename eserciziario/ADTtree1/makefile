main: main.o item.o BTree.o
	gcc -o main main.o item.o BTree.o

main.o: main.c item.c BTree.c
	gcc -c main.c item.c BTree.c

item.o: item.c
	gcc -c item.c

BTree.o: BTree.c item.c
	gcc -c BTree.c item.

clean:
	rm -f *.o main