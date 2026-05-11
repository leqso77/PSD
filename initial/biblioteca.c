#include <stdio.h>
#include <string.h>

struct Libro{
    char titolo[50];
    char autore[50];
    int anno;
};

int main(){

    struct Libro libreria[3];

    for (int i=0; i<3; i++){
        printf("inseisci il titolo: ");
        scanf(" %[^\n]", libreria[i].titolo);
        printf("inserici l'autore: ");
        scanf(" %[^\n]", libreria[i].autore);
        printf("inerisci l-anno di pubblicazione: ");
        scanf("%d", &libreria[i].anno);
    }

    for (int i=0; i<3; i++){
        printf("\n\nlibro: %s\n", libreria[i].titolo);
        printf("autore: %s\n",libreria[i].autore);
        printf("pubblicato nel: %d\n", libreria[i].anno);
    }

    return 0;
}