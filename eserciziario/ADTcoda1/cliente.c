#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cliente.h"

struct cliente{
    int numeroTicket;
    char *richiesta;
};

Cliente newCliente(int numeroTicket, char *richiesta){
    Cliente cliente=malloc(sizeof(struct cliente));
    cliente->numeroTicket=numeroTicket;
    cliente->richiesta=strdup(richiesta);
    return cliente;
}

int getNumeroTicket(Cliente cliente){
    return cliente->numeroTicket;
}

char *getRichiesta(Cliente cliente){
    return cliente->richiesta;
}

void printCliente(Cliente cliente){
    printf("Cliente numero %d ha richiesto %s\n", cliente->numeroTicket, cliente->richiesta);
}

void freeCliente(Cliente cliente){
    free(cliente->richiesta);
    free(cliente);
}
