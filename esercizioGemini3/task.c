#include <stdlib.h>
#include <string.h>
#include "task.h"

struct task {
	char *titolo;
	char *assegnatario;
	int ore_stimate;
    int priorita;
};

Task initTask(char* titolo, char* assegnatario, int ore_stimate){
	Task t = malloc(sizeof(struct task));
	t->titolo = strdup(titolo);
	t->assegnatario = strdup(assegnatario);
	t->ore_stimate = ore_stimate;
	return t;
}

char* getTitolo(Task t){
	char *titolo = malloc(sizeof(char) * (1+strlen(t->titolo)));
	strcpy(titolo, t->titolo);
	return titolo;
}

char* getAssegnatario(Task t){
	char *assegnatario = malloc(sizeof(char) * (1+strlen(t->assegnatario)));
	strcpy(assegnatario, t->assegnatario);
	return assegnatario;
}

int getOre(Task t){
	return t->ore_stimate;
}

void setPriorita(Task t, int priorita){
    t->priorita=priorita;
}

int getPriorita(Task t){
    return t->priorita;
}
