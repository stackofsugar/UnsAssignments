#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2;
    char linef1[50],
        linef2[50];

    file1 = fopen("testfiles/satu.txt", "r");
    file2 = fopen("testfiles/dua.txt", "r");
    if (!file1 || !file2) {
        printf("Woanjing gabisa dibuka\n");
        return 1;
    }

    while (fgets(linef1, sizeof(linef1), file1)) {
        printf("1-> %s", linef1);
    }
    fclose(file1);

    while (fgets(linef2, sizeof(linef2), file2)) {
        linef2[strcspn(linef2, "\n")] = 0;
        printf("2-> %s\n", linef2);
    }
    fclose(file2);
    
    // FILE *binfile;
    // binfile = fopen("testfiles/file.bin", "wb");
}