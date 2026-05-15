#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    if(isEmpty(btree)){
        return;
    }
    freeBtree(getLeft(btree));
    freeBtree(getRight(btree));
    freeItem(btree->info);
    free(btree);
}

void printPreOrder(Btree btree){
    if(isEmpty(btree)){
        return;
    }
    printItem(getBtreeRoot(btree));
    printPreOrder(getLeft(btree));
    printPreOrder(getRight(btree));
}

int trovaMassimo(Btree btree){
    if (isEmpty(btree)){
        return -1;
    }
    int maxValore=getValore(getBtreeRoot(btree));
    if (!isEmpty(getLeft(btree))){
        int maxSinistra=trovaMassimo(getLeft(btree));
        if(maxSinistra > maxValore){
            maxValore=maxSinistra;
        }
    }
    if (!isEmpty(getRight(btree))){
        int maxDestra= trovaMassimo(getRight(btree));
        if (maxDestra > maxValore){
            maxValore=maxDestra;
        }
    }
    return maxValore;
}



void printLivello(Btree btree, int livello){
if (isEmpty(btree)){
    return;
}
if (livello == 0){
    printItem(getBtreeRoot(btree));
}

printLivello(getLeft(btree), livello-1);
printLivello(getRight(btree), livello-1);
}

void specchio(Btree btree){
    if (isEmpty(btree)){
        return;
    }
    Btree temp=btree->left;
    btree->left=btree->right;
    btree->right=temp;

    specchio(btree->left);
    specchio(btree->right);
}