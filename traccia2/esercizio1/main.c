#define N 30
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"
#include "item.h"

int isBalanced(char *exp){
	Stack s=newStack();

	for(int i=0; exp[i] != '\0'; i++){
		if (exp[i] == '(' || exp[i] == '[' || exp[i]== '{'){
			char *parentesi=malloc(sizeof(char));
			*parentesi=exp[i];
			push(s, parentesi);
		}
		else if (exp[i]== ')' || exp[i]== ']' || exp[i]== '}'){
			if(isEmptyStack(s)){
				return 0;
			}
			char *topItem=top(s);
			char parentesiAperta=*topItem;
			pop(s);
			free(topItem);
			
			if ((exp[i] == ')' && parentesiAperta != '(') || (exp[i]==']' && parentesiAperta != '[') || (exp[i] == '}' && parentesiAperta != '{')){
				return 0;
			}
		}
	}
	int result=isEmptyStack(s);
	return result;
}


int main() {
	char exp1[N]="(1+[x+{5+4}-7])";
	char exp2[N]="(1+2";
	char exp3[N]="(2+[3*4+{5])";
	char exp4[N]="";
	char exp5[N]="[";

	printf("1) Valuto: %s\n", exp1);
	if (isBalanced(exp1))
		printf("L' espressione e' bilanciata\n\n");
	else
		printf("L'espressione non e' bilanciata\n\n");

	printf("2) Valuto: %s\n", exp2);
	if (isBalanced(exp2))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("3) Valuto: %s\n", exp3);
	if (isBalanced(exp3))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("4) Valuto: %s\n", exp4);
	if (isBalanced(exp4))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");

	printf("5) Valuto: %s\n", exp5);
	if (isBalanced(exp5))
			printf("L' espressione e' bilanciata\n\n");
	else
			printf("L'espressione non e' bilanciata\n\n");
}
