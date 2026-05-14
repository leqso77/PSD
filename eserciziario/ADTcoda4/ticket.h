typedef struct ticket *Ticket;

Ticket newTicket(int idChiamata, char *nomeCliente, char *RepartoRichiesto);
int getIdChiamata(Ticket ticket);
char *getNomeCliente(Ticket ticket);
char *getRepartoRichiesto(Ticket ticket);
void printTicket(Ticket ticket);
void freeTicket(Ticket ticket);