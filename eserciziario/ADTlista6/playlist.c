#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canzone.h"
#include "playlist.h"

struct node{
    Canzone info;
    struct node *next;
};

struct playlist{
    struct node *head;
};

Playlist createPlaylist(){
    Playlist playlist=malloc(sizeof(struct playlist));
    playlist->head=NULL;
    return playlist;
}

void aggiungiInFondo(Playlist playlist, Canzone canzone){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->info=canzone;
    newNode->next=NULL;
    if (playlist->head == NULL){
        playlist->head=newNode;
        return;
    }
    struct node *currentNode=playlist->head;
    while(currentNode->next != NULL){
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
}

void rimuoviCanzone(Playlist playlist, char *titolo){
    if (playlist->head == NULL){
        return;
    }
    if (strcmp(getTitolo(playlist->head->info), titolo)==0){
        struct node *temp=playlist->head;
        playlist->head=playlist->head->next;
        free(temp);
        return; 
    }

    struct node *currentNode=playlist->head;
    while (currentNode->next != NULL && strcmp(getTitolo(currentNode->next->info), titolo)!=0){
        currentNode=currentNode->next;
    }
    if (currentNode->next != NULL){
        struct node *temp=currentNode->next;
        currentNode->next=temp->next;
        free(temp);
    }
}

void printPlaylist(Playlist playlist){
    struct node *currentNode= playlist->head;
    while(currentNode != NULL){
        stampaCanzone(currentNode->info);
        currentNode=currentNode->next;
    }
}

void freePlaylist(Playlist playlist){
    struct node *currentNode=playlist->head;
    while(currentNode != NULL){
        struct node *temp=currentNode;
        currentNode=currentNode->next;
        free(temp->info);
        free(temp);
    }
    free(playlist);
}


