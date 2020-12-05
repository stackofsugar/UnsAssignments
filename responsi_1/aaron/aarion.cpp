#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 		RESPONSI KONSEP PEMROGRAMAN
		UNIVERSITAS SEBELAS MARET
			INFORMATIKA 2020
	NAMA	: Christopher Aaron Widodo
	NIM		: M0520019
*/

//fungsi-fungsi prototipe atau prototype function
void selamatDatang();
void loginregister(int a);
void transaksi(int* kPtr);
void headerLoginRegistrasi(int login, int regis);
void headerTransaksi(int*kPtr);
float scannerFloat(float x);
int scannerBasic(int x, int y);
int scannerPIN();
void regisID();

//deklarasi structure untuk menyimpan data akun user dan diberi nama ( typedef ) dengan "Data"
typedef	struct dt{
		char ID[20];
		char NAMA[50];
		int PIN;
		float SALDO;
	} Data;
	
//deklarasi variabel structure dengan nama datauser dan berisi 20 elemen structure
Data datauser[20];

//deklarasi sebuah integer yang diberi nilai awal dengan nol 
//(increment-global atau ig) akan digunakan sebagai counter pengisian array dari structure
int ig=0;

	
// utama
int main(){
	selamatDatang();
	return 0;
}



//welcome
void selamatDatang(){
	// here lies system("cls");
	int lr;
	puts("\n------------------------------------------------------------------------------------------------------------------------\n");
	puts("\t\t\t\t== SELAMAT DATANG DI BANK VIRTUAL AAROLEASIA ==");
	puts("\t\t\t\t\t     == SILAKAN LOGIN ==");	
	puts("\t\t\t\t    == REGISTER JIKA BELUM MEMILIKI AKUN ==");
	puts("\n------------------------------------------------------------------------------------------------------------------------\n");
	puts("Tekan 1 untuk Login ");
	puts("Tekan 2 untuk Registrasi ");
	puts("Tekan lainnya untuk Keluar\n ");
		
	 //membaca input user tipe integer 
	 //dan disimpan dalam variabel lr(login-register)
	printf("PILIHAN ANDA : ");
	scanf("%d",&lr);
	
	loginregister(lr);	
}

