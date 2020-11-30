#include <stdio.h>

int main() {
    unsigned long hasil;
    int i = 2;

    while (i < 100){
        hasil += i;
        i = i + 3;
    }

    printf("Hasil dari operasi adalah %lu\n", hasil);
}
