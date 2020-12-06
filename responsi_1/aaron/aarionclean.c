# 1 "aarion.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# 13 "aarion.c"
void selamatDatang();
void loginregister(int a);
void transaksi(int* kPtr);
void headerLoginRegistrasi(int login, int regis);
void headerTransaksi(int*kPtr);
float scannerFloat(float x);
int scannerBasic(int x, int y);
int scannerPIN();
void regisID();


typedef struct dt{
  char ID[20];
  char NAMA[50];
  int PIN;
  float SALDO;
 } Data;


Data datauser[20];



int ig=0;



int main(){
 selamatDatang();
 return 0;
}




void selamatDatang(){

 int lr;
 puts("\n------------------------------------------------------------------------------------------------------------------------\n");
 puts("\t\t\t\t== SELAMAT DATANG DI BANK VIRTUAL AAROLEASIA ==");
 puts("\t\t\t\t\t     == SILAKAN LOGIN ==");
 puts("\t\t\t\t    == REGISTER JIKA BELUM MEMILIKI AKUN ==");
 puts("\n------------------------------------------------------------------------------------------------------------------------\n");
 puts("Tekan 1 untuk Login ");
 puts("Tekan 2 untuk Registrasi ");
 puts("Tekan lainnya untuk Keluar\n ");



 printf("PILIHAN ANDA : ");
 scanf("%d",&lr);

 loginregister(lr);
}


void loginregister(int a){
 int b=0,k,g;
 char IDhold[20];
 int PINhold;
 float sld;



 switch(a){

  case 1:
   headerLoginRegistrasi(1,0);
   puts("\nMasukkan ID dan PIN");


   while(b==0){
    printf("ID\t: ");
    scanf("%s",&IDhold);;


    if (feof(stdin)){
      selamatDatang();
      break;
    }

    else{


     PINhold=scannerPIN();





     for(k=0; k<20; k++){
      if(k==19){




        if((strcmp(IDhold, datauser[k].ID) != 0) || (PINhold!=datauser[k].PIN)){



         puts("ID atau PIN tidak cocok, tolong masukkan ulang");
         puts("Atau masukkan EOF untuk kembali ke menu utama\n");
        }
        else{







         int* kPtr=&k;
         puts("\nSELAMAT, LOGIN BERHASIL!!!\n");

         transaksi(kPtr);
         b=1;
         break;
        }
      }

      else{


        if((strcmp(IDhold, datauser[k].ID) == 0) && (PINhold==datauser[k].PIN)){







         int* kPtr=&k;
         puts("\nSELAMAT, LOGIN BERHASIL!!!\n");

         transaksi(kPtr);
         b=1;
         break;
        }
      }
     }
    }
   }
  break;




  case 2:
   headerLoginRegistrasi(0,1);
   if(ig==20){






    puts("Maaf, jumlah akun yang terdaftar sudah maksimal");
    puts("Silakan memulai ulang program...\n");

    selamatDatang();
    break;
   }

   else{


   regisID();
   if (feof(stdin)){

      selamatDatang();
      break;
       }
   datauser[ig].PIN=scannerPIN();

   printf("NAMA\t: ");
   getchar();

            scanf("%[^\n]%*c", datauser[ig].NAMA);


   puts("\nApakah anda ingin menyetor saldo pertama Anda ?");
   puts("Tekan 1 untuk Ya");
   puts("Tekan 0 untuk Tidak\n");

   g=scannerBasic(0,1);
    if(g==1){


     printf("\nMasukkan jumlah saldo untuk disetor : Rp ");
     sld=scannerFloat(0);
     datauser[ig].SALDO=sld;
    }
    else if(g==0){


     datauser[ig].SALDO=0;
    }

   ig++;


   puts("\nSELAMAT, REGISTRASI ANDA BERHASIL !\n");



   selamatDatang();
   break;
   }



  default:
   puts("\nTERIMA KASIH TELAH MENGGUNAKAN BANK VIRTUAL AAROLEASIA\n");

   break;
 }
}


