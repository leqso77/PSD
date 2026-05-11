#include <stdio.h>

void insertionsort(int a[], int n){
    for (int i=1; i<n; i++){
        int key=a[i];
        int j=i-1;
        while (j>=0 && a[j]<key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

void printArray(int a[], int n){
    for (int i=0; i<n; i++){
        printf("[%d] ", a[i]);
    }
}

int main(){
    int array[]={12, 13, 11, 5, 6};
    int n=5;
    insertionsort(array, n);
    printArray(array, n);
    printf("\n");
    return 0;
}