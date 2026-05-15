#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if (isEmpty(btree)){
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
    freeBtree(getLeft(btree));
    freeBtree(getRight(btree));
    freeItem(getBtreeRoot(btree));
    free(btree);
}

int sommaNodi(Btree btree){
    if(isEmpty(btree)){
        return 0;
    }
    int valCorrente=getValore(getBtreeRoot(btree));
    return valCorrente + sommaNodi(getLeft(btree)) + sommaNodi(getRight(btree));
}

int contaPari(Btree btree){
    if(isEmpty(btree)){
        return 0;
    }
    int valCorrente=getValore(getBtreeRoot(btree));
    int isPari=0;
    if (valCorrente % 2 == 0){
        isPari=1;
    }
    return isPari + contaPari(getLeft(btree)) + contaPari(getRight(btree));
}

int cercaValore(Btree btree, int target){
    if(isEmpty(btree)) {
        return 0;
    }

    if (getValore(getBtreeRoot(btree))== target){
        return 1;
    }
    if (cercaValore(getLeft(btree),target)==1){
        return 1;
    }
    return cercaValore(getRight(btree), target);
}
