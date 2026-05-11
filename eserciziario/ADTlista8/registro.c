#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prenotazione.h"
#include "registro.h"

struct node{
    Prenotazione info;
    struct node *next;
};

struct registro{
    struct node *head;
};

Registro newRegistro(){
    Registro registro=malloc(sizeof(struct registro));
        registro->head=NULL;
        return registro;
}

void addPrenotazione(Registro registro, Prenotazione prenotazione){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=prenotazione;
    newNode->next=NULL;
    if (registro->head == NULL){
        registro->head=newNode;
        return;
    }
    struct node *currentNode=registro->head;
    while (currentNode->next != NULL){
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
}

void removePrenotazione(Registro registro, char *nome){
    if (registro->head == NULL){
        printf("registro vuoto\n");
        return;
    }
    if (strcmp(getNome(registro->head->info), nome)==0){
        struct node *temp=registro->head;
        registro->head=registro->head->next;
        freePrenotazione(temp->info);
        free(temp);
        return;
    }
    struct node *currentNode=registro->head;
    while(currentNode->next != NULL && strcmp(getNome(currentNode->next->info), nome) != 0){
        currentNode=currentNode->next;
    }
    if (currentNode->next != NULL){
    struct node *temp=currentNode->next;
    currentNode->next=temp->next;
    freePrenotazione(temp->info);
    free(temp);
    }
}

int calcolaCoperti(Registro registro){
    struct node *currentNode=registro->head;
    int totale=0;
    while (currentNode != NULL){
        totale+=getNumeroPersone(currentNode->info);
        currentNode=currentNode->next;
    }
    return totale;
}

void printRegistro(Registro registro){
    struct node *currentNode=registro->head;
    while(currentNode != NULL){
        printPrenotazione(currentNode->info);
        currentNode=currentNode->next;
    }
}

void freeRegistro(Registro registro){
    struct node *currentNode=registro->head;
    while(currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        freePrenotazione(temp->info);
        free(temp);
    }
    free(registro);
}