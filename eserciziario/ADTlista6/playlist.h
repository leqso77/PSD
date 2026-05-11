#include "canzone.h"

typedef struct playlist *Playlist;

Playlist createPlaylist();
void aggiungiInFondo(Playlist playlist, Canzone canzone);
void rimuoviCanzone(Playlist playlist, char *titolo);
void printPlaylist(Playlist playlist);
void freePlaylist(Playlist playlist);