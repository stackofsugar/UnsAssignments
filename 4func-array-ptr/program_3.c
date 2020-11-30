// (C) 2020 Christopher Digno
#include <stdio.h>

int sum(int (*arr)[4]){
    int i,
        sum = 0;

    for (i = 0; i < 3; i++){
        sum += *arr[i];
    }

    return sum;
}

int main() {
    int arr_main[3][4],
        i,
        j,
        buffer;
    printf("Enter integers to fill a 3x4 matrix...\n");

    for (i = 0; i < 3; i++){
        for (j = 0; j < 4; j++){
            printf("Enter number for [%d][%d]: ",i,j);
            scanf("%d",&buffer);
            arr_main[i][j] = buffer;
        }
    }

    printf("%d\n",sum(arr_main));
}