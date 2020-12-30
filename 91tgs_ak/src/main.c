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
    int operation_choice;
    char file_name1[40] = "../contoh_textfile/",
         file_name2[40] = "../contoh_textfile/",
         file_name_buffer[40],
         line_buffer1[256],
         line_buffer2[256];
    FILE *m_file1, *m_file2;

    printf("Welcome to FileCompare (C) 2020 Christopher Digno\n");
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
        printf("File can't be found/opened! Try to re-check your file name/path. \n");
        return exit_file_cant_be_opened;
    }
    else {
        fseek(m_file1, 0, SEEK_SET);
        while(fgets(line_buffer1, sizeof(line_buffer1), m_file1)){
            while(fgets(line_buffer2, sizeof(line_buffer2), m_file2)){
                if(!(strcmp(line_buffer1, line_buffer2))){
                    g_similar_count++;                                          // Mengincrement counter
                    DEBX(("MATCH #", g_similar_count, ": ", line_buffer1));
                    line_buffer1[strcspn(line_buffer1, "\n")] = 0;              // Mengenolkan newline di data yang dibaca
                    ll_insert(line_buffer1, -1);                                // Memasukkan ke linkedlist, mode append
                }
            }
            fseek(m_file2, 0, SEEK_SET);
        }
    }

    fclose(m_file1);
    fclose(m_file2);
    printf("We have found %d similarities \n", g_similar_count);

    while(1){                                                                   // Loop setelah program mendapatkan file buffer (setelah mengolah kedua file)
        operation_choice = 0;
        printf("Choose your operation choice: \n");
        printf("[1] Print the Similarity List\n");
        printf("[2] Modify Similarity List \n");
        printf("[3] Generate Similarity List report to a new text file \n");
        printf("[Other] Exit program \n> ");
        operation_choice = intScan(limitof_int, -limitof_int);

        if(operation_choice == och_PrintList){
            printf("Similarities of 2 files: \n");
            ll_testprint();
        }
        else if(operation_choice == och_ModifyList){
            int nth_value = 0;
            printf("Choose your modification operation: \n");
            printf("[1] Remove n-th list value \n"); 
            printf("[2] Insert before n-th list value \n"); 
            printf("[3] Change n-th list value's data \n");
            printf("[Other] Back to menu \n> "); 
            operation_choice = intScan(limitof_int, -limitof_int);

            if(operation_choice == mch_DeleteList){
                printf("Enter your nth-value: ");
                nth_value = intScan(g_similar_count, 0);
                ll_deletel(nth_value);
                g_similar_count--;
            }
            else if(operation_choice == mch_InsertList){
                printf("Enter your nth-value (-1 to append): ");
                nth_value = intScan(g_similar_count + 1, -1);
                char data[256];
                printf("Enter your new data: ");
                scanf("%[^\n]%*c", data);
                ll_insert(data, nth_value);
            }
            else if(operation_choice == mch_ChangeValue){
                printf("Enter your nth-value: ");
                nth_value = intScan(g_similar_count, 0);
                char data[256];
                printf("Enter your new data: ");
                scanf("%[^\n]%*c", data);
                ll_insert(data, nth_value);
                ll_deletel(nth_value + 1);
            }
            else {
                continue;
            }
        }
        else if(operation_choice == och_ExportList){
            printf("We will export the similarity list report to the path ../contoh_textfile/<yourfile>.txt \n");
            while(1){
                printf("Enter your file name, eg. \"report.txt\" \n> ");
                char rep_file_name[40] = "../contoh_textfile/";
                scanf("%[^\n]%*c", file_name_buffer);
                strcat(rep_file_name, file_name_buffer);

                // Mengecek apakah file dengan nama tsb ada atau tidak. Kalau ada, loop kembali keatas
                FILE *report_file;
                if((report_file = fopen(rep_file_name, "r"))){
                    printf("The file %s exists. Please choose a different name \n", file_name_buffer);
                    fclose(report_file);
                }
                else {
                    report_file = fopen(rep_file_name, "w");
                    assert(report_file);
                    fprintf(report_file, "== SIMILARITY REPORT FILE == \nAutomatically generated by FileCompare \n\nx_x Compared files x_x: ");
                    fprintf(report_file, "%s and %s \n\n== REPORT BEGIN == \n", file_name1, file_name2);

                    if(!(head)){
                        fprintf(report_file, ".: THE LIST IS EMPTY :. \n");
                    }
                    else {
                        LinkedList *printbuf = head;
                        for(int i = 1; printbuf; i++){
                            fprintf(report_file, "MATCH #%d: %s \n", i, printbuf->data);
                            printbuf = printbuf->next;
                        }
                    }

                    fprintf(report_file, "== REPORT END ==");
                    fclose(report_file);
                    break;
                }
            }
        }
        else {
            break;
        }
    }

    ll_memcleanup();
}