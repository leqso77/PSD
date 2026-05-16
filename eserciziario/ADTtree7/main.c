#include "btree.h"
#include "item.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    Btree f1= buildBtree(createItem(1), newBtree(), newBtree());

    Btree n3= buildBtree(createItem(3), f1, newBtree());
    Btree n8= buildBtree(createItem(8), newBtree(), newBtree());

    Btree n5= buildBtree(createItem(5), n3, n8);
    Btree n20= buildBtree(createItem(20), newBtree(), newBtree());

    Btree root= buildBtree(createItem(20), n5, n20);

    int numNodi=nodiInterni(root);
    printf("l'albero ha %d nodi interni\n", numNodi);

    if (isBilanciato(root) == 0){
        printf("Albero non bilanciato\n");
    }
    else{
        printf("Albero bilanciato\n");
    }

    Btree alberoCopia=cloneAlbero(root);

    freeBtree(root);

    int interniCopia=nodiInterni(alberoCopia);
    printf("nodi interni dell'albero clonto: %d\n", interniCopia);

    freeBtree(alberoCopia);

    return 0;
}