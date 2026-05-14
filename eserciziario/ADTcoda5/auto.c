#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

struct automobile{
    char *targa;
    char *programmaLavaggio;
    float prezzo;
};

Auto newAuto(char *targa, char *programmaLavaggio, float prezzo){
    Auto automobile=malloc(sizeof(struct automobile));
    automobile->targa=strdup(targa);
    automobile->programmaLavaggio=strdup(programmaLavaggio);
    automobile->prezzo=prezzo;
    return automobile;
}

char *getTarga(Auto automobile){
    return automobile->targa;
}

char *getProgrammaLavaggio(Auto automobile){
    return automobile->programmaLavaggio;
}

float getPrezzo(Auto automobile){
    return automobile->prezzo;
}

void printAuto(Auto automobile){
    printf("auto %s ha scelto il prigramma %s, prezzo-> %.2f\n", automobile->targa, automobile->programmaLavaggio, automobile->prezzo);
}

void freeAuto(Auto automobile){
    free(automobile->targa);
    free(automobile->programmaLavaggio);
    free(automobile);
}



