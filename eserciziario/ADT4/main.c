#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "concessionaria.h"

int main(){

    Concessionaria concessionaria= createConcessionaria();
    Auto car1= createAuto("Fiat", "Panda", 2010, 5000);
    Auto car2= createAuto("Ford", "Focus", 2015, 10000);
    Auto car3= createAuto("Volkswagen", "Golf", 2018, 15000);
    addAuto(concessionaria, car1);
    addAuto(concessionaria, car2);
    addAuto(concessionaria, car3);

    printConcessionaria(concessionaria);
    cercaPerMarca(concessionaria, "Ford");
    cercaPerModello(concessionaria, "Golf");
    printf("concesisonaria dopo la vendita di car1:\n");
    vendiAuto(concessionaria, car1);
    printConcessionaria(concessionaria);

    return 0;

}

