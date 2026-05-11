#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prodotto.h"
#include "carrello.h"

struct node{
    Prodotto info;
    struct node *next;
};

struct carrello{
    struct node *head;
};

Carrello createCarrello(){
    Carrello carrello=malloc(sizeof(struct carrello));
    carrello->head=NULL;

    return carrello;
}

void aggiungiAlCarrello(Carrello carrello, Prodotto prodotto){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=prodotto;
    newNode->next= carrello->head;
    carrello->head=newNode;
}

float calcolaTotale(Carrello carrello){
    float totale=0.0;
    struct node *currentNode=carrello->head;
    while(currentNode != NULL){
        totale=totale+getPrezzo(currentNode->info);
        currentNode=currentNode->next;
    }
    return totale;
}

void stampaCarrello(Carrello carrello){
    struct node *currentNode= carrello->head;

    if (currentNode == NULL){
        printf("carrello vuoto\n");
        return;
    }

    while (currentNode != NULL){
        printProdotto(currentNode->info);
        currentNode=currentNode->next;
    }
}

void svuotaCarrello(Carrello carrello){
    struct node *currentNode=carrello->head;
    
    while(currentNode != NULL){
        struct node *temp=currentNode;
        currentNode= currentNode->next;
        freeProdotto(temp->info);
        free(temp);
    }
    free(carrello);
}