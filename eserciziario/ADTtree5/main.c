#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

int main(){
    Btree f3=buildBtree(createItem(3), newBtree(), newBtree());
    Btree f2=buildBtree(createItem(2), newBtree(), newBtree());
    Btree f7=buildBtree(createItem(7), newBtree(), newBtree());
    Btree f4=buildBtree(createItem(4), newBtree(), newBtree());

    Btree n5=buildBtree(createItem(5), f3, f2);
    Btree n8=buildBtree(createItem(8), f7, f4);

    Btree albero=buildBtree(createItem(10), n5, n8);

    printf("l'abero ha foglie-> ");
    printFoglie(albero);
    printf("\n");

    int numeroNodiInt=contaNodiInterni(albero);
    printf("L'albero ha %d nodi interni\n", numeroNodiInt);

    int target1=17;
    if (esistePercorsoSomma(albero, target1)==1){
        printf("Trovato il percorso che somma a %d\n", target1);
    }
    else{
        printf("Nessun percorso somma a %d\n", target1);
    }

    int target2=20;
    if (esistePercorsoSomma(albero, target2)==1){
        printf("Trovato il percorso che somma a %d\n", target2);
    }
    else{
        printf("Nessun percorso somma a %d\n", target2);
    }

    freeBtree(albero);


}