//fungsi untuk melakukan registrasi atau login
void loginregister(int a){
	int b=0,k,g;
	char IDhold[20];
	int PINhold;
	float sld;
	
	//parameter a yang dioper kemudian akan dimasukkan
	//ke dalam fungsi switch-case berparameter a
	switch(a){
		//jika user menginput atau memasukkan 1, akan dimasukkan ke case login akun
		case 1:
			headerLoginRegistrasi(1,0);//fungsi untuk mencetak judul atau hedader halam login
			puts("\nMasukkan ID dan PIN");
					
			//dilakukan while-loop selama b bernilai 0
			while(b==0){						
				printf("ID\t: ");
				scanf("%s",&IDhold);;
				//JIKA pada standart input terbaca penginputan EOF(ctrl+d atau ctrl+z tergantung os)
				//user akan dimasukkan kembali ke dalam fungsi selamatDatang
				if (feof(stdin)){
						selamatDatang();
						break;
				}
				
				else{
					//Jika user tidak memasukkan EOF, maka akan dilakukan pendefinisian variabel PINhold oleh fungsi scannerPIN
					//syarat atau batasan yang diperlukan akan dijalankan dan diproses oleh fungsi scannerPIN
					PINhold=scannerPIN();
					
					//jika inputan sudah terbaca dengan benar, program akan masuk ke dalam fungsi for-loop 
					//pada loop ini, akan dilakukan pengecekan apakah ID dan PIN yang diinput oleh user terdaftar dan cocok
					//pengecekan dilakukan dengan membandingkan inputan user (IDhold dan PINhold) dengan structure datauser 

					for(k=0; k<20; k++){
						if(k==19){
							
							//jika pengecekan nilai k sudah mencapai 19 ( batas maksimal jumlah user atau akun yang dapat dibuat )
							//maka akan dilakukan pengecekan terakhir apakah ID dan PIN terdaftar
							//pembanding pada bagian ini adalah data user terakhir (datauser array index ke-19 )
								if((strcmp(IDhold, datauser[k].ID) != 0) || (PINhold!=datauser[k].PIN)){
									//jika ID inputan user (IDhold) dan PIN inputan user (PINhold) TIDAK sesuai dengan data structure
									//maka akan muncul pemberitahuan bahwa tidak cocok dan kemudian program akan kembali berjalan lagi
									// ( kembali ke line 81 )
									puts("ID atau PIN tidak cocok, tolong masukkan ulang");
									puts("Atau masukkan EOF untuk kembali ke menu utama\n");
								}
								else{
									//jika ID inputan user (IDhold) dan PIN inputan user (PINhold) SESUAI dengan data structure
									//maka program akan memunculkan pemberitahuan bahwa berhasil 
									//dan kemudian  layar/stdout akan di-pause 
									
									//kemudian jika user memencet suatu tombol, 
									//maka program akan berlanjut ke fungsi transaksi dengan parameter pointer dari variabel k(kPtr)
									//dan dilakukan pendefinisian b=1 agar while-loop dapat berhenti
									int* kPtr=&k;
									puts("\nSELAMAT, LOGIN BERHASIL!!!\n");
									// here lies system("pause");
									transaksi(kPtr);
									b=1;
									break;
								}
						}
								
						else{
							//dilakukan pengecekan untuk nilai k 1 sampai dengan 18
							
								if((strcmp(IDhold, datauser[k].ID) == 0) && (PINhold==datauser[k].PIN)){
									//jika ID inputan user (IDhold) dan PIN inputan user (PINhold) SESUAI dengan data structure
									//maka program akan memunculkan pemberitahuan bahwa berhasil 
									//dan kemudian  layar/stdout akan di-pause 
									
									//kemudian jika user memencet suatu tombol, 
									//maka program akan berlanjut ke fungsi transaksi dengan parameter pointer dari variabel k(kPtr)
									//dan dilakukan pendefinisian b=1 agar while-loop dapat berhenti
									int* kPtr=&k;
									puts("\nSELAMAT, LOGIN BERHASIL!!!\n");
									// here lies system("pause");							
									transaksi(kPtr);
									b=1;								
									break;
								}									
						}
					}				
				}
			}	
		break;//break case 1
			

			
		//jika user menginput atau memasukkan 2, akan dimasukkan ke case pendaftaran akun
		case 2:
			headerLoginRegistrasi(0,1);//fungsi untuk mencetak judul atau header laman registrasi
			if(ig==20){
				//jika nilai counter ig sudah mencapai 20
				//yang di mana seluruh dari arrah user sudah terisi penuh (array ke-19 terisi)
				//maka program akan mencetak pemberitahuan bahwa akun yang terdaftar sudah maksimal
				//dan meminta untuk user memulai ulang program di fungsi selamatDatang
				//pada bagian ini juga diberi // here lies system("pause") agar user dapat membaca instruksi terlebih dahulu
		
				puts("Maaf, jumlah akun yang terdaftar sudah maksimal");
				puts("Silakan memulai ulang program...\n");
				// here lies system("pause");
				selamatDatang();
				break;		
			}
			
			else{
                //jika nilai counter ig BELUM mencapai 20 (maksimal 19)
				//maka program akan berlanjut ke tahapan registrasi akun
			regisID();//melakukan scan dan pengisian untuk ID array structure data user ke-ig
			if (feof(stdin)){
				//jika user menginput EOF, maka program akan kembali ke fungsi selamatDatang()
						selamatDatang();
						break;
							}
			datauser[ig].PIN=scannerPIN();//merupakan bagian pendefisian nilai PIN data user ke-ig 
										  //dengan menggunakan fungsi scannerPIN
			printf("NAMA\t: ");
			getchar();//untuk me-refresh buffer yang ditinggalkan oleh scanf ( \n atau enter )
			// gets(datauser[ig].NAMA);
            scanf("%[^\n]%*c", datauser[ig].NAMA);
			
			//meminta apakah user/nasabah ingin men-deposit saldo pertamanya
			puts("\nApakah anda ingin menyetor saldo pertama Anda ?");
			puts("Tekan 1 untuk Ya");
			puts("Tekan 0 untuk Tidak\n");
		
			g=scannerBasic(0,1);//pendefinisian nilai variabel g dengan menggunakan fungsi scannerBasic
				if(g==1){
					//jika user memilih Ya atau nilai g bernilai 1
					//maka program akan meminta jumlah deposit saldo pertamanya
					printf("\nMasukkan jumlah saldo untuk disetor : Rp ");
					sld=scannerFloat(0);//pendefinisian nilai variabel sld dengan menggunakan fungsi scannerFloat
					datauser[ig].SALDO=sld;//pendefinisian nilai SALDO dari structure data user ke-ig oleh sld
				}
				else if(g==0){
					//jika user memilih Tidak atau nilai g bernilai 0
					//maka program akan mendefinisikan nilai atau saldo awal/SALDO structure data user ke-ig adalah 0
					datauser[ig].SALDO=0;					
				}
				
			ig++;//tiap registrasi yang berhasil, akan dilakukan penambahan(increment) nilai variabel ig dengan 1
			
			//mencetak atau memberi tahu user jika registrasi berhasil dan mem-pause layar sementara 
			puts("\nSELAMAT, REGISTRASI ANDA BERHASIL !\n");
			// here lies system("pause");
			
			//jika user memencet sebuah tombol, maka program akan kembali ke menu utama (fungsi selamatDatang)
			selamatDatang();		
			break;//break case2
			}
			
		//jika user menginput selain 1 atau 2
		//maka program akan mencetak kata terima kasih & kemudian program berhenti			
		default: 
			puts("\nTERIMA KASIH TELAH MENGGUNAKAN BANK VIRTUAL AAROLEASIA\n");
			// here lies system("pause");
			break;		//break default
	}	
}

