#include <stdio.h>              // print, scan, etc
#include <stdlib.h>             // atoi()
#include <string.h>             // strtok()
#define intLimit 2147483647
#define strLimit 100

/*
 * intScan(int batasAtas, int batasBawah)
 * 
 * Metode yang digunakan untuk memvalidasi 
 * masukan int berdasarkan batasan dan jenis 
 * lain (selain int) yang mungkin dimasukkan pengguna
 */
int intScan(int ceiling, int floor){
    int buffer;
    while(1){
        if(scanf("%d%*c", &buffer)){
            if(buffer < floor){
                printf("Masukan terlalu rendah! Coba lagi: ");
            } else if(buffer > ceiling){
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

/*
 * Struct yang digunakan untuk menyimpan informasi 
 * setiap barang yang dimasukkan oleh pengguna     
 */
typedef struct {
    char kind[strLimit];
    char itemName[strLimit];
    int amount;
    int price;
    int idNumber;
} Item;

/*
 * Enumeration yang digunakan untuk mendefinisikan kode 
 * operasi untuk mempermudah pemahaman dan penulisan kode
 */
enum Operation {
    eBarang_input = 1,
    eBarang_detail,
    eBarang_modif,
    eBarang_mutate,
    eDefType
} operation;

/*
 * itemScan(Item *anggota_array_item)
 * 
 * Metode yang digunakan untuk memberikan
 * masukan kepada Item array, dibuat karena
 * ada >1 instansi masukan dalam program
 */
void itemScan(Item *item) {
    printf("Masukkan jenis barang: ");
    scanf("%[^\n]%*c", item->kind);
    printf("Masukkan nama barang: ");
    scanf("%[^\n]%*c", item->itemName);
    printf("Masukkan jumlah barang tersedia: ");
    item->amount = intScan(intLimit, 0);
    printf("Masukkan harga satuan barang (ribuan rupiah): ");
    item->price = intScan(intLimit, 0);
    printf("Masukkan nomor pengenal: ");
    item->idNumber = intScan(intLimit, 0);
}

int main() {
    int opDone = 0,
        itemFillLevel = 0;
    Item item[100];

    printf("Selamat datang di sistem inventarisasi Stackofsugar\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    while(!opDone){
        int opcode, accepting = 1;
        printf("***************************************\n");
        printf("List nama barang yang tersedia di toko:\n");
        if(itemFillLevel == 0){
            printf("      ..Gudang masih kosong!..\n");
        }
        else {
            for(int i = 0; i < itemFillLevel; i++){
                printf("%d. %s\n",(i + 1), item[i].itemName);
            }
        }

        printf("\n== Operasi apa yang anda inginkan? ==\n");
        printf("1. Masukkan barang \n2. Tampilkan detail barang \n3. Modifikasi barang \n4. Mutasi (keluar-masuk) barang \n5. Keluar \n> ");
        opcode = intScan(5,1);

        switch(opcode){
            case eBarang_input:
                accepting = 1;
                printf("== Instansi Input Barang ==\n");
                if(itemFillLevel > 99){
                    printf("Maaf, gudang sudah penuh!");
                }
                else {
                    while(accepting){
                        printf("Masukkan data barang ke %d:\n", (itemFillLevel + 1));
                        itemScan(&item[itemFillLevel]);
                        itemFillLevel++;
                        printf("Apakah anda ingin memasukkan barang lagi? (1/0) \n> ");
                        accepting = intScan(1, 0);
                    }
                }
                break;
            case eBarang_detail:
                accepting = 1;
                while(accepting){
                    printf("Masukkan nomor urut barang yang ingin anda lihat detailnya (0 untuk kembali): ");
                    int choice = intScan(itemFillLevel, 0);
                    if(choice == 0){
                        accepting = 0;
                    }
                    else {
                        choice--;
                        printf("Data barang ke %d:\n", (choice + 1));
                        printf("Jenis barang: %s\n", item[choice].kind);
                        printf("Nama barang: %s\n", item[choice].itemName);
                        printf("Jumlah stok: %d\n", item[choice].amount);
                        printf("Harga satuan: Rp %d000\n", item[choice].price);
                        printf("Nomor pengenal: %d\n", item[choice].idNumber);
                    }
                }
                break;
            case eBarang_modif:
                accepting = 1;
                while(accepting){
                    printf("Masukkan nomor urut barang yang ingin anda modifikasi nilainya (0 untuk kembali): ");
                    int choice = intScan((itemFillLevel + 1),0);
                    if(choice == 0){
                        accepting = 0;
                    }
                    else {
                        choice--;
                        printf("Tool modifikasi barang ke %d:\n", (choice + 1));
                        itemScan(&item[choice]);
                        printf("Apakah anda ingin memodifikasi nilai barang lagi? (0/1) \n> ");
                        accepting = intScan(1,0);
                    }
                }
                break;
            case eBarang_mutate:
            {
                char mutasi[10];
                char *token;
                int parse[3], buffer;
                accepting = 1;
                while(accepting){
                    printf("Format: ([No.Urut. Barang] <spasi> 1(masuk)/0(keluar) <spasi> [Jumlah]\n");
                    printf("Masukkan kode operasi sesuai format: ");
                    scanf("%[^\n]%*c", mutasi);
                    // Parsing no.urut. barang input
                    token = strtok(mutasi, " ");
                    for(int i = 0; i < 3; i++){
                        const char *buffer = token;
                        parse[i] = atoi(buffer);
                        // parse[0] = no.urut, parse[1] = 1/0, parse[2] = jumlah
                        token = strtok(NULL, " ");
                    }
                    // Penjaringan error
                    if(parse[0] < 1 || parse[0] > itemFillLevel){
                        printf("Nomor urut tidak terdefinisi/salah!\n");
                    }
                    else if(parse[1] < 0 || parse[1] > 1){
                        printf("Argumen 2 yang diperbolehkan adalah 1(masuk)/0(keluar)!\n");
                    }
                    else {
                        // Pengubahan jumlah
                        buffer = item[parse[0]-1].amount;
                        if(parse[1] == 0){
                            if(item[parse[0]-1].amount < parse[2]){
                                printf("Barang di gudang lebih sedikit dari permintaan!\n");
                            }
                            else {
                                item[parse[0]-1].amount -= parse[2];
                            }
                        }
                        else if(parse[1] == 1){
                            item[parse[0]-1].amount += parse[2];
                        }
                        else {
                            printf("Ada kesalahan! \nCoba lagi? (1/0) \n> ");
                            accepting = intScan(1,0);
                        }
                        printf("Stok %s diperbarui dari %d menjadi %d\n", item[parse[0]-1].itemName, buffer, item[parse[0]-1].amount);
                    }
                    printf("Apakah anda ingin melakukan mutasi lagi? (1/0) \n> ");
                    accepting = intScan(1,0);
                }
                break;
            }
            default:
                opDone = 1;
        }
    }
}