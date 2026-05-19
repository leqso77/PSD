#define FILM_H

typedef struct film *Film;

Film initFilm(char* titolo, char* regista, int anno);
char* getTitolo(Film);
char* getRegista(Film);
int getAnno(Film);
void setValutazione(Film, int valutazione);
int getValutazione(Film);