// program.h
// Berisi fungsi-fungsi nonspesifik
// (C) 2020 Christopher Digno

#ifndef PROGRAM_H_
#define PROGRAM_H_

/*
 "Menambahkan" sendiri struktur data bool jika user menggunakan
 compiler C
*/
#ifndef __cplusplus
  typedef int bool;
# define true 1
# define false 0
#endif //__cplusplus

/*
 Membuat definisi debug printing
*/
#ifdef DEBUGMODE_M
# define DEB(args_) printf("%s", args_)
# define DEBX(args_) printf args_       // <- eksperimen pribadi
#else
# define DEB(args_)
# define DEBX(args_)
#endif // DEBUGMODE_M

/*
 Enum (atau beberapa enum) untuk mempermudah decision making
*/
enum OperationChoice {
    och_PrintList = 1,
    och_ModifyList,
    och_ExportList
} operation_choice;

enum ModificationChoice {
    mch_DeleteList = 1,
    mch_InsertList,
    mch_ChangeValue
} modification_choice;

/*
 Kode return sederhana untuk mempermudah development
*/
enum ReturnCodes {
    exit_success,
    exit_file_cant_be_opened,

} return_codes;

/*
 Fungsi yang digunakan untuk memvalidasi masukan integer pengguna, 
 dalam skenario jika pengguna memasukan bukan angka.

 @param in_ceiling Batas atas masukan
 @param in_floor Batas bawah masukan 
 @return int, berupa hasil scan masukan keyboard
*/
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

#endif // PROGRAM_H_