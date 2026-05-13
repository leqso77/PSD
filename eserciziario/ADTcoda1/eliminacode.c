#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cliente.h"
#include "eliminacode.h"

struct node{
    Cliente info;
    struct node *next;
};

struct eliminacode{
    struct node *head;
    struct node *tail;
};

Eliminacode createEliminacode(){
    Eliminacode eliminacode=malloc(sizeof(struct eliminacode));
    eliminacode->head=NULL;
    eliminacode->tail=NULL;
    return eliminacode;
}

int isEmpty(Eliminacode eliminacode){
    if (eliminacode->head == NULL && eliminacode->tail== NULL){
        return 1;
    }
    return 0;
}

void enqueue(Eliminacode eliminacode, Cliente cliente){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=cliente;
    newNode->next=NULL;

    if (isEmpty(eliminacode)){
        eliminacode->head=newNode;
        eliminacode->tail=newNode;
    }
    else{
        eliminacode->tail->next=newNode;
        eliminacode->tail=newNode;
    }
}

Cliente dequeue(Eliminacode eliminacode){
    if (isEmpty(eliminacode)){
        return NULL;
    }
    struct node *currentNode=eliminacode->head;
    Cliente clienteServito=currentNode->info;
    eliminacode->head=eliminacode->head->next;

    if (eliminacode->head==NULL){
        eliminacode->tail=NULL;
    }
    free(currentNode);
    return clienteServito;
}

void printEliminacode(Eliminacode eliminacode){
    struct node *temp=eliminacode->head;
    while(temp != NULL){
        printCliente(temp->info);
        temp=temp->next;
    }
}

void freeEliminacode(Eliminacode eliminacode){
    struct node *currentNode=eliminacode->head;
    while (currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=temp->next;
        
        freeCliente(temp->info);
        free(temp);
    }
    free(eliminacode);
}

