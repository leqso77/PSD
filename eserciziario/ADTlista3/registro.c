#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "studente.h"
#include "registro.h"

struct node{
    Studente info;
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

void aggiungiStudnete(Registro registro, Studente studente){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=studente;
    newNode->next=registro->head;
    registro->head=newNode;
}

Studente cercaPerMatricola(Registro registro, char *matricola){
    struct node *currentNode=registro->head;
    while (currentNode != NULL){
        if (strcmp(getMatricola(currentNode->info), matricola)==0){
            return currentNode->info;
        }
        currentNode=currentNode->next;
    }
    return NULL;
}

void rimuoviStudente(Registro registro, char *matricola){
    if (registro->head == NULL){
        return;
    }

    if (strcmp(getMatricola(registro->head->info), matricola)==0){
        struct node *temp=registro->head;
        registro->head=registro->head->next;
        freeStudente(temp->info);
        free(temp);

        return;
    }
    struct node *pre=registro->head;
    struct node *currenNode=registro->head->next;

    while (currenNode != NULL){
        if (strcmp(getMatricola(currenNode->info), matricola)==0){
            pre->next=currenNode->next;
            freeStudente(currenNode->info);
            free(currenNode);
            return;
        }
        pre=currenNode;
        currenNode=currenNode->next;
    }
}

void stampaRegistro(Registro registro){
    struct node *currentNode=registro->head;
    if (currentNode == NULL){
        return;
    }
    printf("elenco studenti: \n");
    while(currentNode != NULL){
        printStudente(currentNode->info);
        currentNode=currentNode->next;
    }
}

void freeRegistro(Registro registro){
    struct node *currentNode=registro->head;
    while (currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        free(temp->info);
        free(temp);
    }
    free(registro);
}