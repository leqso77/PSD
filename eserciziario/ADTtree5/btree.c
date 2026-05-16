#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

struct node {
    Item info;
    Btree left;
    Btree right;
};

Btree newBtree(){
    return NULL;
}

int isEmpty(Btree btree){
    return btree == NULL;
}

Btree buildBtree(Item item, Btree left, Btree right){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=item;
    newNode->left=left;
    newNode->right=right;
    return newNode;
}

Item getBtreeRoot(Btree btree){
    if(isEmpty(btree)){
        return NULL;
    }
    return btree->info;
}

Btree getLeft(Btree btree){
    return btree->left;
}

Btree getRight(Btree btree){
    return btree->right;
}

void freeBtree(Btree btree){
    if(isEmpty(btree)){
        return;
    }
    freeBtree(btree->left);
    freeBtree(btree->right);
    freeItem(btree->info);
    free(btree);
}

int contaNodiInterni(Btree btree){
    if(isEmpty(btree)){
        return 0;
    }

    if (isEmpty(getLeft(btree)) && isEmpty(getRight(btree))){
        return 0;
    }

    return 1 + contaNodiInterni(getLeft(btree)) + contaNodiInterni(getRight(btree));
}


void printFoglie(Btree btree){
    if (isEmpty(btree)){
        return;
    }

    if (isEmpty(getLeft(btree)) && isEmpty(getRight(btree))){
        printItem(getBtreeRoot(btree));
    }
    printFoglie(getLeft(btree));
    printFoglie(getRight(btree));
}

int esistePercorsoSomma(Btree btree, int target){
    if (isEmpty(btree)){
        return 0;
    }
    
    int valoreCorrente=getValore(getBtreeRoot(btree));
    int sommaRimanente=target - valoreCorrente;

    if(isEmpty(getLeft(btree)) && isEmpty(getRight(btree))){
        if (sommaRimanente==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int trovatoASinistra=esistePercorsoSomma(getLeft(btree), sommaRimanente);
    int trovatoADestre=esistePercorsoSomma(getRight(btree), sommaRimanente);

    if(trovatoASinistra == 1 || trovatoADestre ==1){
        return 1;
    }
    return 0;

}