//fungsi transaksi dengan parameter pointer kPtr
void transaksi(int* kPtr){
	int a,h=0,i=0;
	int holder[20];
	int tr;
	float tarik,setor,transfer;
	int hitungrekening,pilihan;
	char pembanding[1]={};//deklarasi variabel string kosong sebagai pembanding nantinya
	
	do{//mulai atau titik mula do-while loop ( akan terus berulang selama nilai a=1)
		// here lies system("cls");//membersihkan layar
		headerTransaksi(kPtr);	//mencetak header dari laman transaksi dengan parameter pointer kPtr
		
		a=0;//pendefinisian nilai a dengan 0 
		
		//membaca input user ,eksekusi program tergantung dari input user
		//input user diambil menggunakan fungsi scannerBasic berparameter 1 dan 4
		switch(scannerBasic(1,4)){
			case 1:
				//jika nilai dari input yang sudah diproses oleh scannerBasic adalah 1
				//maka program akan menampilkan saldo dari user ke-k (nilai k yang ada di fungsi loginregister sebelumnya)
				printf("\nSaldo Anda adalah :");
				printf("Rp %.2f\n",datauser[*kPtr].SALDO);
				break;//pengecekan saldo selesai, break case 1
		
			case 2:
				//jika nilai dari input yang sudah diproses oleh scannerBasic adalah 2
				//maka program akan meminta lagi inputan mengenai jumlah saldo yang ingin ditarik
				printf("\nMasukkan jumlah saldo yang ingin Anda tarik : Rp ");
				tarik=scannerFloat(0);//pendefinisian nilai variabel tarik dengan fungsi scannerFloat
					if(datauser[*kPtr].SALDO>=tarik){
						//jika SALDO user ke-k LEBIH BESAR ATAU SAMA DENGAN dari jumlah variabel tarik (saldo yg ingin ditarik user)
						//maka akan dilakukan pengurangan SALDO user ke-k dengan nilai variabel tarik
						//dan kemudian akan mencetak sisa SALDO dari user ke-k
						datauser[*kPtr].SALDO=datauser[*kPtr].SALDO-tarik;
						printf("\nSisa saldo Anda sekarang adalah :");
						printf("Rp %.2f\n",datauser[*kPtr].SALDO);//mencetak nominal saldo user ke-k dengan 2 angka di belakang koma 
						}	
					else{
						//jika SALDO user ke-k LEBIH KECIL dari nilai variabel tarik ( saldo yg ingin ditarik user)
						//maka program akan mencetak pemberitahuan bahwa saldo dari user ke-k tidak cukup
						puts("Maaf, saldo anda tidak cukup");
						}
				break;//transaksi penarikan saldo selesai, break case 2
	
			case 3:
				//jika nilai dari input yang sudah diproses oleh scannerBasic adalah 3
				//maka program akan meminta lagi inputan mengenai jumlah saldo yang ingin ditarik
				printf("\nMasukkan jumlah saldo yang ingin Anda setor : Rp ");
				setor=scannerFloat(0);//pendefinisian nilai variabel setor dengan fungsi scannerFloat
				//SALDO dari user ke-k akan ditambahkan dengan nilai variabel setor 
				//dan kemudian akan mencetak jumlah SALDO dari user ke-k setelahnya	
				datauser[*kPtr].SALDO=datauser[*kPtr].SALDO+setor;			
				printf("Jumlah saldo anda sekarang adalah :");
				printf("Rp %.2f\n",datauser[*kPtr].SALDO);	
				break;//break case 3

			case 4:
				// here lies system("cls");//membersihkan stdout atau layar user untuk diberi header DAFTAR REKENING & prosesnyaa
				puts("------------------------------------------------------------------------------------------------------------------------\n");
				printf("                                === DAFTAR REKENING BANK VIRTUAL AAROLEASIA ===\n");
				puts("\n------------------------------------------------------------------------------------------------------------------------\n");
				
				//bagian pencetakan NOMOR AKUN dan NAMA NASABAH yang telah terdaftar/ter-registrasi sebelumnya
				//pengecekan dilakukan dengan cara membandingkan value ID yang ada di dalam array structure data 
				//dengan array 'pembanding' yang tidak memiliki anggota
				printf("NOMOR AKUN\t\tNAMA NASABAH\n");
				
				//program akan memasuki for-loop dengan parameter hitungrekening yang nilai inisisinya adalah 0
				//yang di-increment-kan dengan 1 dan akan berjalan selama nilainya kurang dari 20 ( sampai 19 [array datauser maksimal])
					for(hitungrekening=0 ; hitungrekening<20; hitungrekening++){
						if(strcmp(datauser[hitungrekening].ID,pembanding) != 0){
						//jika nilai atau value dari ID user ke-hitungrekening TIDAK SAMA dengan variabel 'pembanding'
						//maka program akan mencetak nilai dari variabel 'hitungrekening' 
						//dan juga akan mencetak nilai/string NAMA dari user ke-hitungrekening 
						//kedua variabel yang tercetak akan dipisahkan dengan 3 tab dan di akhiri dengan newline
						printf("%d\t\t\t%s\n",hitungrekening,datauser[hitungrekening].NAMA);
						
						//setiap value hitungrekening yang memenuhi syarat akan disimpan dalam array holder ke-h
						holder[h]=hitungrekening;					
						h++;//increment nilai h dengan 1 akan anggota tidak tertumpuk
						}
					}	
					
				//setelah for-loop selesai, program akan meminta user untuk memilih nomor akun mana yang ingin ditransfer
				puts("\nMasukkan Nomor Akun yang ingin Anda transfer (0--19)");
				
				do{//mulai atau titik mula do-while loop ( akan terus berulang selama nilai a=0)
						pilihan=scannerBasic(0,19);//pendefinisian nilai pilihan dengan fungsi scannerBasic
					if (feof(stdin)){
						//jika inputan user(pilihan) di stdin dari scannerBasic merupakan EOF
						//maka program akan kembali ke Menu Utama
						selamatDatang();
						return;
							}
					else if(pilihan==*kPtr){
						//jika nilai pilihan sama dengan nilai k ( nomor akun user yang sama )
						//maka program akan mencetak pemberitahuan
						puts("Anda tidak dapat mentransfer ke diri anda sendiri. Silakan coba lagi");
						puts("Atau masukkan EOF untuk kembali ke menu utama\n");
					}
					else {
						//jika nilai inputan user bukan EOF ataupun nilai k pada saat itu
						//maka program akan dimasukkan ke dalam for-loop lagi 
						for(i=0; i<=20; i++){
							if(pilihan==holder[i]){
								//jika nilai pilihan sama dengan nilai array holder index ke-i
								//maka akan dilakukan pendefinisian a=1 dan break sehingga do-while loop akan berhenti
								a=1;
								break;//break dowhile
							}
							else if(i==20){
								//jika nilai i sudah mencapai 20 ( maksimal )
								//dan jika nilai pilihan TIDAK ADA yang sama dengan nilai array holder index ke-i 
								//yang selalu bertambah dari 0 sampai dengan 19 ( 20 tidak mungkin sama karena index datauser dari holder ke-i maksimal 19 ) 
								//maka program akan mencetak pemberitahuan bahwa salah
								puts("Nomor Akun yang anda masukkan tidak terdaftar. Silakan coba lagi");
								puts("Atau masukkan EOF untuk kembali ke menu utama\n");
							}
							
						}
					}
					
				}while(a==0);//program berhenti jika nilai a tidak 0 lagi
				
				//program akan meminta jumlah saldo yang ingin ditransfer dari user ke-k kepada user ke-pilihan
				printf("\nMasukkan Jumlah Saldo yang ingin ditransfer : Rp ");
	
				transfer=scannerFloat(0);//pendefinisian nilai transfer dengan fungsi scannerFloat
					if(datauser[*kPtr].SALDO>=transfer){
						//jika SALDO user ke-k LEBIH BESAR ATAU SAMA DENGAN dari jumlah variabel transfer (saldo yg ingin ditransfer user)
						//maka akan dilakukan pengurangan SALDO user ke-k dengan nilai variabel transfer
						//kemudian akan dilakukan penambahan SALDO user ke-pilihan dengan nilai variabel transfer
						//dan kemudian akan mencetak sisa SALDO dari user ke-k
						datauser[*kPtr].SALDO=datauser[*kPtr].SALDO-transfer;
						datauser[pilihan].SALDO=datauser[pilihan].SALDO+transfer;
						printf("\nSisa saldo anda sekarang adalah :");
						printf("Rp %.2f\n",datauser[*kPtr].SALDO);
						}
							
					else{
						//jika SALDO user ke-k KURANG DARI dari jumlah variabel tarik (saldo yg ingin ditarik user)
						//maka akan muncul pemberitahuan saldo tidak cukup
						puts("Maaf, saldo anda tidak cukup");
						}			
				break;//break case 4
			
			default :
				break;//break default
		}//switch-case selesai
		
	//program menanyakan user apakah user ingin melakukan transaksi ulang
	puts("\nApakah anda ingin melakukan transaksi lagi ?");
	puts("Tekan 1 untuk melakukan transaksi ulang\nTekan 0 untuk kembali ke Menu Utama\n");
	a=scannerBasic(0,1);//pendefinisian nilai a dengan fungsi scannerBasic
	puts("");
	} while(a==1);//jika inputan user atau nilai a tidak sama dengan 1 (0), maka do-while loop akan berhenti
	//kembali ke fungsi selamatDatang

	return selamatDatang();
}
////////////////////////////////////////////////////////HEADERKW//////////////////////////////////////////////////////HEADERKW////////////////////////////////////////////////////////

