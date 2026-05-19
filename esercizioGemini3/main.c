#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "progetto.h"
#include "task.h"

// da completare riga ***
void stampaEordina(Progetto p){
	printf("\n-- Stampa progetto originale --\n");
	printProgetto(p);
	printf("\n-- Stampa progetto dopo ordinamento --\n");

	// *** inserire qui la chiamata all'operatore che ordina il progetto
    sort(p);
	
	printProgetto(p);
	printf("\n\n");
}

// funzione che restituisce un numero intero tra 1 e 3 (1=Bassa, 2=Media, 3=Alta)
int randomPriorita() {
	return 1 + (rand() % 3);
}

int main() { 
	srand(time(NULL)); 

	Progetto p1= createProgetto("Progetto Vuoto");
    stampaEordina(p1);

    Progetto p2=createProgetto("Progetto Singolo");
    Task t1= initTask("Bob", "Setuo Server", 4); setPriorita(t1, 2);
    addTask(p2, t1);
    stampaEordina(p2);

    Progetto p3=createProgetto("Progetto Semplice");
    Task t2= initTask("Scrittura Documentazione", "Alice",  2); setPriorita(t2, 1);
    Task t3= initTask("Fix Bug Critico", "Charlie",  3); setPriorita(t3, 3);
    addTask(p3, t2);
    addTask(p3, t3);
    stampaEordina(p3);


    Progetto p4=createProgetto("Progetto Conflitti");
    Task t4= initTask("Database","Mario",  10); setPriorita(t4, 3);
    Task t5= initTask("Frontend","Luigi",  5); setPriorita(t5, 1);
    Task t6= initTask("API", "Anna", 8); setPriorita(t6, 3);
    Task t7= initTask("Z-Index fix", "Luca", 2); setPriorita(t7, 1);
    addTask(p4, t4);
    addTask(p4, t5);
    addTask(p4, t6);
    addTask(p4, t7);
    stampaEordina(p4);



    Progetto p5=createProgetto("Progetto Casuale");
    Task t8= initTask("Task E", "Elena", 4); setPriorita(t8, randomPriorita());
    Task t9= initTask("Task D", "Sara", 1); setPriorita(t9, randomPriorita());
    Task t10= initTask("Task C", "Marco", 6); setPriorita(t10, randomPriorita());
    Task t11= initTask("Task B", "Gino", 2); setPriorita(t11, randomPriorita());
    Task t12= initTask("Tastk A", "Pino", 3); setPriorita(t12, randomPriorita());
    addTask(p5, t8);
    addTask(p5, t9);
    addTask(p5, t10);
    addTask(p5, t11);
    addTask(p5, t12);
    stampaEordina(p5);


    return 0;
}