#include <stdio.h>

int main(){

    int n=89009;

    int *p=&n;

    printf("valore attuale del numero: %d\n", n);

    *p=23423;

    printf("valore nuovo: %d\n", n);
    return 0;
}