void transaksi(int* kPtr){
 int a,h=0,i=0;
 int holder[20];
 int tr;
 float tarik,setor,transfer;
 int hitungrekening,pilihan;
 char pembanding[1]={};

 do{

  headerTransaksi(kPtr);

  a=0;



  switch(scannerBasic(1,4)){
   case 1:


    printf("\nSaldo Anda adalah :");
    printf("Rp %.2f\n",datauser[*kPtr].SALDO);
    break;

   case 2:


    printf("\nMasukkan jumlah saldo yang ingin Anda tarik : Rp ");
    tarik=scannerFloat(0);
     if(datauser[*kPtr].SALDO>=tarik){



      datauser[*kPtr].SALDO=datauser[*kPtr].SALDO-tarik;
      printf("\nSisa saldo Anda sekarang adalah :");
      printf("Rp %.2f\n",datauser[*kPtr].SALDO);
      }
     else{


      puts("Maaf, saldo anda tidak cukup");
      }
    break;

   case 3:


    printf("\nMasukkan jumlah saldo yang ingin Anda setor : Rp ");
    setor=scannerFloat(0);


    datauser[*kPtr].SALDO=datauser[*kPtr].SALDO+setor;
    printf("Jumlah saldo anda sekarang adalah :");
    printf("Rp %.2f\n",datauser[*kPtr].SALDO);
    break;

   case 4:

    puts("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                === DAFTAR REKENING BANK VIRTUAL AAROLEASIA ===\n");
    puts("\n------------------------------------------------------------------------------------------------------------------------\n");




    printf("NOMOR AKUN\t\tNAMA NASABAH\n");



     for(hitungrekening=0 ; hitungrekening<20; hitungrekening++){
      if(strcmp(datauser[hitungrekening].ID,pembanding) != 0){




      printf("%d\t\t\t%s\n",hitungrekening,datauser[hitungrekening].NAMA);


      holder[h]=hitungrekening;
      h++;
      }
     }


    puts("\nMasukkan Nomor Akun yang ingin Anda transfer (0--19)");

    do{
      pilihan=scannerBasic(0,19);
     if (feof(stdin)){


      selamatDatang();
      return;
       }
     else if(pilihan==*kPtr){


      puts("Anda tidak dapat mentransfer ke diri anda sendiri. Silakan coba lagi");
      puts("Atau masukkan EOF untuk kembali ke menu utama\n");
     }
     else {


      for(i=0; i<=20; i++){
       if(pilihan==holder[i]){


        a=1;
        break;
       }
       else if(i==20){




        puts("Nomor Akun yang anda masukkan tidak terdaftar. Silakan coba lagi");
        puts("Atau masukkan EOF untuk kembali ke menu utama\n");
       }

      }
     }

    }while(a==0);


    printf("\nMasukkan Jumlah Saldo yang ingin ditransfer : Rp ");

    transfer=scannerFloat(0);
     if(datauser[*kPtr].SALDO>=transfer){




      datauser[*kPtr].SALDO=datauser[*kPtr].SALDO-transfer;
      datauser[pilihan].SALDO=datauser[pilihan].SALDO+transfer;
      printf("\nSisa saldo anda sekarang adalah :");
      printf("Rp %.2f\n",datauser[*kPtr].SALDO);
      }

     else{


      puts("Maaf, saldo anda tidak cukup");
      }
    break;

   default :
    break;
  }


 puts("\nApakah anda ingin melakukan transaksi lagi ?");
 puts("Tekan 1 untuk melakukan transaksi ulang\nTekan 0 untuk kembali ke Menu Utama\n");
 a=scannerBasic(0,1);
 puts("");
 } while(a==1);


 return selamatDatang();
}



