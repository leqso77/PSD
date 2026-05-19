#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "progetto.h"
#include "list.h"
#include "task.h"

struct progetto {
	char *nome_progetto;
	List tasks;
};

Progetto createProgetto(char* nome_progetto){
	Progetto p = malloc(sizeof(struct progetto));
	p->nome_progetto = strdup(nome_progetto);
	p->tasks = newList();
	return p;
}

void addTask(Progetto p, Task t){
	addHead(p->tasks, t);
}

void removeTask(Progetto p, char *titolo){
	Task t = initTask(titolo, "", 0);
	removeListItem(p->tasks, t);
}

void printProgetto(Progetto p){
	printf("Progetto: %s", p->nome_progetto);
	printList(p->tasks);
	printf("\n");
}

void sort(Progetto p){
    int n=sizeList(p->tasks);
    for (int i=0; i< n-1; i++){
        for(int j=0; j<n-i-1; j++){
            Task t1= (Task)getListItemPos(p->tasks, j);
            Task t2 = (Task)getListItemPos(p->tasks, j+1);
            if (getPriorita(t1) < getPriorita(t2)){
                setListItemPos(p->tasks, j, t2);
                setListItemPos(p->tasks, j+1, t1);
            }
            else if(getPriorita(t1) == getPriorita(t2)){
                if(strcmp(getTitolo(t1), getTitolo(t2)) > 0){
                    setListItemPos(p->tasks, j, t2);
                    setListItemPos(p->tasks, j+1, t1);
                }
            } 
        }
    }
}