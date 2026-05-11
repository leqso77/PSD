#include <stdio.h>
#include "paziente.h"
#include "triage.h"

int main() {
    printf("=== PRONTO SOCCORSO: GESTIONE TRIAGE ===\n\n");

    SalaAttesa sala = createSalaAttesa();

    // 1. Arrivano i pazienti in ordine casuale di gravità
    printf("Accettazione pazienti in corso...\n");
    aggiungiPaziente(sala, createPaziente("Marco (Taglio al dito)", 4));
    aggiungiPaziente(sala, createPaziente("Anna (Infarto)", 1));
    aggiungiPaziente(sala, createPaziente("Luca (Febbre alta)", 3));
    
    // Giorgio ha lo stesso codice di Anna, ma è arrivato dopo. Deve andare DOPO di lei!
    aggiungiPaziente(sala, createPaziente("Giorgio (Incidente)", 1)); 
    
    aggiungiPaziente(sala, createPaziente("Sara (Sospetta frattura)", 2));

    // 2. Controllo la coda
    printf("\nSituazione in Sala d'Attesa (Dal più grave al meno grave):\n");
    printSalaAttesa(sala);

    // 3. Il medico chiama
    printf("\nIl medico si libera. Chiama il prossimo!\n");
    chiamaProssimo(sala); // Dovrebbe chiamare Anna e rimuoverla

    // 4. Coda aggiornata
    printf("\nSituazione in Sala d'Attesa aggiornata:\n");
    printSalaAttesa(sala);

    freeSalaAttesa(sala);
    return 0;
}