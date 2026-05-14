#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket.h"

struct ticket{
    int idChiamata;
    char *nomeCliente;
    char *repartoRichiesto; 
};

Ticket newTicket(int idChiamata, char *nomeCliente, char *repartoRichiesto){
    Ticket ticket=malloc(sizeof(struct ticket));
    ticket->idChiamata=idChiamata;
    ticket->nomeCliente=strdup(nomeCliente);
    ticket->repartoRichiesto=strdup(repartoRichiesto);
    return ticket;
}

int getIdChiamata(Ticket ticket){
    return ticket->idChiamata;
}

char *getNomeCliente(Ticket ticket){
    return ticket->nomeCliente;
}

char *getRepartoRichiesto(Ticket ticket){
    return ticket->repartoRichiesto;
}

void printTicket(Ticket ticket){
    printf("ticket: %d, nome: %s, reparto: %s\n", ticket->idChiamata, ticket->nomeCliente, ticket->repartoRichiesto);
}

void freeTicket(Ticket ticket){
    free(ticket->nomeCliente);
    free(ticket->repartoRichiesto);
    free(ticket);
}