#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "documento.h"
#include "stampante.h"

struct node{
    Documento info;
    struct node *next;
};

struct stampante{
    struct node *head;
    struct node *tail;
};

Stampante newStampante(){
    Stampante stampante=malloc(sizeof(struct stampante));
    stampante->head=NULL;
    stampante->tail=NULL;
    return stampante;
}

int isEmpty(Stampante stampante){
    if (stampante->head == NULL && stampante->tail == NULL){
        return 1;
    }
    return 0;
}

void enqueue(Stampante stampante, Documento documento){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=documento;
    newNode->next=NULL;

    if (isEmpty(stampante)){
        stampante->head=newNode;
        stampante->tail=newNode;
    }
    else {
        stampante->tail->next=newNode;
        stampante->tail=newNode;
    }
}

Documento dequeue(Stampante stampante){
    if (isEmpty(stampante)){
        return NULL;
    }
    struct node *currentNode=stampante->head;
    Documento documentoRimosso=currentNode->info;
    stampante->head=stampante->head->next;
    if (stampante->head == NULL){
        stampante->tail=NULL;
    }
    free(currentNode);
    return documentoRimosso;
}
int CalcolaTempo(Stampante stampante){
    struct node *temp=stampante->head;
    int tempo=0;
    while (temp != NULL){
        tempo=tempo+ getNumeroPagine(temp->info)*3;
        temp=temp->next;
    }
    return tempo;
}

void printStampante(Stampante stampante){
    struct node *currenteNode= stampante->head;
    while (currenteNode != NULL){
        printFile(currenteNode->info);
        currenteNode=currenteNode->next;
    }
}

void freeStampante(Stampante stampante){
    struct node *currentNode=stampante->head;
    while(currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        free(temp->info);
        free(temp);
    }
    free(currentNode);
}