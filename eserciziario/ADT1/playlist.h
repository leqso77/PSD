#include "canzone.h"

typedef struct playlist *Playlist;

Playlist createPlaylist();
void addCanzone(Playlist, Canzone);
void printPlaylist(Playlist);
void removeCanzone(Playlist, Canzone);
void riproduci(Playlist, Canzone);
void skip(Playlist);
