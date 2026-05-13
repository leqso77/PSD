typedef struct documento *Documento;

Documento newDocumento(char *nomeFile, int numeroPagine);
char *getNomeFile(Documento documento);
int getNumeroPagine(Documento documento);
void printFile(Documento documento);
void freeDocumento(Documento documento);
