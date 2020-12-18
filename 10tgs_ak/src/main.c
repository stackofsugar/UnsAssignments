// main.c :")
// FileCompare (C) 2020 Christopher Digno

// #define DEBUGMODE_M              // <- dipakai jika ingin print debugging
#include "../include/stdafx.h"      // include precompiled header

#define ll_insert(_arg1, _arg2) head = insert(head, _arg1, _arg2)
#define ll_testprint() testprint(head)
#define ll_deletel(_arg) head = deletel(head, _arg)
#define ll_memcleanup() head = memcleanup(head)

#define limitof_int 2147483647 

LinkedList *head = NULL;          // Inisialisasi linked list
int g_similar_count = 0;

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
                    DEB("Match -> "); DEB(line_buffer1);                            // Bentuk string masih ber-\n harus dihilangkan supaya lebih tidak membuat stres
                    // Mari parsing dibawah ini:
                    line_buffer1[strcspn(line_buffer1, "\n")] = 0;                  // line_buffer2 basically tidak dipakai lagi dari sini
                    DEBX(("AFTER PARSING: %d. %s\n", match_hit, line_buffer1));
                    ll_insert(line_buffer1, -1);                                    // menginvoke linkedlist
                    g_similar_count++;
                }
        }
    }

    fclose(m_file1);
    fclose(m_file2);
    printf("We have found %d similarities \n", g_similar_count);

    while(1){                                                                       // Loop setelah program mendapatkan file buffer (setelah mengolah kedua file)
        operation_choice = 0;
        printf("Choose your operation choice: \n");
        printf("[1] Print the Similarity List\n");
        printf("[2] Delete n-th entry in the Similarity List \n");
        printf("[3] Modify Similarity List \n");
        printf("[4] Export Similarity List to a new text file \n");
        printf("[Other] Exit program \n> ");
        operation_choice = intScan(limitof_int, 0);

        if(operation_choice == och_PrintList){
            ll_testprint();
        }
        else if(operation_choice == och_DeleteList){
            printf("Which list number you want to delete? \n> ");
            operation_choice = intScan(g_similar_count, 0);
            ll_deletel(operation_choice);
            printf("Deleted list number %d\n", operation_choice);
            g_similar_count--;
        }
        else {
            break;
        }
    }

    ll_memcleanup();
}