/* Write a program to compute the factorial of the given nonnegative integer. */

#include <stdio.h>

int main() {
    int num,consent;
    unsigned long fac = 1;

do{
    printf("Enter a nonnegative integer: ");
    scanf("%d",&num);
    
    for (int i = num; i > 0; i--){
        fac *= i;
    }

    printf("%d! = %lu",num,fac);
    printf("\n");

    /* Opsi untuk mengulang penggunaan program */
    printf("Do you want to use the program again? (0/1) \n> ");
    scanf("%d",&consent);
    fac = 1;
} while (consent == 1);

    return 0;
}


/*
Sample Output:
Enter a nonnegative integer: 5
5! = 120
Do you want to use the program again? (0/1) 
> 1
Enter a nonnegative integer: 8
8! = 40320
Do you want to use the program again? (0/1) 
> 0
*/