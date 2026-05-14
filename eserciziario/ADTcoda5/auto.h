typedef struct automobile *Auto;

Auto newAuto(char *targa, char *programmaLavaggio, float prezzo);
char *getTarga(Auto automobile);
char *getProgrammaLavaggio(Auto automobile);
float getPrezzo(Auto automobile);
void printAuto(Auto automobile);
void freeAuto(Auto automobile);