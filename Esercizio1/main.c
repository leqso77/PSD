#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "song.h"
#include "playlist.h"

// utilizzare questa funzione nel main per <stampare, ordinare, stampare> la playlist
// da completare riga ***
void stampaEordina(Playlist pl){
	printf("\n-- Stampa playlist originale --\n");
	printPlaylist(pl);
	printf("\n-- Stampa playlist dopo ordinamento per gradimento --\n");

	// *** inserire qui la chiamata all'operatore che ordina la playlist per gradimento
	sortByGradimento(pl);

	printPlaylist(pl);
	printf("\n\n");
}

// funzione che restituisce un numero intero tra 1 e 100
int randomInt() {
	return 1 + (rand() % 100);
}

int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga

	// completare
	Playlist pl1=createPlaylist("Playlist vuota");
	stampaEordina(pl1);

	Playlist pl2=createPlaylist("Playlist con una canzone");
	Song sA=initSong("titolo A", "artista A", 180);
	setGradimento(sA, 80);
	addSong(pl2, sA);
	stampaEordina(pl2);


	Playlist pl3= createPlaylist("Playist con due canzoni");
	Song sC=initSong("titolo C", "artista C", 180);
	setGradimento(sC, 80);
	Song sB=initSong("titolo G", "artista G", 180);
	setGradimento(sB, 70);
	addSong(pl3, sC);
	addSong(pl3, sB);
	stampaEordina(pl3);

	Playlist pl4= createPlaylist("Playlist con quattro canzoni");
	Song sH=initSong("titolo D", " artista D", 180);
	setGradimento(sH, 60);
	Song sG=initSong("titolo G", "artista G", 180);
	setGradimento(sG, 60);
	Song sF=initSong("titolo F", "artista F", 180);
	setGradimento(sF, 90);
	Song sE=initSong("titolo E", "artista E", 180);
	setGradimento(sE, 40);
	addSong(pl4, sH);
	addSong(pl4, sG);
	addSong(pl4, sF);
	addSong(pl4, sE);
	stampaEordina(pl4);

	Playlist pl5= createPlaylist("Playlist con cinque canzoni con gradimento casuale");
	Song sN=initSong("titolo N", "artista N", 180);
	setGradimento(sN, randomInt());
	Song sM=initSong("titolo M", "artista M", 180);
	setGradimento(sM, randomInt());
	Song sL=initSong("titolo L", "artista L", 180);
	setGradimento(sL, randomInt());
	Song sK=initSong("titolo K", "artista K", 180);
	setGradimento(sK, randomInt());
	Song sJ=initSong("titolo J", "artista J", 180);
	setGradimento(sJ, randomInt());
	addSong(pl5, sN);
	addSong(pl5, sM);
	addSong(pl5, sL);
	addSong(pl5, sK);
	addSong(pl5, sJ);
	stampaEordina(pl5);

	return 0;
}
