#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"


int main (){
    Stack s= createStack();

    Item brano1;
    strcpy(brano1.titolo ,"Bohemian Rhapsody");
    strcpy(brano1.artista ,"Queen");    

    Item brano2;
    strcpy(brano2.titolo ,"Stairway to Heaven");
    strcpy(brano2.artista ,"Led Zeppelin");

    Item brano3;
    strcpy(brano3.titolo, "Shape of You");
    strcpy(brano3.artista, "Ed Sheeran");

    push(&s, brano1);
    push(&s, brano2);
    push(&s, brano3);

    printf("vuoi toranre indietro? (1 per si, 0 per no): ");
    int scelta;
    scanf("%d", &scelta);

    if(scelta == 1){
        Item branoAscoltato = pop(&s);
        printf("Brano ascoltato: ");
        printItem(branoAscoltato);
    }
    else if (scelta == 0){
        printf("Brano in ascolto: ");
        printItem(top(s));
    }
    else{
        printf("Scelta non valida.\n");
    }
    freeStack(&s);
    return 0;
}