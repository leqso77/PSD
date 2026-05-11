#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contatto.h"

struct contatto{
    char *nome;
    char *cognome;
    char *numero;
    char *email;
};

Contatto createContatto(char *nome, char *cognome, char *numero, char *email){
    Contatto contatto=malloc(sizeof(struct contatto));
    contatto->nome=strdup(nome);
    contatto->cognome=strdup(cognome);
    contatto->numero=strdup(numero);
    contatto->email=strdup(email);
    return contatto;
}

int cercapernome(Contatto contatto, char *nome){
    return strcmp(contatto->nome, nome)==0;
}

int cercapernumero(Contatto contatto, char *numero){
    return strcmp(contatto->numero, numero)==0;
}


Contatto changeDetails(Contatto contatto, char *nome, char *cognome, char *numero, char *email){
    if(nome!=NULL){
        free(contatto->nome);
        contatto->nome=strdup(nome);
    }

    if(cognome!=NULL){
        free(contatto->cognome);
        contatto->cognome=strdup(cognome);
    }
    if(numero!=NULL){
        free(contatto->numero);
        contatto->numero=strdup(numero);
    }
    if(email!=NULL){
        free(contatto->email);
        contatto->email=strdup(email);
    }
    return contatto;
}

void printContatto(Contatto contatto){
    printf("%s %s, numero %s, email %s\n", contatto->nome, contatto->cognome, contatto->numero, contatto->email);
}

