#include <stdio.h>
#ifndef PUNTO_H
#define PUNTO_H

typedef struct punto *Punto;

Punto creaPunto(float x, float y);
float ascissa(Punto p);
float ordinata(Punto p);
float distanza(Punto p1, Punto p2);

#endif