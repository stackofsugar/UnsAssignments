// (C) 2020 Christopher Digno
#include <stdio.h>

unsigned long long fibo(int x){
    if (x <= 1){
        return x;
    }
    else {
        return (fibo(x-1) + fibo(x-2));
    }
}

int main() {
    int iter,
        i;

    printf("Enter a positive number as Fibonacci iteration \n> ");
    scanf("%d",&iter);
    for (i = 0; i < iter; i++){
        printf("%llu ",fibo(i));
    }
    printf("\n");
}