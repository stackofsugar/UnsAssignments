// program.c
// (C) 2020 Christopher Digno

#include "../include/stdafx.h"

int intScan(int in_ceiling, int in_floor){
    int buffer;
    while(1){
        if(scanf("%d%*c", &buffer)){
            if(buffer < in_floor){
                printf("Masukan terlalu rendah! Coba lagi: ");
            } else if(buffer > in_ceiling){
                printf("Masukan terlalu tinggi! Coba lagi: ");
            } else {
                return buffer;
            }
        } else {
            printf("Masukan tidak valid! Coba lagi: ");
            scanf("%*c");
        }
    }
}