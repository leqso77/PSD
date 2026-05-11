gioco_kart: main.o kart.o
	gcc main.o kart.o -o gioco_kart

main.o: main.c kart.h
	gcc -c main.c

kart.o: kart.c kart.h
	gcc -c kart.c

clean: 
	rm *.o gioco_kart