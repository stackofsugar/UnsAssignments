// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// //fungsi-fungsi prototipe atau prototype function
// void selamatDatang();
// void transaksi(int* kPtr);
// void loginregister(int a);
// void check();

// //deklarasi structure untuk menyimpan data akun user dan diberi nama ( typedef ) dengan "Data"
// typedef	struct dt{
// 		char ID[20];
// 		char NAMA[50];
// 		int PIN;
// 		float SALDO;
// 	} Data;
	
// //deklarasi variabel structure dengan nama datauser dan berisi 20 elemen structure
// Data datauser[20];

// //deklarasi sebuah counter (increment-global atau ig) pengisian array structure bertipe data integer yang diberi nilai awal dengan nol 
// int ig=0;

	
// // utama
// int main(){
// 	selamatDatang();
// }



// //welcome
// void selamatDatang(){
// 	int lr;
	
// 	puts("Selamat Datang di Bank Aroleasia");
// 	puts("Tekan 0 untuk Keluar ");
// 	puts("Tekan 1 untuk Login ");
// 	puts("Tekan 2 untuk Register ");
		
// 	 //membaca input user tipe integer dan disimpan dalam variabel lr(login-register)
// 	printf("PILIHAN ANDA : ");
// 	scanf("%d",&lr);
	
// 	loginregister(lr);				
// }

// //body
// void transaksi(int* kPtr){
// 	int a=0;
// 	int tr;
// 	float tarik,setor;
	
// 	do{
// 		puts("\nSELAMAT, LOGIN BERHASIL!!!\n");
// 		puts("\nPilih Transaksi yang ingin dilakukan :");
// 		puts("1 --- Cek Saldo");
// 		puts("2 --- Tarik Saldo");	
// 		puts("3 --- Setor Saldo");	
		
// 		//membaca input user ,eksekusi program tergantung dari input user
// 		printf("PILIHAN ANDA : ");
// 		scanf("%d",&tr);
// 		switch(tr){
// 			case 1:
// 				printf("\nSaldo anda adalah :");
// 				printf("Rp%.2f\n",datauser[*kPtr].SALDO);
// 				break;
				
// 			case 2:
// 				printf("\nMasukkan jumlah saldo yang ingin ditarik : Rp");
// 				scanf("%f",&tarik);
// 					if(datauser[*kPtr].SALDO>=tarik){
// 						datauser[*kPtr].SALDO=datauser[*kPtr].SALDO-tarik;
// 						printf("\nSisa saldo anda sekarang adalah :");
// 						printf("Rp%.2f\n",datauser[*kPtr].SALDO);
// 						}
							
// 					else{
// 						puts("Maaf, saldo anda tidak cukup");
// 						break;
// 						}
// 				break;
				
// 			case 3:
// 				printf("\nMasukkan jumlah saldo yang ingin disetor : Rp");
// 				scanf("%f",&setor);
// 				datauser[*kPtr].SALDO=datauser[*kPtr].SALDO+setor;
				
// 				printf("Jumlah saldo anda sekarang adalah :");
// 				printf("Rp%.2f\n",datauser[*kPtr].SALDO);	
// 				break;
			
// 			default :
// 				transaksi(kPtr);
// 				break;	
// 		}
// 	puts("\nApakah anda ingin melakukan transaksi lagi ?");
// 	puts("Masukkan '1' jika ya\nMasukkan angka lain jika tidak");
// 	printf("PILIHAN ANDA : ");
// 	scanf("%d",&a);
// 	puts("");
// 	} while(a==1);

// 	return selamatDatang();
// }





// void loginregister(int a){
// 	int b=0,i=0,j,k,l,m;
// 	char IDhold[20];
// 	int PINhold;
// 	int g=0;
// 	float sld;
	
// 	switch(a){
// 		case 1:
// 			puts("\nMasukkan ID dan PIN");
					
// 			while(b==0 && IDhold[0]!=EOF){
				
				
// 				printf("ID\t: ");
// 				scanf("%s",&IDhold);
// 					if(IDhold[0]==EOF)
// 						selamatDatang();
// 				printf("PIN\t: ");
// 				scanf("%d",&PINhold);
					
				
							
// 					for(k=0; k<20; k++){
// 						if(k==19){
// 								if((strcmp(IDhold, datauser[k].ID) != 0) || (PINhold!=datauser[k].PIN)){
// 									puts("ID atau PIN tidak cocok, tolong masukkan ulang");
// 									puts("Atau masukkan EOF untuk kembali ke menu utama");
// 								}
// 								else{
// 									int* kPtr=&k;
// 									transaksi(kPtr);
// 									b=1;
// 									break;
// 								}
// 							}
								
// 						else{
// 								if((strcmp(IDhold, datauser[k].ID) == 0) && (PINhold==datauser[k].PIN)){
// 									int* kPtr=&k;							
// 									transaksi(kPtr);
// 									b=1;		
// 									break;
// 								}									
// 						}
// 					}				
// 					}
// 				break;
			
			
			
// 		//jika user menginput atau memasukkan 2, akan dimasukkan ke fungsi pendaftaran akun
// 		case 2:
// 			printf("\n%s\n%s\n%s\n","Masukkan maksimal 20 kata untuk ID","Masukkan angka untuk PIN","Masukkan maksimal 50 kata untuk NAMA");
// 			check();
// 			printf("PIN\t: ");
// 			scanf("%d",&datauser[ig].PIN);
// 			printf("NAMA\t: ");
// 			getchar();
// 			gets(datauser[ig].NAMA);
// 			puts("\nApakah anda ingin menyetor saldo pertama anda ?");
// 			puts("Tekan 1 untuk Ya");
// 			puts("Tekan 0 untuk Tidak");
// 			printf("PILIHAN ANDA : ");
// 			scanf("%d",&g);
// 				if(g==1){
// 					puts("\nMasukkan jumlah saldo untuk disetor");
// 					scanf("%f",&sld);
// 					datauser[ig].SALDO=sld;
// 				}
// 				else{
// 					datauser[ig].SALDO=0;
// 				}
			
// 			ig++;
// 			puts("\nSelamat, registrasi anda berhasil!!\n");
// 			selamatDatang();		
// 			break;
			
// 		default:
// 			break;		
// 	}	
// }




// void check(){
// 		char testid[20];
// 		int k=0,x=0;
		
// 		printf("ID\t: ");
// 		scanf("%s",&testid);
			
// 			for(k; k<20; k++){
// 				if(strcmp(datauser[k].ID,testid) == 0)
// 					{
// 					printf("ID sudah terpakai, masukkan ID lain\n");
// 					return check();
// 					}
// 				}
			
// 			for(x; x<20; x++){
// 				datauser[ig].ID[x]=testid[x];
// 				}
// }