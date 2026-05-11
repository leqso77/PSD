#ifndef LIBRO_H
#define LIBRO_H

typedef struct libro *Libro;

Libro createLibro(char *, char *, char*, int);
int cercaPerAutore(Libro libro, char *autore);
int cercaPerTitolo(Libro libro, char *titolo);
void printLibro(Libro libro);
#endif