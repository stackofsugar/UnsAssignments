// main.c
#include <stdio.h>
#include "calculator.h"
#define ANGKA1 21
#define ANGKA2 7

int main(){
    uint32_t angka1, angka2;
    printf("Welcome to the Calculator \n");

    #if !defined(ANGKA1) && !defined(ANGKA2)    // Jika duaduanya undef
        printf("Enter 2 values: ");
        scanf("%u%u", &angka1, &angka2);
    #elif !defined(ANGKA1) || !defined(ANGKA2)  // Jika salah satu undef
        printf("Enter the other value: ");
        #ifdef ANGKA1                               // Jika angka1 def
            scanf("%u", &angka2);
            angka1 = ANGKA1;
        #elif defined(ANGKA2)                       // jika angka2 def
            scanf("%u", &angka1);
            angka2 = ANGKA2;
        #endif
    #else
        angka1 = ANGKA1;
        angka2 = ANGKA2;
    #endif

    printf("Hasil Perkalian:   %u\n      Pembagian:   %u\n", kali(angka1, angka2), bagi(angka1, angka2));
    printf("      Penambahan:  %u\n      Pengurangan: %u\n", jumlah(angka1, angka2), kurang(angka1, angka2));
}