#include <stdio.h>
#include "kart.h"

int main(){
    struct Pilota piloti[5] = {
        {"Mario", 120.5},
        {"Luigi", 118.3},
        {"Peach", 122.1},
        {"Bowser", 119.8},
        {"Yoshi", 121.0}
    };

    ordinaClassifica(piloti, 3);
    printf("Classifica finale:\n");
    stampaClassifica(piloti, 3);

    return 0;
}