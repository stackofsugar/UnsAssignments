// main.c :")
// FileCompare (C) 2020 Christopher Digno

#define DEBUGMODE_M             // <- disimpan jika ingin print debugging
#include "../include/stdafx.h"  // include precompiled header

int main(){
    int operation_choice, 
        match_hit = 0;
    char file_name1[40] = "../contoh_textfile/",
         file_name2[40] = "../contoh_textfile/",
         file_name_buffer[40],
         line_buffer1[256],
         line_buffer2[256];
    FILE *m_file1, *m_file2;

    printf("Welcome to FileCompare \n");
    printf("Enter the files you want to compare, please pick one in ../contoh_textfile or make it yourself in that folder. \nEnter the 1st file: ");
    scanf("%s", file_name_buffer);
    strcat(file_name1, file_name_buffer);   // Meng-append nama file supaya file jadi satu saja di ../contoh_textfile
    printf("Enter the 2nd file: ");
    scanf("%s", file_name_buffer);
    strcat(file_name2, file_name_buffer);
    DEBX(("%s and %s\n", file_name1, file_name2));

    m_file1 = fopen(file_name1, "r");
    m_file2 = fopen(file_name2, "r");
    if(!(m_file1) || !(m_file2)){           // Error checking sederhana
        printf("File can't be found/opened! Try to re-check your file path. \n");
        return exit_file_cant_be_opened;
    }
    else {
        while(fgets(line_buffer1, sizeof(line_buffer1), m_file1)
            && fgets(line_buffer2, sizeof(line_buffer2), m_file2)){
                if(!(strcmp(line_buffer1, line_buffer2))){
                    match_hit++;
                    // DEB("Match -> "); DEB(line_buffer1);    // Bentuk string masih ber-\n harus dihilangkan supaya lebih tidak membuat stres
                    // Mari parsing dibawah ini:
                    line_buffer1[strcspn(line_buffer1, "\n")] = 0; // line_buffer2 basically tidak dipakai lagi dari sini
                    DEBX(("AFTER PARSING: %d. %s\n", match_hit, line_buffer1));
                }
        }
    }

    while(1){                               // Loop setelah program mendapatkan file buffer (setelah mengolah kedua file)
        printf("Choose your operation choice: \n");
        printf("[1] Print file buffer list\n");
        printf("[2] Delete n-th entry in the list \n");
        printf("[3] Pop List \n");
        printf("[Other] Exit program \n");
        operation_choice = intScan(2, 0);

        if(operation_choice == eCompareFile){

        }
        else if(operation_choice == eFileManip){

        }
    }
}