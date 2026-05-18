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
    if (isEmpty(btree)){
    return;
    }
    freeBtree(btree->left);
    freeBtree(btree->right);
    freeItem(btree->info);
    free(btree);
}

int isDegenereTail(Btree btree){
    if(isEmpty(btree)){
        return 1;
    }

    if(!isEmpty(getLeft(btree)) && !isEmpty(getRight(btree))){
        return 0;
    }
    if(!isEmpty(btree)){
        return isDegenereTail(getLeft(btree));
    }
    else{
        return isDegenereTail(getRight(btree));
    }
}

int lunghezzaRamoDestroTail(Btree btree, int accumulatore){
    if(isEmpty(btree)){
        return accumulatore;
    }
    return lunghezzaRamoDestroTail(getRight(btree), accumulatore+1);
}

int cercaSoloASinistraTail(Btree btree, int target){
    if(isEmpty(btree)){
        return 0;
    }
    if(getValore(getBtreeRoot(btree)) == target){
        return 1;
    }
    return cercaSoloASinistraTail(getLeft(btree), target);
}

