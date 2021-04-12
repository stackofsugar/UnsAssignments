/* 
 * Write a program that reads a grade point and prints its letter grade. (Implement two
 * different versions of your program using the followings to decide about the letter grade:
 * switch-case, if-else.) --> Cases based on Mrs. Umi Salamah's RPS Kalkulus
 * 
 * SWITCH version
 */

#include <stdio.h>

int main() {
    int grade,consent;

do{
    printf("Please enter your grade: ");
    scanf("%d",&grade);

    switch (grade){
        case 0 ... 54:
            printf("Your letter grade is E.");
            break;
        case 55 ... 59:
            printf("Your letter grade is D.");
            break;
        case 60 ... 64:
            printf("Your letter grade is C.");
            break;
        case 65 ... 69:
            printf("Your letter grade is C+.");
            break;
        case 70 ... 74:
            printf("Your letter grade is B.");
            break;
        case 75 ... 79:
            printf("Your letter grade is B+.");
            break;
        case 80 ... 84:
            printf("Your letter grade is A-.");
            break;
        case 85 ... 100:
            printf("Your letter grade is A.");
            break;
        default:
            printf("INVALID GRADE");
            break;
    }
    printf("\n");

    /* Opsi untuk mengulang penggunaan program */
    printf("Do you want to use the program again? (0/1) \n> ");
    scanf("%d",&consent);
} while (consent == 1);
    return 0;
}


/*
Sample Output:
Please enter your grade: 87
Your letter grade is A.
Do you want to use the program again? (0/1) 
> 1
Please enter your grade: 63
Your letter grade is C.
Do you want to use the program again? (0/1) 
> 0
*/