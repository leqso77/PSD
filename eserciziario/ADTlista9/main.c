#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "veicolo.h"
#include "officina.h"

int main(){
    Officina officina=createOfficina();
    addVeicolo(officina, newVeicolo("DE103CV", "perugeot 207", 1000.00));
    addVeicolo(officina, newVeicolo("DG115DY", "kia picanto", 2.00));
    addVeicolo(officina, newVeicolo("FA638MJ", "perugeot 2008", 1500.00));
    addVeicolo(officina, newVeicolo("EP63307", "Honda CBR 500R", 250.00));
    addVeicolo(officina, newVeicolo("DE100TE", "perugeot 208", 1900.00));

    printf("OFFICINA ATTUALMENTE\n");
    printOfficina(officina);
    dannoMaggiore(officina);

    removeVeicolo(officina, "DE100TE");

    printf("\nOFFICINA DOPO LA RIMOZIONE\n");
    printOfficina(officina);

    freeOfficina(officina);

    return 0;
}