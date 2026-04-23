#include <stdio.h>
#include <string.h>

void gridPlan(char grid[3][3]){
    for (int r=0; r<3; r++){
        for (int col=0; col<3; col++){
            printf(" %c ",grid[r][col]);
            if (col < 2) printf("|");
        }
        printf("\n");
    }
    printf("\n");
}

int mossa(char grid[3][3], int riga, int colonna, char player){
    if (grid[riga][colonna]== ' '){
        grid[riga][colonna] = player;
        return 1;
    }
    else {
        if(grid[riga][colonna]== 'X' || grid[riga][colonna]== 'O'){
            printf("Errore, posto occupato\n");
        }
    }
    return 0;
}

int winner(char grid[3][3]){
    for(int i = 0; i<3; i++){
        if (grid[i][0] != ' ' && grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2]){
            return 1;
        }
        if (grid[0][i] != ' ' && grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i]){
            return 1;
        }
    }

    if (grid[0][0] != ' ' && grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]){
        return 1;
    }
    if (grid[0][2] != ' ' && grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]){
        return 1;
    }
    return 0;
}

int main(){
    char grid[3][3]={
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
    };

    int turno=0;
    char player='X';
    int riga, colonna;
    int vincitore=0;

    while (turno<9){
        gridPlan(grid);
        printf("turno di %c, inserisci riga e colonna: ", player);
        scanf("%d %d", &riga, &colonna);

        if(riga<0 || riga>2 || colonna<0 || colonna>2){
            printf("sei uscito fuori\n");
            continue;
        }

        int mossaValida= mossa(grid, riga, colonna, player);

        if(mossaValida == 1){
            if(winner(grid)==1){
                vincitore=1;
                break;
            }

            if (player == 'X'){
                player = 'O';
            }
            else {
                player = 'X';
            }
            turno++;
        }
    }
    gridPlan(grid);
    if (vincitore==1){
        printf("hai vinto ghay\n");
    }
    else {
        printf("PAREGGIO!!! siete due ghey\n");
    }
    return 0;
}
