#include <stdio.h>
#define PRINTARRAY(arr_size, main_arr)      \
        printf("Array is: \n");             \
        for(int i = 0; i < arr_size; i++){  \
            printf("%d ", main_arr[i]);     \
        }                                   \
        printf("\n")                             

int main(){
    int arr_size;
    printf("Array size: ");
    scanf("%d", &arr_size);

    int main_arr[arr_size];
    printf("Enter space-separated array elements \n");
    for(int i = 0; i < arr_size; i++){
        scanf("%d", &main_arr[i]);
    }

    PRINTARRAY(arr_size, main_arr);
}