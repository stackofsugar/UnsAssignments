/* 
 * cubism.c - Prints out the square and the cube of the numbers from 0 to 5.
 * (C) 2020 Christopher Digno | Some rights reserved
 */

#include <stdio.h>

int main() {
    int i;

    printf("Number \tSquare \tCube\n");
    printf("====================\n");

    for (i = 0; i <= 5; i++){
        printf("%d\t%d\t%d\n",i,i*i,i*i*i);
    }
}