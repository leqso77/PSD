#include <stdio.h>
#include "transazione.h"
#include "conto.h"

int main() {
    printf("=== BANCA IN C ===\n\n");

    Conto mioConto = createConto();

    // 1. Aggiungo alcune operazioni (essendo inserite in testa, l'ultima sarà la prima stampata)
    printf("Registro le transazioni del mese...\n");
    aggiungiTransazione(mioConto, createTransazione(101, "Stipendio", 1500.00));
    aggiungiTransazione(mioConto, createTransazione(102, "Spesa Supermercato", -85.50));
    aggiungiTransazione(mioConto, createTransazione(103, "Ricarica Telefonica", -15.00));
    aggiungiTransazione(mioConto, createTransazione(104, "Bonifico da nonna", 50.00));

    // 2. Controllo l'estratto conto e il saldo
    printf("\n--- ESTRATTO CONTO ---\n");
    stampaEstrattoConto(mioConto);
    printf("SALDO ATTUALE: %.2f euro\n", calcolaSaldo(mioConto));

    // 3. Ops! La ricarica era un errore, la annullo (Rimozione nel mezzo)
    printf("\n>>> Errore di sistema: Annullamento transazione ID 103...\n");
    annullaTransazione(mioConto, 103);

    // 4. Ricontrollo il conto aggiornato
    printf("\n--- ESTRATTO CONTO AGGIORNATO ---\n");
    stampaEstrattoConto(mioConto);
    printf("SALDO ATTUALE: %.2f euro\n", calcolaSaldo(mioConto));

    // 5. Pulizia
    freeConto(mioConto);

    return 0;
}