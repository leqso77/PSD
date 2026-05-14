#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket.h"
#include "centralino.h"

int main() {
    Centralino centralino=newCentralino();

    enqueue(centralino, newTicket(1, "Leqso", "informatica"));
    enqueue(centralino, newTicket(2, "Roberto", "informatica"));
    enqueue(centralino, newTicket(3, "Arjel", "informatica"));
    enqueue(centralino, newTicket(4, "Simone", "informatica"));
    enqueue(centralino, newTicket(5, "Daniele", "informatica"));
    enqueue(centralino, newTicket(6, "Michele", "economia"));

    printCentralino(centralino);

    contaChiamatePerReparto(centralino, "informatica");

    Ticket ticketrimosso=dequeue(centralino);
    if (ticketrimosso != NULL){
        printf("risponde: ");
        printTicket(ticketrimosso);
        freeTicket(ticketrimosso);
    }

    Ticket ticketrimosso1=dequeue(centralino);
    if (ticketrimosso1 != NULL){
        printf("rismonde: ");
        printTicket(ticketrimosso1);
        freeTicket(ticketrimosso1);
    }
    printf("\n");

    printCentralino(centralino);
    contaChiamatePerReparto(centralino, "informatica");

    freeCentralino(centralino);

    return 0;
}
