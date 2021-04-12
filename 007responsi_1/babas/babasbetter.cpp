#include <stdio.h>
#define intLimit 2147483647
#define ulongLimit 4294967295

int intMasuk(int batasAtas, int batasBawah) { // supaya batasan dan jenis masukan tervalidasi
    int buffer;
    while(1){
        if(scanf("%d", &buffer)){
            if(buffer < batasBawah){
                printf("Masukan terlalu rendah! Coba lagi: ");
            } else if(buffer > batasAtas){
                printf("Masukan terlalu tinggi! Coba lagi: ");
            } else {
                return buffer;
            }
        }
        else {
            printf("Masukan tidak valid! Coba lagi: ");
            scanf("%*c");
        }
    }
}

enum Bayar {
    eTunai = 1, eMember
} bayar;

typedef struct {
    char nama[8][10];
    unsigned int harga[8];
    int jumlahBeli[8];
} Barang;

typedef struct {
    char nama[4][8];
    char desc[4][27];
    unsigned int harga[4];
    int jumlahBeli[4];
} Promo;

int main() {
    int pilihan, pilihanHemat, lagi = 1, lagiPromo = 1, caraBayar, berhasilBayar = 0, mauNota, /*tambahLagi = 0,*/ totalBayar;
    unsigned int totalBelanja = 0;
    Barang barang = {
        {"Wajan", "Saringan", "Panci", "Sabun", "Minyak", "Rinso", "Sendok", "Garpu"},
        {300, 30, 200, 120, 120, 150, 15, 15},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    Promo promo = {
        {"Pahe 1", "Pahe 2", "Pahe 3", "Pahe 4"},
        {"2 Wajan", "3 Panci", "2 Minyak FREE 1 Sabun", "4 Panci FREE 1 wajan"},
        {400, 450, 280, 900},
        {0, 0, 0, 0}
    };
    printf("Selamat datang di toko *basz* \n::DISKON 20%% MEMBER ALL ITEMS::\n");
    printf("Pilih barang yang ingin anda beli:\n");
    for(int i = 0; i < 8; i++){
        printf("%d. %s \t-> Rp %u00\n", i+1, barang.nama[i], barang.harga[i]);
    }
    printf("9. Paket Hemat\n");

    // while(!tambahLagi)
    while(lagi) {
        printf("Pilihan barang anda: ");
        pilihan = intMasuk(9, 1);
        if(pilihan != 9){
            printf("Masukkan jumlah %s yang ingin dibeli: ", barang.nama[pilihan - 1]);
            barang.jumlahBeli[pilihan - 1] = intMasuk(intLimit, 1);
        }
        else {
            printf("Pilih paket hemat yang anda inginkan: \n");
            for(int i = 0; i < 4; i++){
                printf("%d. %s: %s \n    ---> Rp %u00\n", i+1, promo.nama[i], promo.desc[i], promo.harga[i]);
            }
            while(lagiPromo){    
                printf("Pilihan promo anda: ");
                pilihanHemat = intMasuk(4,0);
                printf("Masukkan jumlah %s yang ingin dibeli: ", promo.nama[pilihanHemat - 1]);
                promo.jumlahBeli[pilihanHemat - 1] = intMasuk(intLimit, 1);
                printf("Anda ingin berbelanja promo lagi? (1/0): ");
                lagiPromo = intMasuk(1,0);
            }
        }
        printf("Anda ingin berbelanja barang lagi? (1/0): ");
        lagi = intMasuk(1,0);
    }

    printf("\nx+x+x Anda telah berbelanja x+x+x\n");
    for(int i = 0; i < 8; i++){
        if(barang.jumlahBeli[i]){
            printf("%s \t   %d x Rp %u00 \t   = Rp %u00\n", barang.nama[i], barang.jumlahBeli[i], barang.harga[i], (barang.jumlahBeli[i] * barang.harga[i]));
            totalBelanja += (barang.jumlahBeli[i] * barang.harga[i]);
        }
    }
    for(int i = 0; i < 4; i++){
        if(promo.jumlahBeli[i]){
            printf("%s \t   %d x Rp %u00 \t   = Rp %u00\n", promo.nama[i], promo.jumlahBeli[i], promo.harga[i], (promo.jumlahBeli[i] * promo.harga[i]));
            totalBelanja += (promo.jumlahBeli[i] * promo.harga[i]);
        }
    }
    printf("Anda telah berbelanja \t\t   = Rp %u00\n", totalBelanja);

    printf(".:Pilih metode pembayaran anda:. \n1. Tunai \n2. Kartu member 20%% OFF ALL ITEM!!! \nPilihan pembayaran: ");
    caraBayar = intMasuk(2,1);
    if(caraBayar == eTunai){
        printf("Total yang harus dibayar \t= Rp %u00\n", totalBelanja);
    }
    else if(caraBayar == eMember){
        totalBelanja *= 0.8;
        printf("Total yang harus dibayar \t= Rp %u00\n", totalBelanja);
    }
    while(!berhasilBayar){
        printf("Nominal pembayaran anda \t= Rp ");
        totalBayar = intMasuk(intLimit, 0);
        totalBayar /= 100;
        if(totalBayar < (int)totalBelanja){
            printf("Maaf, jumlah pembayaran anda kurang dari total belanja! Silakan coba lagi.\n");
            printf("Total yang harus dibayar \t= Rp %u00\n", totalBelanja);
        }
        else {
            printf("Kembalian: %u00 \n", (totalBayar - totalBelanja));
            printf("Pembayaran berhasil! Anda ingin mencetak nota? (1/0) \n> ");
            berhasilBayar = 1;
            mauNota = intMasuk(1,0);
            if(!mauNota){
                printf("Terimakasih telah berbelanja, selamat datang kembali!!!\n");
            }
            else{
                printf("Nama Barang \t\t\tQty \t   Harga \tTotal\n");
                for(int i = 0; i < 8; i++){
                    if(barang.jumlahBeli[i]){
                        printf("%s \t\t\t%d \t   Rp %u00 \tRp%u00\n", barang.nama[i], barang.jumlahBeli[i], barang.harga[i], (barang.jumlahBeli[i] * barang.harga[i]));
                    }
                }
                for(int i = 0; i < 4; i++){
                    if(promo.jumlahBeli[i]){
                        printf("%s \t\t\t%d \t   Rp %u00 \tRp%u00\n", promo.nama[i], promo.jumlahBeli[i], promo.harga[i], (promo.jumlahBeli[i] * promo.harga[i]));
                    }
                }
            }
        }
    }
}   