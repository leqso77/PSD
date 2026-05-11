#include <stdio.h>


void swap(int *a, int *b){
int temp;
temp=*a;
*a=*b;
*b=temp;
}


int main(){
    int a=10;
    int b=99;

    printf("valori prima dello swap: %d %d\n", a, b);

    swap(&a, &b);

    printf("valori dopo lo swap: %d %d\n", a, b);
    return 0;


}