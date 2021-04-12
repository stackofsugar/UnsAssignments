#include <stdio.h>

int main() {
    unsigned long hasil;
    int i;

    for (i = 2; i < 100; i += 3){
        hasil += i;
    }

    printf("Hasil dari operasi adalah %lu\n", hasil);
}