//merupakan fungsi berparameter integer login dan regis untuk mencetak antara header/instruksi dari laman login atau registrasi
void headerLoginRegistrasi(int login, int regis){
	// here lies system("cls");//membersihkan layar stdout dan mengganti dengan headaer login/registrasi
	if(login==1){
		//jika parameter login bernilai 1, maka akan mencetak header login
				puts("\n------------------------------------------------------------------------------------------------------------------------\n");
				puts("\t\t\t\t\t     == HALAMAN LOGIN ==");
				puts("\n------------------------------------------------------------------------------------------------------------------------\n");
		
	}
	else if(regis==1){
		//jika parameter regis bernilai 1, maka akan mencetak header registrasi
			puts("\n------------------------------------------------------------------------------------------------------------------------\n");
			puts("\t\t\t\t\t     == HALAMAN REGISTRASI ==");
			puts("\n------------------------------------------------------------------------------------------------------------------------\n");
	}
				//mencetak instruksi untuk user
				printf("\n%s\n%s\n%s\n\n",
						"**Masukkan maksimal 20 karakter/huruf tanpa spasi untuk ID",
						"**Masukkan sebanyak 6 digit bilangan bulat positif untuk PIN",
						"**Masukkan maksimal 50 karakter/huruf untuk NAMA");
}

