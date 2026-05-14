#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket.h"
#include "centralino.h"

struct node{
    Ticket info;
    struct node *next;
};

struct centralino{
    struct node *head;
    struct node *tail;
};

Centralino newCentralino(){
    Centralino centralino=malloc(sizeof(struct centralino));
    centralino->head=NULL;
    centralino->tail=NULL;
    return centralino;
}

int isEmpty(Centralino centralino){
    if (centralino->head == NULL && centralino->tail == NULL){
        return 1;
    }
    return 0;
}

void enqueue(Centralino centralino, Ticket ticket){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=ticket;
    newNode->next=NULL;
    if (isEmpty(centralino)){
        centralino->head=newNode;
        centralino->tail=newNode;
    }
    else {
        centralino->tail->next=newNode;
        centralino->tail=newNode;
    }
}

Centralino dequeue(Centralino centralino){
    if (isEmpty(centralino)){
        return NULL;
    }
    struct node *temp=centralino->head;
    Ticket ticketRimosso=temp->info;
    centralino->head=centralino->head->next;
    if (centralino->head == NULL){
        centralino->tail=NULL;
    }
    free(temp);
    return ticketRimosso;
}

int contaChiamatePerReparto(Centralino centralino, char *repartoRichiesto){
    struct node *currentNode=centralino->head;
    int totale=0;
    while (currentNode != NULL){
        if(strcmp(getRepartoRichiesto(currentNode->info), repartoRichiesto)==0){
            totale+=1;
        }
        currentNode=currentNode->next;
    }
    printf("\nnumero di persone per il reparto %s-> %d\n\n", repartoRichiesto, totale);
}

void printCentralino(Centralino centralino){
    struct node *temp=centralino->head;
    while(temp != NULL){
        printTicket(temp->info);
        temp=temp->next;
    }
}

void freeCentralino(Centralino centralino){
    struct node *currentNode=centralino->head;
    while (currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        freeTicket(temp->info);
        free(temp);
    }
    free(currentNode);
}

