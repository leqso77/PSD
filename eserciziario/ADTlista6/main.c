#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canzone.h"
#include "playlist.h"

int main(){
    Playlist playlist=createPlaylist();
    aggiungiInFondo(playlist, createCanzone("canzone 1", "autore 1", 300));
    aggiungiInFondo(playlist, createCanzone("canzone 2", "autore 2", 280));
    aggiungiInFondo(playlist, createCanzone("canzone 3", "autore 3", 400));
    aggiungiInFondo(playlist, createCanzone("canzone 4", "autore 4", 405));

    printPlaylist(playlist);
    printf("\n");

    aggiungiInFondo(playlist, createCanzone("canzone 5", "autore 5", 290));

    printPlaylist(playlist);

    freePlaylist(playlist);

    return 0;
}