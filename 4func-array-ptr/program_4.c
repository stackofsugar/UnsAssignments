// (C) 2020 Christopher Digno
#include <stdio.h>

const double g_5p9 = 0.55555555555,
             g_9p5 = 1.8;

void celcToFah(double* x){
    double bufx,
           bufres;

    bufx = *x;
    bufres = ((bufx * g_9p5) + 32);
    printf("%lf",bufres);
}
void fahToCelc(double* x){
    double bufx,
           bufres;
    
    bufx = *x;
    bufres = ((bufx - 32) * g_5p9);
    printf("%lf",bufres);
}

int main() {
    double in_temp;
    int consent;
        
    printf("Please enter the temperature you want to convert. \n> ");
    scanf("%lf",&in_temp);
    printf("Please choose an operation \n1. C -> F \n2. F -> C \n> ");
    scanf("%d",&consent);
    
    if (consent == 1){
        celcToFah(&in_temp);
        printf(" degrees F\n");
    }
    else if (consent == 2){
        fahToCelc(&in_temp);
        printf(" degrees C\n");
    }
    else {
        printf("EXCEPTION: Unknown value entered.");
    }
    
}