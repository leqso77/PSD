#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prodotto.h"
#include "carrello.h"

int main(){
    Carrello carrello= createCarrello();

    printf("aggiungi prodotti: \n");
    aggiungiAlCarrello(carrello, creaProdotto("MAcbook air m4", 999.99));
    aggiungiAlCarrello(carrello, creaProdotto("MSI steatlth 15 m", 1900.00));
    aggiungiAlCarrello(carrello, creaProdotto("Macbook pro m5", 1700.00));

    printf("\n CARRELLO \n");
    stampaCarrello(carrello);
    printf("\n");

    float totale=calcolaTotale(carrello);
    printf("Prezzo totale: %.2f\n", totale);

    svuotaCarrello(carrello);
}