#include "btree.h"
#include "item.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
int height(Btree btree){
    if(isEmpty(btree) || (isEmpty(getLeft(btree)) && isEmpty(getRight(btree)))){
        return 0;
    }

    int hLeft=height(getLeft(btree));
    int hRight=height(getRight(btree));
    if (hLeft > hRight){
        return hLeft +1;
    }
    else{
    return hRight +1;
    }
}


Btree cloneAlbero(Btree btree){
    if(isEmpty(btree)){
        return newBtree();
    }
    int numero=getValore(getBtreeRoot(btree));
    Item rootClone=createItem(numero);
    
    return buildBtree(rootClone, cloneAlbero(getLeft(btree)), cloneAlbero(getRight(btree)));
}

int nodiInterni(Btree btree){
    if (isEmpty(btree)){
        return 0;
    }

    if (getLeft(btree) == NULL && getRight(btree) == NULL){
        return 0;
    }

   return 1 + nodiInterni(getLeft(btree)) + nodiInterni(getRight(btree));
}

int isBilanciato(Btree btree){
    if (isEmpty(btree)){
        return 1;
    }
    int hLeft=(height(getLeft(btree)));
    int hRight=(height(getRight(btree)));

    int assoluto= hLeft - hRight;
    if(assoluto < 0){
        assoluto=-assoluto;
    }

    if(assoluto <= 1 && isBilanciato(getLeft(btree)) == 1 && isBilanciato(getRight(btree)) == 1){
        return 1;
    }
    else{
        return 0;
    }
}
