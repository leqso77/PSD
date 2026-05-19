typedef struct task *Task;

Task initTask(char* titolo, char* assegnatario, int ore_stimate);
char* getTitolo(Task);
char* getAssegnatario(Task);
int getOre(Task);
void setPriorita(Task, int priorita);
int getPriorita(Task);