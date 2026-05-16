#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "btree.h"

struct node{
    Item info;
    Btree left;
    Btree right;
};

Btree newBtree(){
    return NULL;
}

int isEmpty(Btree btree){
    return btree==NULL;
}

Btree buildBtree(Item item, Btree left, Btree right){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->info=item;
    newNode->left=left;
    newNode->right=right;
    return newNode;
}

Item getBtreeRoot(Btree btree){
    if (isEmpty(btree)){
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
    freeBtree(btree->left);
    freeBtree(btree->right);
    freeItem(btree->info);
    free(btree);
}

int contaNodiSingoli(Btree btree){
    if (isEmpty(btree)){
        return 0;
    }
    int isSingolo=0;
    if((!isEmpty(getLeft(btree)) && isEmpty(getRight(btree))) || (isEmpty(getLeft(btree)) && !isEmpty(getRight(btree)))){
        isSingolo=1;
    }
    return isSingolo + contaNodiSingoli(getLeft(btree)) + contaNodiSingoli(getRight(btree));
}

int sommaFoglie(Btree btree){
    if(isEmpty(btree)){
        return 0;
    }
    if (isEmpty(getLeft(btree)) && isEmpty(getRight(btree))){
        return getValore(getBtreeRoot(btree));
    }
    return sommaFoglie(getLeft(btree)) + sommaFoglie(getRight(btree));
}

int livelloNodo(Btree btree, int target, int livelloAttuale){
    if(isEmpty(btree)){
        return -1;
    }
    if (getValore(getBtreeRoot(btree)) == target){
        return livelloAttuale;
    }

    int livelloSinistra=livelloNodo(getLeft(btree), target, livelloAttuale + 1);

    if (livelloSinistra != -1){
        return livelloSinistra;
    }

    return livelloNodo(getRight(btree), btree, livelloAttuale + 1);
}

