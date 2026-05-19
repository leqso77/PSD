#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "film.h"

Item inputItem(){
	printf("Non usare inputItem(). Non richiedere input da tastiera.\n");
	return initFilm("Film Test", "Regista Test", 2000);
}

void outputItem(Item item){
	Film f = item;
	printf("\n%s (%d) - Regia: %s - valutazione: %d/10", getTitolo(f), getAnno(f), getRegista(f), getValutazione(f));
}

int cmpItem(Item item1, Item item2){
	Film f1 = item1;
	Film f2 = item2;
	return strcmp(getTitolo(f1), getTitolo(f2));
}