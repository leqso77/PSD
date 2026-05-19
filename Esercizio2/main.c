#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#include "list.h"

// scrivere *in questo file*:
// - heightAndNumNodes
// - preorder

int *heightAndNumNodes(BTree btree){
	int *result= malloc(2 * sizeof(int));

	if (isEmptyTree(btree) == 1){
		result[0]=0;
		result[1]=0;
		return result;
	}

	int *sx=heightAndNumNodes(getLeft(btree));
	int *dx=heightAndNumNodes(getRight(btree));

	result[1]=1+sx[1]+dx[1];

	if (sx[1] == 0 && dx[1] == 0){
		result[0]=0;
	}
	else{
		if(sx[0] > dx[0]){
			result[0]=1+sx[0];
		}
		else{
			result[0]=1+dx[0];
		}
	}
	free(sx);
	free(dx);

	return result;

}

void preorder(BTree btree){
	if(isEmptyTree(btree)){
		return;
	}

	List daVisitare= newList();
	addHead(daVisitare, btree);

	while(!isEmpty(daVisitare)){
		BTree corrente= (BTree)removeHead(daVisitare);
		outputItem(getBTreeRoot(corrente));
		if(!isEmptyTree(getRight(corrente))){
			addHead(daVisitare, getRight(corrente));
		}
		if(!isEmptyTree(getLeft(corrente))){
			addHead(daVisitare, getLeft(corrente));
		}
	}
}

void printHeightNumNodesAndPreorder(BTree bt) {
	printf("Albero:\n");
	printTree(bt);
	int *hn = heightAndNumNodes(bt);
	if(hn) printf("Altezza albero: %d\nNumero nodi albero: %d\n", hn[0], hn[1]);
	printf("Visita preorder iterativa: ");
	preorder(bt);
	printf("\n\n");
}

int main(){
	// printHeightNumNodesAndPreorder(aTree);
	// da scrivere

	BTree t1= newTree();
	printHeightNumNodesAndPreorder(t1);

	int val2=2;
	BTree t2= buildTree(newTree(), newTree(), &val2);
	printHeightNumNodesAndPreorder(t2);
	
	int v1= 1, v3=3, v5=5, v7=7, v9=9;
	BTree n1= buildTree(newTree(), newTree(), &v1);
	BTree n5= buildTree(newTree(), newTree(), &v5);
	BTree n3= buildTree(newTree(), newTree(), &v3);
	BTree n9= buildTree(n1, n5, &v9);
	BTree t3= buildTree(n3, n9, &v7);

	printHeightNumNodesAndPreorder(t3);

	BTree t4=newRandomTree(8);
	printHeightNumNodesAndPreorder(t4);

}

