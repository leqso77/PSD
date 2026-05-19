#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carrello.h"
#include "list.h"
#include "prodotto.h"

struct carrello {
	char *id_carrello;
	List prodotti;
};

Carrello createCarrello(char* id_carrello){
	Carrello c = malloc(sizeof(struct carrello));
	c->id_carrello = strdup(id_carrello);
	c->prodotti = newList();
	return c;
}

void addProdotto(Carrello c, Prodotto p){
	addHead(c->prodotti, p);
}

void removeProdotto(Carrello c, char *nome){
	Prodotto p = initProdotto(nome, "", 0.0);
	removeListItem(c->prodotti, p);
}

void printCarrello(Carrello c){
	printf("Carrello: %s", c->id_carrello);
	printList(c->prodotti);
	printf("\n");
}

void sortbyPrezzo(Carrello c){
    int n=sizeList(c->prodotti);
    for (int i=0; i< n-1; i++){
        for (int j=0; j< n-i-1; j++){
            Prodotto p1=(Prodotto) getListItemPos(c->prodotti, j);
            Prodotto p2=(Prodotto) getListItemPos(c->prodotti, j+1);
            if (getPrezzo(p1) < getPrezzo(p2)){
                setListItemPos(c->prodotti, j, p2);
                setListItemPos(c->prodotti, j+1, p1);
            }
        }
    }
}
