#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#include "canzone.h"

int main(){
    Playlist p=createPlaylist();
    Canzone c1=createCanzone("Bohemian Rhapsody", "Queen", "A Night at the Opera", 354);
    Canzone c2=createCanzone("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 482);
    Canzone c3=createCanzone("Imagine", "John Lennon", "Imagine", 183);
    addCanzone(p, c1);
    addCanzone(p, c2);
    addCanzone(p, c3);
    printPlaylist(p);
    removeCanzone(p, c2);
    printPlaylist(p);
    riproduci(p, c1);
    printf("\nSkippo la canzone corrente\n");
    skip(p);
    return 0;
}