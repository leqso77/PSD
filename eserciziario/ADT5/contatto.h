#ifndef CONTATTO_H
#define CONTATTO_H

typedef struct contatto *Contatto;

Contatto createContatto(char *nome, char *cognome, char *numero, char *email);
int cercapernome(Contatto contatto, char *nome);
int cercapernumero(Contatto contatto, char *numero);
Contatto changeDetails(Contatto contatto, char *nome, char *cognome, char *numero, char *email);
void printContatto(Contatto contatto);

#endif