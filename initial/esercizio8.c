#include <stdio.h>

int main(){

    int array[3]={10, 20, 30};

    int *p=array; // qui non i va la & datpo che sia punatori che gli array contengono l'indirizzo di memoria 

    for (int i=0; i<3; i++){
        printf("il valore numero %d e': %d\n", i, *(p+i));
    }

    return 0;

}