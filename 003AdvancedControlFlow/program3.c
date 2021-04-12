#include <stdio.h>

int main() {
    int sum = 0;

    for (int i = 0; i <= 9; i++){
        sum += i;
    }

    printf("Sum of the integers within the range [0 , 9] is %d\n\n",sum);
    
    printf("NUMBERS: \n");

    for (int a = 1; a <= 5; a++){
        for (int j = 0; j < a; j++){
            printf("%d",a);
        }
        printf("\n");
    }
    return 0;
}

/*
OUTPUT:
Sum of the integers within the range [0 , 9] is 45

NUMBERS: 
1
22
333
4444
55555
*/
