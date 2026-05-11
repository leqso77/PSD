#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "stack.h"


int coppie(char open, char closed){
    if (open == '(' && closed == ')') return 1;
    if (open == '{' && closed == '}') return 1;
    if (open == '[' && closed == ']') return 1;
    return 0;
}

int main (){
    Stack s = createStack(); // Assicurati che nel tuo .h si chiami createStack e non initStack come prima!
    
    char espressione[] = "( [ { } ] )";
    int lenght = strlen(espressione);
    int valida = 1;

    for (int i = 0; i < lenght; i++){
        char c = espressione[i];
        
        // Ignoriamo gli spazi vuoti
        if (c == ' ') continue;

        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            
            // ERRORE 1: Troppe chiusure (es. "())" )
            if (isempty(s)) {
                printf("Errore: trovata una parentesi chiusa '%c' senza nessuna apertura.\n", c);
                valida = 0;
                break;
            }
            
            char open = pop(&s);
            
            // ERRORE 2: Coppia sbagliata (es. "(]" )
            if (!coppie(open, c)) {
                printf("Errore: coppia errata. Ho aperto '%c' ma ho provato a chiudere con '%c'.\n", open, c);
                valida = 0;
                break;
            }
        }
    }
    
    // Controllo Finale
    if (valida == 1) {
        // ERRORE 3: Se alla fine del ciclo lo stack ha ancora qualcosa dentro (es. "(()" )
        if (!isempty(s)) {
            printf("Errore: apertura senza chiusura. Sono rimaste parentesi aperte non chiuse.\n");
        } else {
            // Se è valida E lo stack è vuoto, allora è perfetta!
            printf("Espressione valida e bilanciata!\n");
        }
    }

    // Ricordati sempre di liberare la memoria alla fine!
    // freeStack(&s); 
    
    return 0;
}
