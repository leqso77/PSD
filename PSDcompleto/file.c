#include <stdio.h>

struct Giocatore {
    char nome[50];
    int punteggio;
};

int main(){
    struct Giocatore giocatori[3] = {
        {"Alice", 100},
        {"Bob", 150},
        {"Charlie", 120}
    };
    int n=3;

    FILE *file = fopen("giocatori.txt", "w");

    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    for (int i=0; i<n; i++){
        fprintf(file, "%s: %d\n", giocatori[i].nome, giocatori[i].punteggio);
    }

    fclose(file);
    
}