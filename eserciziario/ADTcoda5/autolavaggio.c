#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "autolavaggio.h"

struct node {
    Auto info;
    struct node *next;
};

struct autolavaggio{
    struct node *head;
    struct node *tail;
};

Autolavaggio newAutolavaggio(){
    Autolavaggio autolavaggio=malloc(sizeof(struct autolavaggio));
    autolavaggio->head=NULL;
    autolavaggio->tail=NULL;
    return autolavaggio;
}

int isEmpty(Autolavaggio autolavaggio){
    if (autolavaggio->head == NULL && autolavaggio ->tail == NULL){
        return 1;
    }
    return 0;
}


void enqueue(Autolavaggio autolavaggio, Auto automobile){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=automobile;
    newNode->next=NULL;
    if (isEmpty(autolavaggio)){
        autolavaggio->head=newNode;
        autolavaggio->tail=newNode;
    }
    autolavaggio->tail->next=newNode;
    autolavaggio->tail=newNode;
}


Auto dequeue(Autolavaggio autolavaggio){
    if(isEmpty(autolavaggio)){
        return NULL;
    }
    struct node *currentNode=autolavaggio->head;
    Auto autorimosso=currentNode->info;
    autolavaggio->head=autolavaggio->head->next;
    if(autolavaggio->head == NULL){
        autolavaggio->tail=NULL;
    }
    free(currentNode);
    return autorimosso;
}

int contaLavaggiPremium(Autolavaggio autolavaggio, char *programmaLavaggio){
    if (isEmpty(autolavaggio)){
        return 1;
    }
    struct node *currentNode=autolavaggio->head;
    int totale=0;
    while(currentNode != NULL){
        if (strcmp(getProgrammaLavaggio(currentNode->info), programmaLavaggio)==0){
            totale+=1;
        }
        currentNode=currentNode->next;
    }
    printf("auto in coda per il lavaggio premium: %d\n", totale);
    return 0;
}

void printAutolavaggio(Autolavaggio autolavaggio){
    struct node *currentNode=autolavaggio->head;
    while (currentNode != NULL){
        printAuto(currentNode->info);
        currentNode=currentNode->next;
    }
}

void freeAutolavaggio(Autolavaggio autolavaggio){
    struct node *currentNode=autolavaggio->head;
    while(currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        freeAuto(temp->info);
        free(temp);
    }
    free(currentNode);
}


