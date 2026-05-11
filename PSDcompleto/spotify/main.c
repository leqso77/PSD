#include <stdio.h>
#include "spotify.h"

int main() {
    struct Brano b[] = {
        {"Shape of You", "Ed Sheeran", 0},
        {"Blinding Lights", "The Weeknd", 0},
        {"Dance Monkey", "Tones and I", 0}
    };

    int n = sizeof(b) / sizeof(b[0]);


    ascoltaBrano(&b[0]);
    ascoltaBrano(&b[1]);
    ascoltaBrano(&b[1]);

    ordinaBrani(b, n);
    stampaBrani(b, n);

    return 0;
}