#include <stdio.h>
#include "kart.h"


void ordinaClassifica(struct Pilota a[], int n){
    for (int i=1; i<n; i++){
        struct Pilota key=a[i];
        int j=i-1;
        while (j>=0 && a[j].tempo>key.tempo){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void stampaClassifica(struct Pilota a[], int n){
    for (int i=0; i<n; i++){
        printf("%s: %.2f\n", a[i].nome, a[i].tempo);
    }
}

