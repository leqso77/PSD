#include <stdio.h>
#include <string.h>

struct Automobile{
    char marca[50];
    int anno;
    float prezzo;
};


int main(){

    struct Automobile miaAuto;

    printf("inserisci la marca dell'auto: ");
    scanf("%[^\n]", miaAuto.marca);
    printf("inserisci l'anno dell'auto: ");
    scanf("%d", &miaAuto.anno);
    printf("inserisci il prezzo dell'auto: ");
    scanf("%f.2", &miaAuto.prezzo);


    printf("\n\nauto: %s\n", miaAuto.marca);
    printf("anno: %d\n", miaAuto.anno);
    printf("prezzo: %.2f\n", miaAuto.prezzo);

    
}