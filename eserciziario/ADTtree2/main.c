#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "Btree.h"

int main(){
    Btree foglia4=buildBtree(createItem(4), newBtree(), newBtree());
    Btree foglia5=buildBtree(createItem(5), newBtree(), newBtree());
    Btree foglia6=buildBtree(createItem(6), newBtree(), newBtree());
    Btree node2=buildBtree(createItem(2), foglia4, foglia5);
    Btree node3=buildBtree(createItem(3), newBtree(), foglia6);
    Btree albero=buildBtree(createItem(1), node2, node3);

    printf("Visita Pre-order: \n");
    printPreOrder(albero);
    printf("\n\n");

    printf("Visita In-Order: \n");
    printInOrder(albero);
    printf("\n\n");

    printf("Visita Post-order: \n");
    printPostOrder(albero);
    printf("\n\n");

    int foglie= countLeaves(albero);
    printf("L'albero ha %d foglie\n", foglie);
    freeBtree(albero);

    return 0;
}