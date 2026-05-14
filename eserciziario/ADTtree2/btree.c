#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "Btree.h"

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
    if (isEmpty(btree)){
        return NULL;
    }
    return btree->info;
}

Btree getLeft(Btree btree){
    if (isEmpty(btree)){
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
    freeBtree(getLeft(btree));
    freeBtree(getRight(btree));
    freeItem(getBtreeRoot(btree));
    free(btree);
}

void printPreOrder(Btree btree){
    if (isEmpty(btree)){
        return;
    }
    printItem(getBtreeRoot(btree));
    printPreOrder(getLeft(btree));
    printPreOrder(getRight(btree));
}

void printInOrder(Btree btree){
    if (isEmpty(btree)){
        return;
    }

    printInOrder(getLeft(btree));
    printItem(getBtreeRoot(btree));
    printInOrder(getRight(btree));
}

void printPostOrder(Btree btree){
    if(isEmpty(btree)){
        return;
    }
    printPostOrder(getLeft(btree));
    printPostOrder(getRight(btree));
    printItem(getBtreeRoot(btree));
}

int countLeaves(Btree btree){
    if(isEmpty(btree)){
        return 0;
    }
    if(isEmpty(getLeft(btree)) && isEmpty(getRight(btree))){
        return 1;
    }
    return countLeaves(getLeft(btree)) + countLeaves(getRight(btree));
}