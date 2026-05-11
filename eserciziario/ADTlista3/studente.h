typedef struct studente *Studente;

Studente newStudente(char *matricola, char *nome, int voto);
char* getMatricola(Studente studente);
void printStudente(Studente studente);
void freeStudente(Studente studente);