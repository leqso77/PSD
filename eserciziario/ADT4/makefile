main: main.o auto.o concessionaria.o
	gcc -o  main main.o auto.o concessionaria.o

main.o: main.c auto.c concessionaria.c
	gcc -c main.c auto.c concessionaria.c

auto.o: auto.c concessionaria.c
	gcc -c auto.c concessionaria.c

concessionaria.o: concessionaria.c auto.c
	gcc -c concessionaria.c auto.c

clean:
	rm -f *.o main

