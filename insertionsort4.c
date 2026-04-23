#include <stdio.h>
#include <string.h>

struct Smartphone {
    char nome[50];
    char modello[50];
    float prezzo;
    int quantita;
};

int vendita(struct Smartphone *telefono, int quantitaDaAcquistare) {
    if (telefono->quantita <= 0) {
        return 0;
    }
    if (telefono->quantita < quantitaDaAcquistare) {
        return 0;
    }
    telefono->quantita -= quantitaDaAcquistare;
    return 1;
}

void printCatalogo(struct Smartphone t[], int n){
    for (int i=0; i<n; i++){
        printf("%s, %s, %.2f$, %d rimasti\n", t[i].nome, t[i].modello, t[i].prezzo, t[i].quantita);
    }
}

int main(){
    struct Smartphone magazzino[3] = {
        {"Apple", "iPhone 13", 799.99, 2},
        {"Samsung", "Galaxy S22", 650.00, 0}, // Ops, questo è esaurito!
        {"Google", "Pixel 7", 599.50, 5}
    };

    int n=3;
    char modelloScelto[50];
    int trovato=0;
    int quantitaDaAcquistare;

    printCatalogo(magazzino, n);

    printf("\nscegli il modello: ");
    scanf("%[^\n]", modelloScelto);
    printf("quanti ne vuoi acquistare?: ");
    scanf("%d", &quantitaDaAcquistare);

    for (int i=0; i<n; i++){
        if (strcmp(magazzino[i].modello, modelloScelto)==0){
            trovato=1;

            if (vendita(&magazzino[i], quantitaDaAcquistare) == 1){
                if (((magazzino->quantita)-quantitaDaAcquistare)<0){
                    printf("quantita non disponibile!!!\n");
                    break;
                }
                printf("\nvendita avvenuta con successo\n");
            }
            else{
                printf("\nmodello esaurito\n");
            }
            break;
        }
    }
    if(trovato==0){
        printf("\nmodello non trovato\n\n");
    }
    printCatalogo(magazzino, n);

    return 0;
}