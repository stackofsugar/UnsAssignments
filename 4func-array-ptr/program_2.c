// (C) 2020 Christopher Digno
#include <stdio.h>

float sum(unsigned int x){
    if (x == 0){
        return 0;
    }
    else {
        return ( (1.0f/((2.0f*x)-1.0f)) + sum(x - 1));
    }
}

int main() {
    unsigned int iter;

    printf("Please enter a number to calculate the sequence \n> ");
    scanf("%u",&iter);
    printf("%f\n",sum(iter));
}