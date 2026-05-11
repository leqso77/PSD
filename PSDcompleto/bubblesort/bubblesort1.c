#include <stdio.h>

void bubblesort(int a[], int n){
    int swapped;
    for (int i=0; i<n-1; i++){
        swapped=0;
        for (int j=0; j<n-i-1; j++){
            if (a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            swapped=1;
            }
        }
        if (swapped==0){
            if(i==0){
                printf("Array già ordinato, nessuno scambio necessario.\n");
            }
            break;
        }
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=sizeof(a)/sizeof(a[0]);

    bubblesort(a, n);

    printf("Array ordinato: ");
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}