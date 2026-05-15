#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

int main(){
    Btree f3=buildBtree(createItem(3), newBtree(), newBtree());
    Btree f8=buildBtree(createItem(8), newBtree(), newBtree());
    Btree f25=buildBtree(createItem(25), newBtree(), newBtree());

    Btree n5=buildBtree(createItem(5), f3, f8);
    Btree n20=buildBtree(createItem(20), newBtree(), f25);

    Btree albero=buildBtree(createItem(10), n5, n20);

    int massimo=trovaMassimo(albero);
    printf("valore massimo-> %d\n", massimo);

    printf("nodi a livello 2\n");
    printf("attesi 3, 8, 25\n");
    printLivello(albero, 2);
    printf("\n");

    printf("albero specchiato pre-oreder originale: \n");
    printPreOrder(albero);
    specchio(albero);
    printf("\n");

    printf("albero specchiato pre-order specchiato: \n");
    printPreOrder(albero);
    printf("\n");

    freeBtree(albero);

    return 0;
}