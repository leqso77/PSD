main: main.o btree.o item-int.o list.o
	gcc -o main main.o btree.o item-int.o list.o

main.o: main.c btree.c list.c
	gcc -c main.c btree.c list.c

btree.o: btree.c item-int.c list.c
	gcc -c btree.c item-int.c list.c

item-int.o: item-int.c
	gcc -c item-int.c

list.o: list.c item-int.c
	gcc -c list.c item.c

clean:
	rm -f *.o main