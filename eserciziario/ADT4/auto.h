#ifndef AUTO_H
#define AUTO_H

typedef struct car *Auto;

Auto createAuto(char *, char *, int, int);
int cercapermarca(Auto car, char *marca);
int cercapermodello(Auto car, char *modello);
void printAuto(Auto car);

#endif