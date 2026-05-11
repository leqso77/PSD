#include <stdio.h>

int min(int a, int b){
    return (a<b)? a : b;
}

void merge(int a[], int b[], int c[], int n, int m){
    int i=0, j=0, k=0;
    int temp[n+m];
    while (i<n && j<m){
        if (a[i]<b[j]){
            temp[k++]=a[i++];
        } else {
            temp[k++]=b[j++];
        }
    }
    while (i<n){
        temp[k++]=a[i++];
    }
    while (j<m){
        temp[k++]=b[j++];
    }
    for (int i=0; i<k; i++){
        c[i]=temp[i];
    }
}


void mergesort(int a[], int n){
    int curr_size;
    int left_start;

    for (curr_size=1; curr_size<=n-1; curr_size*=2){
        for (left_start=0; left_start<n-1; left_start+= 2*curr_size){
            int left_end=left_start+curr_size-1;
            int right_end=min(left_start+2*curr_size-1, n-1);
            merge (a+left_start, a+left_end+1, a+left_start, left_end-left_start+1, right_end-left_end);
        }
    }
}

int main() { 
    
    int arr[] = {12, 6, 4, 5, 9, 2, 3, 1}; // Esempio esatto tratto dalle slide di teoria 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int i; 
    // 2. Stampa array originale 
    printf("Array originale: \n"); 
    for(i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
    // 3. Invocazione dell'algoritmo Merge Sort Iterativo 
    mergesort(arr, n); 
    // 4. Stampa risultato 
    printf("Array ordinato (Merge Sort): \n"); 
    for(i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n");
    return 0; 
} 