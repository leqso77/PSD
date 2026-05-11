#ifndef SPOTIFY_H
#define SPOTIFY_H

struct Brano {
    char titolo[50];
    char artista[50];
    int ascolti;
};

void ascoltaBrano(struct Brano *b);
void ordinaBrani(struct Brano b[], int n);
void stampaBrani(struct Brano b[], int n);

#endif // SPOTIFY_H