#include <stdio.h>
#include <string.h>

int scopriLettera(char *segreta, char *nascosta, char tentativo){
int trovata=0;

for (int i=0; i<=strlen(segreta); i++){
    if(segreta[i]==tentativo){
        nascosta[i]=tentativo;
        trovata=1;
    }
}
return trovata;
}

int main(){
    char segreta[]="hacker";
    char nascosta[]="______";
    int vite=5;
    char tentativo;

    while(vite>0 && strcmp(segreta, nascosta)!=0){
        printf("\npassword: %s\n", nascosta);
        printf("tentaviti rimasti: %d\n", vite);
        printf("inserisci una lettera: ");
        scanf(" %c", &tentativo);

        int successo= scopriLettera(segreta, nascosta, tentativo);
        if (successo ==0){
            printf("Errore! tentativo invano\n");
            vite--;
        }
        else {
            printf("giusto! lettera trovata");
        }
    }
    if (vite==0){
        printf("\naccesso negato, password errata!\n");
    }
    else {
        printf("\naccesso consentito, password corretta\n");
    }

    return 0;
}