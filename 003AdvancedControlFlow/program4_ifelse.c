/* 
 * Write a program that reads a grade point and prints its letter grade. (Implement two
 * different versions of your program using the followings to decide about the letter grade:
 * switch-case, if-else.) --> Cases based on Mrs. Umi Salamah's RPS Kalkulus
 * 
 * IF-ELSE version
 */

#include <stdio.h>

int main() {
    int grade,consent;

do{
    printf("Please enter your grade: ");
    scanf("%d",&grade);

    if (grade > 0 && grade < 55){
        printf("Your letter grade is E.");
    }
    else if (grade >= 55 && grade < 60){
        printf("Your letter grade is D.");
    }
    else if (grade >= 60 && grade < 65){
        printf("Your letter grade is C.");
    }
    else if (grade >= 65 && grade < 70){
        printf("Your letter grade is C+.");
    }
    else if (grade >= 70 && grade < 75){
        printf("Your letter grade is B.");
    }
    else if (grade >= 75 && grade < 80){
        printf("Your letter grade is B+.");
    }
    else if (grade >= 80 && grade < 85){
        printf("Your letter grade is A-.");
    }
    else if (grade >= 85 && grade < 100){
        printf("Your letter grade is A+.");
    }
    else {
        printf("INVALID GRADE");
    }
    printf("\n");

    /* Opsi untuk mengulang penggunaan program */
    printf("Do you want to use the program again? (0/1) \n> ");
    scanf("%d",&consent);
} while (consent == 1);
}


/*
Sample Output:
Please enter your grade: 77
Your letter grade is B+.
Do you want to use the program again? (0/1) 
> 1
Please enter your grade: 83
Your letter grade is A-.
Do you want to use the program again? (0/1) 
> 0
*/