//merupakan fungsi berparameter pointer kPtr untuk mencetak header transaksi
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

////////////////////////////////////////////////////////SCANNER////////////////////////////////////////////////////////SCANNER////////////////////////////////////////////////////////SCANNER

//merupakan fungsi berparameter float x yang berfungsi untuk mengecek apakah inputan user valid atau tidak (UNTUK SALDO)
float scannerFloat(float x){
	float tr;//pendeklarasian float tr sebagai holder sementara
	
	while(1){//inisiasi while-loop selama kondisi true (akan selalu berulang)
		if(scanf("%f%*c",&tr)){
			//program akan meminta input dari user dalam float dan akan disimpan dalam variabel tr
			//selama inputan user tidak terdiri dari character, kondisi terpenuhi
			if(tr<=x){
				//jika nilai variabel tr LEBIH KECIL ATAU SAMA DENGAN dari parameter x, user akan diminta untuk menginput ulang
				printf("Masukan Anda tidak valid! Silakan coba lagi\n\n");
		 		printf("\nMasukkan Jumlah Saldo : Rp ");
		
			}
			else{
				//jika nilai variabel tr LEBIH dari parameter x, fungsi akan me-return value dari variabel tr 
				//(fungsi scannerFloat yang dipanggil saat itu akan bernilai tr) 
				return tr;
			}
		}
		else{
			//jika input user terdiri dari character, user akan diminta untuk menginput ulang 
			//(kembali ke inisiasi while-loop)
			printf("Masukan Anda tidak valid! Silakan coba lagi\n\n");
			printf("\nMasukkan Jumlah Saldo : Rp ");
			scanf("%*c");
		}
	}

}

