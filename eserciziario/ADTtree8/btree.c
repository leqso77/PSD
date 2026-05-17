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
    if(isEmpty(btree)){
        return NULL;
    }
    return btree->left;
}

Btree getRight(Btree btree){
    if(isEmpty(btree)){
        return NULL;
    }
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

void printPreOrder(Btree btree){
    if(isEmpty(btree)){
        return;
    }
    printItem(getBtreeRoot(btree));
    printPreOrder(getLeft(btree));
    printPreOrder(getRight(btree));
}

int isStrutturaUguale(Btree b1, Btree b2){
    if (isEmpty(b1) && isEmpty(b2)){
        return 1;
    }
    if ((!isEmpty(b1) && isEmpty(b2)) || (isEmpty(b1) && !isEmpty(b2))){
        return 0;
    }

    return isStrutturaUguale(getLeft(b1), getLeft(b2)) && isStrutturaUguale(getRight(b1), getRight(b2));
}

int altezzaMinima(Btree btree){
    if(isEmpty(btree)){
        return 0;
    }
    if(isEmpty(getLeft(btree)) && isEmpty(getRight(btree))){
        return 1;
    }
    if (isEmpty(getLeft(btree))){
        return 1 + altezzaMinima(getRight(btree));
    }
    
    if(isEmpty(getRight(btree))){
        return 1 + altezzaMinima(getLeft(btree));
    }
    int hLeft=altezzaMinima(getLeft(btree));
    int hRight=altezzaMinima(getRight(btree));
    if (hLeft < hRight){
        return hLeft + 1;
    }
    else{
        return hRight + 1;
    }
}

Btree prunaFoglie(Btree btree){
    if(isEmpty(btree)){
        return NULL;
    }
    if(isEmpty(getLeft(btree)) && isEmpty(getRight(btree))){
        freeItem(getBtreeRoot(btree));
        free(btree);
        return NULL;
    }
    btree->left=prunaFoglie(getLeft(btree));
    btree->right=prunaFoglie(getRight(btree));

    return btree;
}