#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long X, Y, Xmod, XpowY;
    long long modulo = 1000000007;
    
    scanf("%lld%lld", &X, &Y); // X^Y

    Xmod = X % modulo;
    XpowY = 1;

    while (Y > 0) {

        if (Y % 2 == 1) { // If Y is odd
            XpowY = (XpowY * Xmod) % modulo;
        }

        Xmod = (Xmod * Xmod) % modulo;
        Y = Y / 2;

    }

    printf("%lld\n", XpowY);

    return 0;
}