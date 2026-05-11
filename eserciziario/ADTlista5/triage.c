#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paziente.h"
#include "triage.h"

struct node{
    Paziente info;
    struct node *next;
};

struct salaAttesa{
    struct node *head;
};

SalaAttesa createSalaAttesa(){
    SalaAttesa salaAttesa=malloc(sizeof(struct salaAttesa));
    salaAttesa->head=NULL;
    return salaAttesa;
}

void aggiungiPaziente(SalaAttesa salaAttesa, Paziente paziente){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=paziente;

    if (salaAttesa->head == NULL || getCodice(paziente) < getCodice(salaAttesa->head->info)){
        newNode->next= salaAttesa->head;
        salaAttesa->head=newNode;
        return;
    }

    struct node *prec=NULL;
    struct node *currentNode=salaAttesa->head;

    while (currentNode != NULL && getCodice(currentNode->info)<=getCodice(paziente)){
        prec=currentNode;
        currentNode=currentNode->next;
    }
    prec->next=newNode;
    newNode->next=currentNode;
}

void chiamaProssimo(SalaAttesa salaAttesa){
    if (salaAttesa->head==NULL){
        printf("nessun paziente in attesa\n");
        return;
    }
    struct node *temp=salaAttesa->head;
    salaAttesa->head=salaAttesa->head->next;
    printPaziente(temp->info);

    freePaziente(temp->info);
    free(temp);
}

void printSalaAttesa(SalaAttesa salaAttesa){
    if(salaAttesa->head == NULL){
        printf("sala d'attesa vuota");
        return;
    }

    struct node *currentNode=salaAttesa->head;
    printf("pazienti in sala: \n");
    while (currentNode != NULL){
        printPaziente(currentNode->info);
        currentNode=currentNode->next;
    }
}

void freeSalaAttesa(SalaAttesa salaAttesa){
    struct node *currentNode=salaAttesa->head;
    while(currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        freePaziente(temp->info);
        free(temp);
    }
    free(salaAttesa);
}