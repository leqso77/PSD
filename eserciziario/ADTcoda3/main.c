#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordine.h"
#include "drivethru.h"


int main(){
    
    Drivethru drivethru=newDrivethru();

    enqueue(drivethru, newOrdine(1, "menu 1", 15.00));
    enqueue(drivethru, newOrdine(2, "menu 2", 17.00));
    enqueue(drivethru, newOrdine(3, "menu 3", 11.00));
    enqueue(drivethru, newOrdine(4, "menu 4", 14.00));
    enqueue(drivethru, newOrdine(5, "menu 5", 10.00));

    printDrivethru(drivethru);

    cercaOrdine(drivethru, 4);

    Ordine ordineConsegnato=dequeue(drivethru);
    if (ordineConsegnato != NULL){
        printf("consegno: ");
        printOrdine(ordineConsegnato);
        freeOrdine(ordineConsegnato);
    }

    Ordine ordineConsegnato2=dequeue(drivethru);
    if (ordineConsegnato2 != NULL){
        printf("consegno: ");
        printOrdine(ordineConsegnato2);
        freeOrdine(ordineConsegnato2);
    }

    printDrivethru(drivethru);

    cercaOrdine(drivethru, 5);

    freeDrivethru(drivethru);


}