#include <stdio.h>
#define MINIMUM2(x,y) (((x) < (y)) ? x : y)

int main(){
    int num1, num2;

    printf("Please enter 2 space-separated integers \n> ");
    scanf("%d%d", &num1, &num2);

    printf("The smallest integer is %d \n", MINIMUM2(num1, num2));
}