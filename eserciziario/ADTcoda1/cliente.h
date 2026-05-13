typedef struct cliente *Cliente;

Cliente newCliente(int numeroTicket, char *richiesta);
int getNumeroTicket(Cliente Cliente);
char *getRichiesta(Cliente cliente);
void printCliente(Cliente cliente);
void freeCliente(Cliente cliente);