//merupakan fungsi berparameter x dan y yang berfungsi untuk mengecek apakah inputan user valid atau tidak (UNTUK PILIHAN")
int scannerBasic(int x, int y){
	int tr;//pendeklarasian integer tr sebagai holder sementara
	
	printf("PILIHAN ANDA : ");
	
	while(1){//inisiasi dari while-loop selama kondisi true (akan selalu berulang)
		if(scanf("%d%*c",&tr)){
			//program akan meminta input dari user dalam integer dan akan disimpan dalam variabel tr
			//selama inputan user tidak terdiri dari character, kondisi terpenuhi
			if(tr<x || tr>y){
				//jika nilai tr LEBIH KECIL dari parameter x ATAU LEBIH BESAR dari parameter y
				//maka user akan diminta untuk menginput ulang (kembali ke while-loop)
				printf("Masukan Anda tidak valid! Silakan coba lagi\n\n");
				printf("PILIHAN ANDA : ");	
			}
			else{
				//jika tr bernilai x atau y atau berada di antara x dan y
				//maka fungsi akan me-return value dari tr 
				//(fungsi scannerBasic yang dipanggilsaat itu akan bernilai tr)
				return tr;
			}
		}
		else{
			//jika input user terdiri dari character, user akan diminta untuk menginput ulang 
			//(kembali ke inisiasi while-loop)
			printf("Masukan Anda tidak valid! Silakan coba lagi\n\n");
			printf("PILIHAN ANDA : ");	
			scanf("%*c");
		}
	}
	
}

