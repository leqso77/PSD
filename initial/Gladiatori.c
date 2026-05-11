#include <stdio.h>
#include <string.h>

struct Personaggio{
    char nome[50];
    int hp;
    int danno;
};

void Status(struct Personaggio p){
    printf("%s ha vita: %d HP | Danno: %d\n", p.nome, p.hp, p.danno);
}

void Attack(struct Personaggio *attaccante, struct Personaggio *difensore){
    difensore->hp-=attaccante->danno;
    printf("%s ha subuto danno %d da %s", difensore->nome, attaccante->danno, attaccante->nome);
}


int main(){
    char rematch;
    do{
    struct Personaggio eroe;
    strcpy(eroe.nome, "Ettore");
    eroe.hp=100;
    eroe.danno=25;

    struct Personaggio mostro;
    strcpy(mostro.nome, "Drago di comodo");
    mostro.hp= 200;
    mostro.danno= 10;

    int turno=1;
    int scelta;

        while (eroe.hp > 0 && mostro.hp > 0){
            printf("\n---turno %d---\n", turno);
            Status(eroe);
            Status(mostro);
            
            printf("cosa vuoi fare?\n 1. attaccare\n 2. curarti(+20hp)\n segli: ");
            scanf("%d", &scelta);

            if (scelta==1){
                Attack(&eroe, &mostro);
            }
            else if (scelta==2){
                if (eroe.hp>=100){
                    printf("hp massimo, non puoi curarti!!");
                    continue;
                }
                eroe.hp+=20;
                if (eroe.hp> 100){
                    eroe.hp=100;
                }
                printf("l'eroe beve la pozione di vita e recupera 20hp\n");
                //continue;
            }
            else {
                printf("colpo schivato da %s", mostro.nome);
            }
            if (mostro.hp > 0){
                printf("\n contrattacco del mostro: \n");
                Attack(&mostro, &eroe);
            }
            turno++;
        }
        printf("\n fine battaglia \n");
        if (eroe.hp <= 0){
            printf("sei morto, %s! ha vinto %s", eroe.nome, mostro.nome);
        }
        else{
            printf("hai vinto, %s! hai sconfitto %s", eroe.nome, mostro.nome);
        }
        printf("\n---- REMATCH?-----\n");
        scanf(" %c", &rematch);
        }  
        while(rematch=='s' || rematch=='S');
        if (rematch=='n' || rematch=='N')
    return 0;
}