/* 
 * controlflow.c - Performs several control flow implementation 
 * (C) 2020 Christopher Digno | Some rights reserved
 */

#include <stdio.h>

int main() {
    int global_consent,end_consent;
    long global_num,num1,num2;
    double numa,numb,TEMP;
do {
    printf("controlflow\n(C) 2020 Christopher Digno\n");
    printf("What operation do you want to conduct?\n1. Odd/Even detector\n2. Sign detector\n3. Big and Small\n4. Float Mulpiplix\nYour choice: ");
    scanf("%d", &global_consent);

do{
    if (global_consent == 1){ // Section 1: Read an integer from keyboard and print out whether it is odd or even
        printf("Please enter an integer: ");
        scanf("%ld", &global_num);
        if (global_num % 2 == 0){
            printf("%ld is an even number.", global_num);
        }
        else {
            printf("%ld is an odd number.", global_num);
        }
    } // end if section 1
    else if (global_consent == 2){ // Section 2: Scan an integer from keyboard and print out whether it is positive or negative
        printf("Please enter an integer: ");
        scanf("%ld", &global_num);
        if (global_num < 0){
            printf("%ld is negative.", global_num);
        }
        else {
            printf("%ld is is positive.", global_num);
        }
    } // end if section 2
    else if (global_consent == 3) {
        printf("Please enter two integers: ");
        scanf("%ld %ld", &num1,&num2);
        if (num1 < num2){
            printf("%ld is smaller than %ld.", num1,num2);
        }
        else {
            printf("%ld is smaller than %ld.", num2,num1);
        }
    }// end if section 3
    else if (global_consent == 4){
        printf("Please enter two real numbers: ");
        scanf("%lf%lf",&numa,&numb);
        TEMP = numa * numb;
        printf("The multiplication result is %lf",(TEMP));
    }// end if section 4
    else { // Throw error
        printf("Unknown value entered.\n");
        return 0;
    }   

    printf("\nEnter 0 to exit, 1 to repeat last, 2 to go to home screen > ");
    scanf("%d", &end_consent);
    if (end_consent == 0){
        return 0;
    }
} while (end_consent == 1);
} while (end_consent == 2);
}