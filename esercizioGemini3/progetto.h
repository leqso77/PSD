#include "task.h"

typedef struct progetto *Progetto;

Progetto createProgetto(char* nome_progetto);
void addTask(Progetto, Task);
void removeTask(Progetto, char*);
void printProgetto(Progetto);
void sort(Progetto);