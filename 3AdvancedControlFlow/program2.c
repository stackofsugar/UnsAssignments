/* Write a program that reads two integers and calculates the following arithmetic
   operations: addition, subtraction, multiplication, division and square root.

  * CATATAN:
  * Untuk pengguna gcc yang mendapatkan undefined reference untuk pow(),
  * silakan menambahkan compiler flag -lm untuk me resolve linker
  * misal: gcc program1.c -o program1.exe -static-libgcc -lm
  * - Christopher Digno
*/

#include <stdio.h>
#include <math.h>

int main() {
    int numA,numB,numAns,consent,whileconst;

do{
    printf("Please enter two integers: ");
    scanf("%d%d",&numA,&numB);
    printf("Please choose an operation: \nPress 1 for ADDITION\nPress 2 for SUBTRACTION\nPress 3 for MULTIPLICATION\nPress 4 for DIVISION\nPress 5 for SQUARE ROOT\nPress 6 for EXIT\n> ");
    scanf("%d",&consent);

    switch (consent){
    case 1 : // ADDITION
        printf("The result is %d.", (numA + numB));
        break;
    case 2: // SUBS
        printf("The result is %d.", (numA - numB));
        break;
    case 3: // MULTIPLY
        printf("The result is %d.", (numA * numB));
        break;
    case 4: // DIVISION
        printf("The result is %d.", (numA / numB));
        break;
    case 5: //SQRT
        printf("sqrt of %d is %d while sqrt of %d is %d.", numA,(int)sqrt(numA),numB,(int)sqrt(numB)); // Forcing sqrt untuk return int -> pendekatan
        break;                                                     /* ^- kalau tidak pakai -lm bisa undefined di cmath */
    case 6: // EXIT
        return 0;
    default:
        printf("CASE UNDEFINED!");
    }

    printf("\n");

    /* Opsi untuk mengulang penggunaan program */
    printf("Do you want to use the program again? (1/0)\n> ");
    scanf("%d",&whileconst);
} while (whileconst == 1);

    return 0;
}


/*
Sample Output:
Please enter two integers: 20 50
Please choose an operation: 
Press 1 for ADDITION
Press 2 for SUBTRACTION
Press 3 for MULTIPLICATION
Press 4 for DIVISION
Press 5 for SQUARE ROOT
Press 6 for EXIT
> 3
The result is 1000.
Do you want to use the program again? (1/0)
> 0
*/