void headerLoginRegistrasi(int login, int regis){

 if(login==1){

    puts("\n------------------------------------------------------------------------------------------------------------------------\n");
    puts("\t\t\t\t\t     == HALAMAN LOGIN ==");
    puts("\n------------------------------------------------------------------------------------------------------------------------\n");

 }
 else if(regis==1){

   puts("\n------------------------------------------------------------------------------------------------------------------------\n");
   puts("\t\t\t\t\t     == HALAMAN REGISTRASI ==");
   puts("\n------------------------------------------------------------------------------------------------------------------------\n");
 }

    printf("\n%s\n%s\n%s\n\n",
      "**Masukkan maksimal 20 karakter/huruf tanpa spasi untuk ID",
      "**Masukkan sebanyak 6 digit bilangan bulat positif untuk PIN",
      "**Masukkan maksimal 50 karakter/huruf untuk NAMA");
}


void headerTransaksi(int*kPtr){
 puts("\n------------------------------------------------------------------------------------------------------------------------\n");
   puts("\t\t\t\t\t     == HALAMAN TRANSAKSI ==");
   puts("\n------------------------------------------------------------------------------------------------------------------------\n");
  printf("NAMA NASABAH : ");
  printf("%s\n",datauser[*kPtr].NAMA);
  puts("\nPilih Transaksi yang ingin Anda lakukan :");
  puts("1 --- Cek Saldo");
  puts("2 --- Tarik Saldo");
  puts("3 --- Setor Saldo");
  puts("4 --- Transfer Saldo\n");
}




float scannerFloat(float x){
 float tr;

 while(1){
  if(scanf("%f%*c",&tr)){


   if(tr<=x){

    printf("Masukan Anda tidak valid! Silakan coba lagi\n\n");
     printf("\nMasukkan Jumlah Saldo : Rp ");

   }
   else{


    return tr;
   }
  }
  else{


   printf("Masukan Anda tidak valid! Silakan coba lagi\n\n");
   printf("\nMasukkan Jumlah Saldo : Rp ");
   scanf("%*c");
  }
 }

}


int scannerBasic(int x, int y){
 int tr;

 printf("PILIHAN ANDA : ");

 while(1){
  if(scanf("%d%*c",&tr)){


   if(tr<x || tr>y){


    printf("Masukan Anda tidak valid! Silakan coba lagi\n\n");
    printf("PILIHAN ANDA : ");
   }
   else{



    return tr;
   }
  }
  else{


   printf("Masukan Anda tidak valid! Silakan coba lagi\n\n");
   printf("PILIHAN ANDA : ");
   scanf("%*c");
  }
 }

}


int scannerPIN(){
 int pilihan,holder,counter;
 printf("PIN\t: ");

 while(1){
  if(scanf("%*c%d",&pilihan)){


   if(pilihan>=0){




    counter=0;
    holder=pilihan;



    while(pilihan!=0){





     pilihan=pilihan/10;
     counter++;
    }




    pilihan=holder;

    if(counter!=6){


     printf("Masukkan PIN tepat 6 digit ! \n\n");
     printf("PIN : ");
    }
    else {


     return pilihan;
    }
   }
   else{


    puts("Masukkan input-an yang valid !\n");
    printf("PIN : ");
   }

  }

  else{


   printf("Input-an tidak valid !\n\n");
   scanf("%*c");

   printf("PIN : ");
  }
 }
}


void regisID(){
  char testid[20];
  int k=0,x=0;

  headerLoginRegistrasi(0,1);


  printf("ID\t: ");
  scanf("%s",&testid);
# 583 "aarion.c"
   for(k; k<20; k++){
    if(strcmp(datauser[k].ID,testid) == 0)
     {





     printf("ID sudah terpakai, masukkan ID lain\n");
     puts("Atau masukkan EOF untuk kembali ke MENU UTAMA\n");

     return regisID();
     }
    }


   for(x; x<20; x++){
    datauser[ig].ID[x]=testid[x];
    }
}
