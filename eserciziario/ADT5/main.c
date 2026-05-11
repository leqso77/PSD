#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "contatto.h"
#include "rubrica.h"


int main(){
    Rubrica rubrica= createRubrica();
    Contatto contatto1=createContatto("Leqso", "Chikviladze", "3285630871", "leqsochikviladze77@gmail.com");
    Contatto contatto2=createContatto("roberto", "cito", "3471304385", "robbencita@gmail.com");
    Contatto contatto3=createContatto("Madona", "sakuashvili", "3895010125", "madonasakuashvili@gmail.com");
    addContact(rubrica, contatto1);
    addContact(rubrica, contatto2);
    addContact(rubrica, contatto3);

    printf("\n\n");

    printContatto(contatto1);
    printContatto(contatto2);
    printContatto(contatto3);
    printRubrica(rubrica);

    printf("\n\n");


    cercaPerNome(rubrica, "Leqso");
    cercaPerNumero(rubrica, "3285630871");
    newDetails(rubrica, contatto1, "Aleksandre", NULL, NULL, NULL);

    printRubrica(rubrica);

    return 0;

}