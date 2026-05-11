#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conto.h"
#include "transazione.h"

struct node{
    Transazione info;
    struct node *next;
};

struct conto{
    struct node *head;
};


Conto createConto(){
    Conto conto=malloc(sizeof(struct conto));
    conto->head=NULL;
    return conto;
}

void aggiungiTransazione(Conto conto, Transazione transazione){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info= transazione;
    newNode->next=conto->head;
    conto->head=newNode;
}

void annullaTransazione(Conto conto, int id){
    if (conto->head == NULL){
        return;
    }
    if (getId(conto->head->info)== id){
        struct node *temp=conto->head;
        conto->head=conto->head->next;
        freeTransazione(temp->info);
        free(temp);
        return;
    }
    struct node *currentNode=conto->head;
    while (currentNode->next != NULL && getId(currentNode->next->info) != id){
        currentNode=currentNode->next;
    }
    if (currentNode->next != NULL){
        struct node *temp=currentNode->next;
        currentNode->next=temp->next;
        freeTransazione(temp->info);
        free(temp);
    }
}

float calcolaSaldo(Conto conto){
    struct node *currentNode=conto->head;
    float importoTotale=0.0;
    while (currentNode != NULL){
        importoTotale+=getImporto(currentNode->info);
        currentNode=currentNode->next;
    }
    return importoTotale;
}

void stampaEstrattoConto(Conto conto){
    struct node *currentNode= conto->head;
    while(currentNode != NULL){
        printTransazione(currentNode->info);
        currentNode=currentNode->next;
    }
}

void freeConto(Conto conto){
    struct node *currentNode= conto->head;
    while (currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        freeTransazione(temp->info);
        free(temp);
    }
}