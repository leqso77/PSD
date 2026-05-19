main: main.o item-int.o list.o btree.o
	gcc -o main.exe main.o item-int.o list.o btree.o

main.o: main.c
	gcc -c main.c

item-int.o: item-int.c
	gcc -c item-int.c

list.o: list.c
	gcc -c list.c

btree.o: btree.c
	gcc -c btree.c

clean:
	rm -f *.o main.exe