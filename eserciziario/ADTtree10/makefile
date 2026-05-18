main: main.o item.o btree.o
	gcc -o main main.o item.o btree.o

main.o: main.c item.c btree.c
	gcc -c main.c item.c btree.c

item.o: item.c
	gcc -c item.c

bteee.o: btree.c item.c
	gcc -c btree.c item.c

clean:
	rm -f *.o main