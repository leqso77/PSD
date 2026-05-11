#include <stdio.h>
#include "punto.h"

int main (){
    Punto p1, p2;
    float dist;

    p1=creaPunto(1.0, 2.0);
    p2=creaPunto(4.0, 6.0);

    printf("Punto 1: (%.2f, %.2f)\n", ascissa(p1), ordinata(p1));
    printf("Punto 2: (%.2f, %.2f)\n", ascissa(p2), ordinata(p2));

    dist=distanza(p1, p2);
    printf("Distanza tra i due punti: %.2f\n", dist);
    return 0;
}