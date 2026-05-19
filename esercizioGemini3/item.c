#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "task.h"

Item inputItem(){
	printf("Non usare inputItem(). Non richiedere input da tastiera.\n");
	return initTask("Task Test", "Assegnatario Test", 5);
}

void outputItem(Item item){
	Task t = item;
	printf("\n[%s] %s (%d ore stimate) - Priorita: %d", getAssegnatario(t), getTitolo(t), getOre(t), getPriorita(t));
}

int cmpItem(Item item1, Item item2){
	Task t1 = item1;
	Task t2 = item2;
	return strcmp(getTitolo(t1), getTitolo(t2));
}