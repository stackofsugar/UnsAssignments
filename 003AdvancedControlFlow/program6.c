/* 
 * Write a program that reads the grades of “10” students and prints whether the students are
 * passed the course or not. Your program should take a grade and then tell if it is 
 * honor [100-85], 
 * satisfactory (85-60] or 
 * unsatisfactory (60-0]. 
 * It should also display the total numbers of the students in each category.
 * 
 * (HW: Modify your answer to Question#3 such that the number of the students of the
 * course is not known at the beginning. Assume that the user enters -1 to quit.)
 */

#include <stdio.h>

int main(){
    int grade, consent,
        sat = 0,
        unsat = 0,
        hon = 0;
    printf("Please enter the grades (enter -1 to end): \n");

    do{
    do{
        scanf("%d",&grade);
        switch (grade){
            case 0 ... 59:
                printf("%d is unsatisfactory.\n",grade);
                unsat++;
                break;
            case 60 ... 84:
                printf("%d is satisfactory.\n",grade);
                sat++;
                break;
            case 85 ... 100:
                printf("%d is an honor grade.\n",grade);
                hon++;
                break;
            default:
                break;
        }
    } while (grade >= 0);

    printf("Total number of honor students: %d",hon);
    printf("\nTotal number of satisfactory students: %d",sat);
    printf("\nTotal number of unsatisfactory students: %d\n",unsat);

    sat = 0; unsat = 0; hon = 0;
    /* Opsi untuk mengulang penggunaan program */
    printf("Do you want to use the program again? (0/1) \n> ");
    scanf("%d",&consent);
    } while (consent == 1);

    return 0;
}




/*
Sample Output:
Please enter the grades (enter -1 to end): 
59
59 is unsatisfactory.
60
60 is satisfactory.
84
84 is satisfactory.
85
85 is an honor grade.
100
100 is an honor grade.
-1
Total number of honor students: 2
Total number of satisfactory students: 2
Total number of unsatisfactory students: 1
*/