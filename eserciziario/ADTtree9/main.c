#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "btree.h"

int main(){
    Btree f40=buildBtree(createItem(40), newBtree(), newBtree());
    Btree f30=buildBtree(createItem(30), f40,newBtree());
    Btree f20=buildBtree(createItem(20), newBtree(), f30);
    Btree root1=buildBtree(createItem(10), newBtree(), f20);

    Btree f50=buildBtree(createItem(50), newBtree(), newBtree());
    Btree f150=buildBtree(createItem(150), newBtree(), newBtree());
    Btree root2=buildBtree(createItem(100), f50, f150);


    if (isDegenereTail(root1)){
        printf("l'albero 1 e' DEGENERE\n");
    }
    else{
        printf("l'albero 1 non e' DEGENERE\n");
    }
    if(!isDegenereTail(root2)){
        printf("l'albero 2 non e' DEGENERE\n");
    }

    int nodiDestra=lunghezzaRamoDestroTail(root1, 0);
    printf("nodi denl ramo a destra del root sono-> %d \n", nodiDestra);

    if(cercaSoloASinistraTail(root2, 50)){
        printf("trovato il 50 a sinistra\n");
    }
    if(!cercaSoloASinistraTail(root2, 150)){
        printf("il 150 non e' stato trovato");
    }

    freeBtree(root1);
    freeBtree(root2);
    return 0;
}