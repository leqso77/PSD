#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "partita.h"
#include "classifica.h"

struct node{
    Partita info;
    struct node *next;
};

struct classifica{
    struct node *head;
};

Classifica createClassifica(){
    Classifica classifica=malloc(sizeof(struct classifica));
    classifica->head=NULL;
    return classifica;
}

void aggiungiInClassifica(Classifica classifica, Partita partita){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=partita;
    
    if (classifica->head == NULL || getPunteggio(partita) > getPunteggio(classifica->head->info)){
        newNode->next=classifica->head;
        classifica->head=newNode;
        return;
    }

    struct node *prec=NULL;
    struct node *currentNode=classifica->head;

    while (currentNode != NULL && getPunteggio(currentNode->info) >= getPunteggio(partita)){
        prec=currentNode;
        currentNode=currentNode->next;
    }
    prec->next=newNode;
    newNode->next=currentNode;
}

void stampaClassifica(Classifica classifica){
    struct node *currentNode=classifica->head;

    if(classifica == NULL){
        return;
    }

    printf("Classifica: \n");
    while(currentNode != NULL){
    stampaPartita(currentNode->info);
    currentNode=currentNode->next;        
    }
}

void freeClassifica(Classifica classifica){
    struct node *currentNode=classifica->head;
    while(currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        free(temp->info);
        free(temp);
    }
    free(classifica);
}