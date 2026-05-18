#include "song.h"

typedef struct playlist *Playlist;

Playlist createPlaylist(char* name);
void addSong(Playlist, Song);
void removeSong(Playlist, char*);
void printPlaylist(Playlist);
void sortByGradimento(Playlist);// ordina le canzoni della playlist mettendole in ordine decrescente di gradimento, complessita' O(n^2)
