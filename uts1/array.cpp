#include <stdio.h>

int main() {
    int arr[3][3];
    bool iscorrect = true;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            do {
                scanf("%d", &arr[i][j]);
                if (arr[i][j] < 100 || arr[i][j] > 1000){
                    iscorrect = false;
                    printf("Your input should be between 100-1000! Try again! \n> ");
                }
                else {
                    iscorrect = true;
                }
            }
            while (iscorrect == false);
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if ((arr[i][j] % 2) == 0){
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}