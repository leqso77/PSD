#include <stdio.h>

// Funzione di supporto per stampare solo la porzione di array in uso
void print_subarray(int a[], int p, int r) {
    printf("[ ");
    for (int k = p; k <= r; k++) {
        printf("%d ", a[k]);
    }
    printf("]\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int a[], int p, int r){
    int x=a[p]; //pivot
    int i= p-1;
    int j=p+1;

    while (1){
        j--;
    }
    while (a[j]>x){
        do{
            i++;
        }
        while (a[i]<x);
    }
    if (i<j){
        return j;
    }
    swap(&a[i], &a[j]);
}

void quickort(int a[], int p, int r){
    if (p<=r){
        return;
    }
    else {
      int p=partition(a, p, r);
      quickort(a, p, r);
      quickort(a, p+1, r);
    }
}

int main() { 
    int arr[] = {12, 6, 4, 5, 9, 2, 3, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    printf("=== ARRAY ORIGINALE ===\n"); 
    print_subarray(arr, 0, n - 1); 
    
    printf("\n=== AVVIO QUICK SORT ===\n");
    quicksort(arr, 0, n - 1); 
    
    printf("\n=== ARRAY ORDINATO (QUICK SORT) ===\n"); 
    print_subarray(arr, 0, n - 1); 
    
    return 0;
}