#include <stdio.h>
#include <string.h>
#include "spotify.h"

void ascoltaBrano(struct Brano *b) {
    b->ascolti++;
}

void ordinaBrani(struct Brano b[], int n){
    for (int i=1; i<n; i++){
        struct Brano key=b[i];
        int j=i-1;

        while (j>=0 && b[j].ascolti>key.ascolti){
            b[j+1]=b[j];
            j--;
        }
        b[j+1]=key;

    }
}

void stampaBrani(struct Brano b[], int n){
    for (int i=0; i<n; i++){
        printf("%s - %s: %d ascolti\n", b[i].titolo, b[i].artista, b[i].ascolti);
    }
}
