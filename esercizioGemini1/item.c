#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "prodotto.h"

Item inputItem(){
	printf("Non usare inputItem(). Non richiedere input da tastiera.\n");
	return initProdotto("Prodotto Test", "Categoria Test", 10.0);
}

void outputItem(Item item){
	Prodotto p = item;
	printf("\n[%s] %s - %.2f euro - sconto: %d%% - prezzo finale: %.2f euro", getCategoria(p), getNome(p), getPrezzo(p), getSconto(p), getPrezzoFinale(p));
}

int cmpItem(Item item1, Item item2){
	Prodotto p1 = item1;
	Prodotto p2 = item2;
	return strcmp(getNome(p1), getNome(p2));
}