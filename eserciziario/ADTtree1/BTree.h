#include "item.h"

typedef struct node *BTree;

BTree newBTree();
int isEmpty(BTree btree);
BTree buildBTree(Item info, BTree left, BTree right);
Item getBTreeRoot(BTree btree);
BTree getLeft(BTree btree);
BTree getRight(BTree btree);

int numNodi(BTree btree);
int height(BTree btree);
int equalBTree(BTree btr1, BTree btr2);

void freeBTree(BTree btree);