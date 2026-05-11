#include <stdio.h>
#include <string.h>

void insertionsort(char a[], int n){
    for (int i=1; i<n; i++){
        int key=a[i];
        int j=i-1;

        while (j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

void printArray(char a[], int n){
    for (int i=0; i<n; i++){
        printf("%c", a[i]);
    }
}

int main(){
    char array[]="zorro";
    int n=strlen(array);

    insertionsort(array, n);
    printArray(array, n);
    printf("\n");
    return 0;
}