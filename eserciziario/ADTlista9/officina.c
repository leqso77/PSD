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
        return;
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
        totale+=getPrezzoRip(currentNode->info);
        currentNode=currentNode->next;
    }
    return totale;
}

void dannoMaggiore(Officina officina){
    struct node *temp=officina->head;
    Veicolo maxVeicolo=temp->info;
    float maggiore=getPrezzoRip(temp->info);

    while (temp != NULL){
        if (getPrezzoRip(temp->info) > maggiore){
            maggiore=getPrezzoRip(temp->info);
            maxVeicolo=temp->info;

        }
        temp=temp->next;
    }
    printf("\n--- VEICOLO CON DANNO MAGGIORE ---\n");
    printf("Targa: %s\n", getTarga(maxVeicolo));
    printf("Costo stimato: %.2f euro\n", maggiore); 
}

void printOfficina(Officina officina){
    struct node *currentNode=officina->head;
    while (currentNode != NULL){
        printVeicolo(currentNode->info);
        currentNode=currentNode->next;
    }
}

void freeOfficina(Officina officina){
    struct node *currentNode=officina->head;
    while(currentNode != NULL){
        struct node *temp = currentNode;   // 1. Salvo il nodo in temp
        currentNode = currentNode->next;   // 2. Mi metto in salvo andando avanti
        
        freeVeicolo(temp->info);           // 3. Distruggo l'info di temp
        free(temp);                        // 4. Distruggo il nodo temp
    }
    free(officina);
}



