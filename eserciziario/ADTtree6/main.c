#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "btree.h"

int main(){
    Btree f8=buildBtree(createItem(8), newBtree(), newBtree());
    Btree f12=buildBtree(createItem(12), newBtree(), newBtree());
    Btree f20=buildBtree(createItem(20), newBtree(), newBtree());

    Btree n5=buildBtree(createItem(5),newBtree(), f8);
    Btree n15=buildBtree(createItem(15), f12, f20);

    Btree albero=buildBtree(createItem(10), n5, n15);

    int nodiSingoli=contaNodiSingoli(albero);
    printf("Nodi con esattamente UN figlio: %d (Atteso: 1 -> il nodo 5)\n", nodiSingoli);

    int somma=sommaFoglie(albero);
    printf("Somma dei valori di tutte le foglie: %d (Atteso: 40 -> 8+12+20)\n\n", somma);

    int target1=12;
    int livello1=livelloNodo(albero, target1, 0);

    if (livello1 != -1){
        printf("Il nodo %d si trova al livello %d.\n", target1, livello1);
    }
    else{
        printf("Il nodo %d non e' nell'albero.\n", target1);
    }

    int target2 = 99;
    int livello2 = livelloNodo(albero, target2, 0);
    if (livello2 != -1) {
        printf("Il nodo %d si trova al livello %d.\n", target2, livello2);
    } else {
        printf("Il nodo %d NON e' nell'albero (livello %d).\n", target2, livello2);
    }

    freeBtree(albero);
}