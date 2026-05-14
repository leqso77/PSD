#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "BTree.h"

struct node{
    Item info;
    BTree left;
    BTree right;
};

BTree newBTree(){
    return NULL;
}

int isEmpty(BTree btree){
    if(btree == NULL){
        return 1;
    }
    return 0;
}

BTree buildBTree(Item info, BTree left, BTree right){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=info;
    newNode->left=left;
    newNode->right=right;
    return newNode;
}

Item getBTreeRoot(BTree btree){
    if (isEmpty(btree)){
        return NULL;
    }
    return btree->info;
}

BTree getLeft(BTree btree){
    if(isEmpty(btree)){
        return NULL;
    }
    return btree->left;
}

BTree getRight(BTree btree){
    if(isEmpty(btree)){
        return NULL;
    }
    return btree->right;
}

int numNodi(BTree btree){
    if (isEmpty(btree)){
        return 0;
    }
    return 1+ numNodi(getLeft(btree)) + numNodi(getRight(btree));
}

int height(BTree btree){
    if (isEmpty(btree) || (isEmpty(getLeft(btree)) && isEmpty(getRight(btree)))){
        return 0;
    }
    int hleft=height(getLeft(btree));
    int hright=height(getRight(btree));

    if (hleft>hright){
        return hleft+1;
    }
    else{ 
        return hright+1;
    }
}

int equalBTree(BTree btr1, BTree btr2){
    if (isEmpty(btr1) && isEmpty(btr2)){
        return 1;
    }
    if (isEmpty(btr1) || isEmpty(btr2)){
        return 0;
    }
    if (equal(getBTreeRoot(btr1), getBTreeRoot(btr2))){
        return equalBTree(getLeft(btr1), getLeft(btr2)) && equalBTree(getRight(btr1), getRight(btr2));
    }
    return 0;
}
void freeBTree(BTree btree){
    if (isEmpty(btree)){
        return;
    }
    freeBTree(getLeft(btree));
    freeBTree(getRight(btree));
    freeItem(getBTreeRoot(btree));
    free(btree);
}