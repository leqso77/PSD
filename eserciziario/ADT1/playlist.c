#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "canzone.h"

struct playlist{
    Canzone canzoni[100];
    int size;
    Canzone current;
};

Playlist createPlaylist(){
    Playlist p=malloc(sizeof(struct playlist));
    p->size=0;
    p->current=NULL;
    return p;
}

void addCanzone(Playlist p, Canzone c){
    int i;
    for (i=0; i < p->size; i++);
        p->canzoni[i]=c;
        p->size++;
}


void removeCanzone(Playlist p, Canzone c){
    for(int i=0; i<p->size; i++){
        if(c==p->canzoni[i]){
            for (; i<p->size-1; i++){
                p->canzoni[i]=p->canzoni[i+1];
            }
            break;
        }
    }
    p->size--;
}

void printPlaylist(Playlist p){
    printf("%d canzoni nella playlist:\n", p->size);
    for (int i=0; i<p->size; i++){
        printCanzone(p->canzoni[i]);
    }
}

void riproduci(Playlist p, Canzone c){
    Canzone temp=p->current;
    int i;
    for (i=0; i<p->size; i++){
        if (c==p->canzoni[i]) break;
    }
i++;
p->current=c;
}

void skip(Playlist p){
    Canzone temp=p->current;
    int i;
    for (i=0; i<p->size; i++){
        if (temp==p->canzoni[i]) break;
}
i++;
p->current=temp;
}

