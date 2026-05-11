#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prenotazione.h"
#include "registro.h"

int main(){
    Registro registro= newRegistro();

    addPrenotazione(registro, newPrenotazione("Leqso", 2, "20:30"));
    addPrenotazione(registro, newPrenotazione("Roberto", 4, "21:30"));
    addPrenotazione(registro, newPrenotazione("Arjel", 3, "22:30"));
    addPrenotazione(registro, newPrenotazione("Daniele", 9, "23:30"));

    printRegistro(registro);
    printf("\n numero totale di coperti: %d\n", calcolaCoperti(registro));

    removePrenotazione(registro, "Arjel");

    printRegistro(registro);
    printf("\n numero totale di coperti: %d\n", calcolaCoperti(registro));


    freeRegistro(registro);

    return 0;

}