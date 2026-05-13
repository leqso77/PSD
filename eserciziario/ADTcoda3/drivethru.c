#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordine.h"
#include "drivethru.h"

struct node{
    Ordine info;
    struct node *next;
};

struct drivethru{
    struct node *head;
    struct node *tail;
};

Drivethru newDrivethru(){
    Drivethru drivethru=malloc(sizeof(struct drivethru));
    drivethru->head=NULL;
    drivethru->tail=NULL;
    return drivethru;
}

int isEmpty(Drivethru drivethru){
    if (drivethru->head == NULL && drivethru->tail == NULL){
        return 1;
    }
    return 0;
}

void enqueue(Drivethru drivethru, Ordine ordine){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=ordine;
    newNode->next=NULL;

    if (drivethru->head == NULL){
        drivethru->head=newNode;
        drivethru->tail=newNode;
    }

    else {
        drivethru->tail->next=newNode;
        drivethru->tail=newNode;
    }
}

Ordine dequeue(Drivethru drivethru){
    if (isEmpty(drivethru)){
        return NULL;
    }
    struct node *currentNode=drivethru->head;
    Ordine ordineSuccessivo=currentNode->info;
    drivethru->head=drivethru->head->next;
    if (drivethru->head == NULL){
        drivethru->tail=NULL;
    }
    free(currentNode);
    return ordineSuccessivo;
}

int cercaOrdine(Drivethru drivethru, int numeroOrdine){
    struct node *currentNode=drivethru->head;
    while(currentNode != NULL){
        if (getNumeroOrdine(currentNode->info) == numeroOrdine){
            printf("ordine in coda\n");
            return 1;
        }
        currentNode=currentNode->next;
    }
    printf("ordine fuori coda\n");
    return 0;
}

void printDrivethru(Drivethru drivethru){
    struct node *currentnode=drivethru->head;
    while(currentnode != NULL){
        printOrdine(currentnode->info);
        currentnode=currentnode->next;
    }
}

void freeDrivethru(Drivethru drivethru){
    struct node *currentNode=drivethru->head;
    while (currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        freeOrdine(temp->info);
        free(temp);
    }
    free(currentNode);
}