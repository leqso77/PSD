#include <stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


void bubbleSort(int a[], int n){
    int swapped=0; 

    for(int i=1; i<n && !swapped; i++){
        swapped=1;
        for (int j=0; j<n-1; j++){
            if (a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
                swapped=0;
                printf("Scambio: %d e %d\n", a[j], a[j+1]);
            }
        }
        printf("array dopo iterazione %d: ", i);
        for (int k=0; k<n; k++){
            printf("%d ", a[k]);   
        }
        printf("\n");
    }
}

int main(){
    int a[]={10,20,7,18,6, 4};
    int n=sizeof(a)/sizeof(a[0]);

    printf("Array prima dell'ordinamento: ");
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
}
    printf("\n");

    bubbleSort(a, n);

    printf("Array dopo l'ordinamento: ");
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
