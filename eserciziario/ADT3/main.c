#include <stdio.h>
#include "spesa.h"
#include "elemento.h"

int main(){
    Spesa spesa=createSpesa();
    addElemento(spesa, "Mela", 5, 1.5);
    addElemento(spesa, "Banana", 3, 2.0);
    printSpesa(spesa);
    totaleSpesa(spesa);
    return 0;
}