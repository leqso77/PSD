#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "studente.h"
#include "registro.h"

int main(){
    Registro registro= newRegistro();
    aggiungiStudnete(registro, newStudente("12345", "leqso", 30));
    aggiungiStudnete(registro, newStudente("12346", "roberto", 30));
    aggiungiStudnete(registro, newStudente("12347", "arjel", 30));
    aggiungiStudnete(registro, newStudente("12349", "daniele", 18));

    stampaRegistro(registro);
    printf("\nCerco lo studente con matricola MAT002...\n");
    Studente trovato = cercaPerMatricola(registro, "12345");
    if (trovato != NULL) {
        printf("Trovato: ");
        printStudente(trovato);
    } else {
        printf("Studente non trovato.\n");
    }

    // 4. La grande prova: Rimozione dal mezzo
    printf("\ndaniele si e' ritirato. Rimuovo 12349...\n");
    rimuoviStudente(registro, "12349");

    // 5. Stampa finale
    printf("\nRegistro aggiornato:\n");
    stampaRegistro(registro);

    // 6. Pulizia
    freeRegistro(registro);

    return 0;
}