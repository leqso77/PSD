#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "veicolo.h"
#include "officina.h"

struct node{
    Veicolo info;
    struct node *next;
};

struct officina{
    struct node *head;
};

Officina createOfficina(){
    Officina officina=malloc(sizeof(struct officina));
    officina->head=NULL;
    return officina;
}

void addVeicolo(Officina officina, Veicolo veicolo){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=veicolo;
    newNode->next=NULL;
    if (officina->head == NULL){
        newNode->next=officina->head;
        officina->head=newNode;
        return;
    }
    struct node *currentNode=officina->head;
    while(currentNode->next != NULL){
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
}

void removeVeicolo(Officina officina, char *targa){
    if (officina->head == NULL){
        printf("officina vuota\n");
        return;
    }
    if(strcmp(getTarga(officina->head->info), targa)== 0){
        struct node *temp=officina->head;
        officina->head=officina->head->next;
        freeVeicolo(temp->info);
        free(temp);
    }

    struct node *currentNode=officina->head;
    while (currentNode->next != NULL && strcmp(getTarga(currentNode->next->info), targa) != 0){
        currentNode=currentNode->next;
    }
    if (currentNode->next != NULL){
        struct node *temp=currentNode->next;
        currentNode->next=temp->next;
        freeVeicolo(temp->info);
        free(temp);
    }
}

int calcoloIncasso(Officina officina){
    struct node *currentNode=officina->head;
    float totale=0.0;
    while (currentNode != NULL){
        totale+=getPrezzoRip(currentNode->next->info);
        currentNode=currentNode->next;
    }
    return totale;
}

void dannoMaggiore(Officina officina){
    
}



