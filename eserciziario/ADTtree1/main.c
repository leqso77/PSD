#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "BTree.h"

int main(){
    BTree foglia2 =buildBTree(createItem(2), newBTree(), newBTree());
    BTree ramo5=buildBTree(createItem(5), foglia2, newBTree());
    BTree ramo15=buildBTree(createItem(15), newBTree(), newBTree());

    BTree albero1=buildBTree(createItem(10), ramo5, ramo15);

    BTree foglia2b =buildBTree(createItem(2), newBTree(), newBTree());
    BTree ramo5b=buildBTree(createItem(5), foglia2b, newBTree());
    BTree ramo15b=buildBTree(createItem(15), newBTree(), newBTree());

    BTree albero2=buildBTree(createItem(10), ramo5b, ramo15b);

    BTree ramo5c=buildBTree(createItem(5), newBTree(), newBTree());
    BTree ramo15c=buildBTree(createItem(15), newBTree(), newBTree());

    BTree albero3=buildBTree(createItem(10), ramo5c, ramo15c);

    printf("numeor totale di nodi: %d\n", numNodi(albero1));
    printf("altezza dell'albero-> %d\n", height(albero1));

    printf("CONFRONTI\n");
    if (equalBTree(albero1, albero2)){
        printf("albero 1 e albero 2 sono UGUALI\n");
    }
    else {
        printf("albero 1 e albeero 2 NON sono uguali\n");
    }

    if (!equalBTree(albero1, albero3)){
        printf("albero 1 e albero 3 sono DIVERSI\n");
    }

    else{
        printf("albero 1 e albero 2 NON sono diversi\n");
    }
    freeBTree(albero1);
    freeBTree(albero2);
    freeBTree(albero3);

    return 0;
}