//merupakan fungsi yang berfungsi untuk mendapatkan input dan mengecek input dari user agar user tepat mengisi 6 digit dan bukan character(PIN)
int scannerPIN(){
	int pilihan,holder,counter;//inisiasi variabel integer
	printf("PIN\t: ");
	
	while(1){	//inisiasi dari while-loop selama kondisi true (akan selalu berulang)
		if(scanf("%*c%d",&pilihan)){
			//program akan meminta input dari user dalam integer dan akan disimpan dalam variabel tr
			//selama inputan user tidak terdiri dari character, kondisi terpenuhi	
			if(pilihan>=0){
				//JIKA inputan user positif ( lebih dari nol )
				//maka kondisi ini terpenuhi dan program akan berlanjut
				
				//merupakan bagian penghitungan jumlah digit dari angka yang diinput oleh user
				counter=0;//pendefinisian & pe-resetan variabel counter menjadi 0
				holder=pilihan;//pendefinisian variabel holder dengan variabel pilihan 
								//hal ini bertujuan untuk menyimpan sementara nilai dari variabel pilihan yang diinput user
								//karena setelah ini, akan dilakukan pengubahan/operasi dari nilai variabel pilihan
								
				while(pilihan!=0){//insiasi dari while-loop 
								  //while-loop ini akan terus berulang selama nilai variabel pilihan tidak sama dengan 0
								  //variabel pilihan pasti akan menjadi 0 karena akan terus dibagi dengan 10 hingga hasilnya ~0 dan dibulatkan 0
				
					//pengoperasian untuk menghitung jumlah digit dari inputan variabel pilihan, yaitu dengan dibagi dengan 10
					//dan setiap perulangan atau pembagian dengan 10, variabel counter akan bertambah 1 ( increment )
					pilihan=pilihan/10;
					counter++;
				}
				//while-loop berhenti ketika nilai pilihan menjadi 0
				
				//kemudian, dilakukan pendefinisian ulang nilai variabel pilihan dengan nilai variabel holder
				//yang sebelumnya sudah diisi dengan nilai variabel pilihan awal
				pilihan=holder;
		
				if(counter!=6){
					//jika jumlah digit inputan user ( nilai dari counter ) TIDAK SAMA DENGAN 6
					//maka user akan diminta untuk menginput ulang (kembali ke while-loop)
					printf("Masukkan PIN tepat 6 digit ! \n\n");
					printf("PIN : ");
				}
				else {
					//jika jumlah digit inputan user ( nilai dari counter ) SAMA DENGAN 6
					//maka fungsi akan me-return value atau nilai dari variabel pilihan
					return pilihan;
				}
			}
			else{
				//jika nilai inputan variabel pilihan negatif atau melebihi jangkaauan tipe data integer
				//maka user akan diminta untuk menginput ulang (kembali ke while-loop)
				puts("Masukkan input-an yang valid !\n");
				printf("PIN : ");
			}
			
		}
		
		else{
			//jika input user terdiri dari character, user akan diminta untuk menginput ulang 
			//(kembali ke inisiasi while-loop)
			printf("Input-an tidak valid !\n\n");
			scanf("%*c");
		
			printf("PIN : ");
		}
	}
}

//merupakan fungsi yang berfungsi untuk melakukan registrasi ID user 
void regisID(){
		char testid[20];//deklarasi array char (string) beranggotakan 20 elemen 
		int k=0,x=0;//deklarasi 2 buah variabel counter bertipe data integer dan nilai inisiasi 0
		// here lies system("cls");//men-clear atau membersihkan layar 
		headerLoginRegistrasi(0,1);//memanggil fungsi headerLoginRegistrasi 
		
		//meminta user untuk menginput ID yang ingin dibuat/didaftarkan ( kemudian disimpan sementara dalam variabel testid
		printf("ID\t: ");
		scanf("%s",&testid);
		
		//dilakukan pengecekan apakah ID yang diinput user sudah terdaftar atau belum 
		//(yaitu dengan membandingkan SEMUA ID structure datauser (array indeks ke-0--19)
		// dengan array inputan user (testid) menggunakan statement strcmp(string compare)
		//string compare merupakan sebuah syntax/statement yang berfungsi untuk membandingkan 2 buah string
		//yang akan me-return 0 jika nilai kedua string yang dibandingkan SAMA
		
		//Jadi, apabila ID dari structur datauser ke-k SAMA DENGAN inputan user sebagai testid
		//maka akan muncul notif
			for(k; k<20; k++){//for-loop k 
				if(strcmp(datauser[k].ID,testid) == 0)
					{
					//Jika value dari ID datauser ke-k SAMA DENGAN value dari value inputan user (testid)
					//maka program akan memberi pemberitahuan bahwa ID sudah ada, dan mem-pause layar
					//setelah user menginput nilai apa pun (// here lies system pause)
					//maka fungsi akan memanggil dirinya kembali ( regisID ) sehingga user diminta untuk menginput lagi
					//kemudian program meminta antara user untuk mencoba ID lain atau menginput EOF untuk kembali ke menu utama
					printf("ID sudah terpakai, masukkan ID lain\n");
					puts("Atau masukkan EOF untuk kembali ke MENU UTAMA\n");
					// here lies system("pause");
					return regisID();
					}
				}
			
			//pengisian ID dari array data user ke-ig (pengisian array dilakukan dengan mengisi elemen/indeks array-nya satu per satu)
			for(x; x<20; x++){
				datauser[ig].ID[x]=testid[x];
				}
}
////////////////////////////////////////////////////////SCANNER////////////////////////////////////////////////////////SCANNER////////////////////////////////////////////////////////SCANNER