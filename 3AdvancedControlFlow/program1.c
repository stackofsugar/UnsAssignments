/* Write a program that prints the powers of 7 for nonnegative numbers less than 4
   You should use a repetition structure in your code
   0 -> 7^0
   1 -> 7^1
   2 -> 7^2
   3 -> 7^3

  * CATATAN:
  * Untuk pengguna gcc yang mendapatkan undefined reference untuk pow(),
  * silakan menambahkan compiler flag -lm untuk me resolve linker
  * misal: gcc program1.c -o program1.exe -static-libgcc -lm
  * - Christopher Digno
  */

#include <stdio.h>
#include <math.h>

int main() {
    int TEMP;
    for (int i = 0; i < 4; i++){
        TEMP = pow(i, 7);
        printf("%d^7 is %d\n",i,TEMP);
    }

    return 0;
}

/*
OUTPUT: 
0^7 is 0
1^7 is 1
2^7 is 128
3^7 is 2187
*/