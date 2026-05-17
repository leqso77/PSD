#include "item.h"

typedef struct node *Btree;

Btree newBtree();
int isEmpty(Btree btree);
Btree buildBtree(Item item, Btree left, Btree right);
Item getBtreeRoot(Btree btree);
Btree getLeft(Btree btree);
Btree getRight(Btree btree);
void freeBtree(Btree btree);
void printPreOrder(Btree btree);

int isStrutturaUguale(Btree b1, Btree b2);
int altezzaMinima(Btree btree);
Btree prunaFoglie(Btree btree);