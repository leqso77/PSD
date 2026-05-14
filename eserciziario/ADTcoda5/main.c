#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "autolavaggio.h"

int main(){
    Autolavaggio autolavaggio=newAutolavaggio();
    
    enqueue(autolavaggio, newAuto("AB123BC", "Premium", 20.00));
    enqueue(autolavaggio, newAuto("AB123DC", "Base", 20.00));
    enqueue(autolavaggio, newAuto("AB156BF", "Completo", 20.00));
    enqueue(autolavaggio, newAuto("AB235SS", "Base", 20.00));
    enqueue(autolavaggio, newAuto("AB124HG", "Completo", 20.00));
    enqueue(autolavaggio, newAuto("AB126XV", "Premium", 20.00));
    enqueue(autolavaggio, newAuto("AB235DG", "Premium", 20.00));

    printAutolavaggio(autolavaggio);

    contaLavaggiPremium(autolavaggio, "Premium");

    Auto autosuccessivo=dequeue(autolavaggio);
    if (autosuccessivo != NULL){
        printf("successivo: ");
        printAuto(autosuccessivo);
        free(autosuccessivo);
    }

    Auto autosuccessivo2=dequeue(autolavaggio);
    if (autosuccessivo2 != NULL){
        printf("successivo: ");
        printAuto(autosuccessivo2);
        free(autosuccessivo2);
    }

    printAutolavaggio(autolavaggio);

    contaLavaggiPremium(autolavaggio, "Premium");

    freeAutolavaggio(autolavaggio);

    return 0;
}