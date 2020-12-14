#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fpt;

    fpt = fopen("test.txt", "w");
    if(!fpt){
        printf("Fatal Error! File couldn't be opened");
        return 0;
    }
    else {
        printf("Enter a double point and a fruit, EOF to terminate.\n");
        double number;
        char fruit[20];
        printf("> ");
        scanf("%lf%19s", &number, fruit);
        while(!feof(stdin)){
            fprintf(fpt, "%.2lf - %s\n", number, fruit);
            printf("> ");
            scanf("%lf%19s", &number, fruit);
        }
        fclose(fpt);
    }
}
