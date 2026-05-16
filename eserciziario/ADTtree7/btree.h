#include "item.h"

typedef struct node *Btree;

Btree newBtree();
int isEmpty(Btree btree);
Btree buildBtree(Item item, Btree left, Btree right);
Item getBtreeRoot(Btree btree);
Btree getLeft(Btree btree);
Btree getRight(Btree btree);
void freeBtree(Btree btree);
int height(Btree btree);
Btree cloneAlbero(Btree btree);
int nodiInterni(Btree btree);
int isBilanciato(Btree btree);
