#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "list.h"

int height(BTree bt) {
    if (isEmptyTree(bt) || (isEmptyTree(getLeft(bt)) && isEmptyTree(getRight(bt)))) {
        return 0;
    }

    int hLeft = 0;
    int hRight = 0;

    if (!isEmptyTree(getLeft(bt))) {
        hLeft = height(getLeft(bt));
    }
    if (!isEmptyTree(getRight(bt))) {
        hRight = height(getRight(bt));
    }

    if (hLeft > hRight) {
        return hLeft + 1;
    } else {
        return hRight + 1;
    }
}

int* sumByLevel(BTree bt){
	int h=height(bt);

    int *sums=calloc(h+1, sizeof(int));

    if (isEmptyTree(bt)){
        return sums;
    }

    List q=newList();
    addListTail(q, bt);

    int curLvl=0;

    while (!isEmpty(q)){
        int levelSize=sizeList(q);
        int currentSum=0;
        for(int i=0; i<levelSize; i++){
            BTree currentNode=removeHead(q);
            int *val=(int *) getBTreeRoot(currentNode);
            if (val != NULL){
                currentSum+=*val;
            }

            if (!isEmptyTree(getLeft(currentNode))){
                addListTail(q, getLeft(currentNode));
            }
            if (!isEmptyTree(getRight(currentNode))){
                addListTail(q, getRight(currentNode));
            }
            
        }
        if (curLvl <= h){
                sums[curLvl] = currentSum;
        }
        curLvl++;
    }
 return sums;
}

void printHeightAndSumByLevel(BTree bt) {
	printf("Albero:\n");
	printTree(bt);
	int h = height(bt);
	printf("Altezza albero: %d\n", h);
	printf("Somma nodi per ogni livello: ");
	int* sums = sumByLevel(bt);

	for(int i = 0; i <= h; i++) {
		printf("%d ", sums[i]);
	}
	printf("\n\n");
}

int main(){
	BTree t1= newTree();
    printHeightAndSumByLevel(t1);

    int *v2=malloc(sizeof(int));
    *v2=2;
    BTree t2= buildTree(newTree(), newTree(), v2);
    printHeightAndSumByLevel(t2);

    int *v1 = malloc(sizeof(int)); *v1 = 1;
    int *v5 = malloc(sizeof(int)); *v5 = 5;
    int *v3 = malloc(sizeof(int)); *v3 = 3;
    int *v9 = malloc(sizeof(int)); *v9 = 9;
    int *v7 = malloc(sizeof(int)); *v7 = 7;

    BTree f1=buildTree(newTree(), newTree(), v1);
    BTree f5=buildTree(newTree(), newTree(), v5);
    BTree n3=buildTree(f1, f5, v3);
    BTree n9=buildTree(newTree(), newTree(), v9);
    BTree t3=buildTree(n3, n9, v7);
    printHeightAndSumByLevel(t3);

    BTree t4=newRandomTree(7);
    printHeightAndSumByLevel(t4);


}

