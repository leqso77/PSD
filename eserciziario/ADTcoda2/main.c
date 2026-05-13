#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "documento.h"
#include "stampante.h"

int main(){
    Stampante stampante=newStampante();
    enqueue(stampante, newDocumento("lezione 1", 40));
    enqueue(stampante, newDocumento("lezione 2", 45));
    enqueue(stampante, newDocumento("lezione 3", 50));
    enqueue(stampante, newDocumento("lezione 4", 55));

    printStampante(stampante);
    printf("ET: %d\n", CalcolaTempo(stampante));

    Documento documento1=dequeue(stampante);
    if(documento1 != NULL){
        printf("Rimosso: ");
        printFile(documento1);
        freeDocumento(documento1);
    }

    Documento documento2=dequeue(stampante);
    if(documento2 != NULL){
        printf("Rimosso: ");
        printFile(documento2);
        freeDocumento(documento2);
    }

    printStampante(stampante);
    printf("ET: %d\n", CalcolaTempo(stampante));

    freeStampante(stampante);

    return 0;
}