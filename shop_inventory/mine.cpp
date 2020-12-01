#include <stdio.h>
#define strlimit 200
#define shortstr 50

/* 
 * Struct untuk menyimpan data mengenai detail produk buku.
 */
typedef struct {
    char title[strlimit];
    char author[strlimit];
    char publisher[strlimit];
    int pages;
} Book;

/*
 * Struct untuk menyimpan data mengenai detail produk tas.
 */
typedef struct {
    char productName[strlimit];
    char manufacturer[strlimit];
    char material[shortstr];
    char capacity;
} Backpack;

/*
 * Sebuah struct yang berfungsi sebagai wrapper kedua jenis barang, memuat sebuah union
 * yang berfungsi untuk mengurangi jumlah memori yang dipakai program.
 */
typedef struct {
    union {
        Book book;
        Backpack backpack;
    };
    int idnumber;
    double price;
} Shop;


/*
 * shopcpy(&objek_yang_dipakai, tipeOperasi)
 * > tipeOperasi 1 = Instansi buku, 2 = Instansi tas
 * 
 * Sebuah metode yang digunakan untuk memasukkan data mengenai
 * sebuah produk, mengedepankan konsep modular programming.
 */
void shopcpy(Shop *obj, int dataType){
    if (dataType == 1){
        printf("Masukkan judul buku: ");
        scanf("%[^\n]%*c", obj->book.title);
        printf("Masukkan penulis buku: ");
        scanf("%[^\n]%*c", obj->book.author);
        printf("Masukkan percetakan buku: ");
        scanf("%[^\n]%*c", obj->book.publisher);
        printf("Masukkan jumlah halaman: ");
        scanf("%d%*c", &obj->book.pages);
        printf("Masukkan nomor identitas barang: ");
        scanf("%d%*c", &obj->idnumber);
        printf("Masukkan harga barang: ");
        scanf("%lf%*c", &obj->price);
    }
    else {
        printf("Masukkan nama model tas: ");
        scanf("%[^\n]%*c", obj->backpack.productName);
        printf("Masukkan merk tas: ");
        scanf("%[^\n]%*c", obj->backpack.manufacturer);
        printf("Masukkan bahan tas: ");
        scanf("%[^\n]%*c", obj->backpack.material);
        printf("Masukkan kapasitas tas: ");
        scanf("%c", &obj->backpack.capacity);
        printf("Masukkan nomor identitas barang: ");
        scanf("%d%*c", &obj->idnumber);
        printf("Masukkan harga barang: ");
        scanf("%lf%*c", &obj->price);
    }
}

/*
 * shopPrint(&objek_yang_dipakai, tipeOperasi, iterasi_array)
 * > tipeOperasi 1 = Instansi buku, 2 = Instansi tas
 * 
 * Sebuah metode yang digunakan untuk mencetak 
 * nilai-nilai sebuah item dengan deskriptor nya.
 */
void shopPrint(Shop *obj, int dataType){
    if (dataType == 1){
        printf("Judul buku: %s\n", obj->book.title);
        printf("Penulis buku: %s\n", obj->book.author);
        printf("Percetakan buku: %s\n", obj->book.publisher);
        printf("Jumlah halaman buku: %d\n", obj->book.pages);
        printf("Nomor identitas buku: %d\n", obj->idnumber);
        printf("Harga buku: %lf Dolar Amerika Serikat\n", obj->price);
    }
    else {
        printf("Nama model tas: %s\n", obj->backpack.productName);
        printf("Merk tas: %s\n", obj->backpack.manufacturer);
        printf("Bahan tas: %s\n", obj->backpack.material);
        printf("Kapasitas tas: %c\n", obj->backpack.capacity);
        printf("Nomor identitas buku: %d\n", obj->idnumber);
        printf("Harga buku: %lf Dolar Amerika Serikat\n", obj->price);
    }
}

int main() {
    int book, backpack;                         // Inisialisasi batasan array

    printf("=== Selamat Datang di Sistem Inventorisasi PojokBuku.co ===");

    printf("\nBerapa item buku yang ingin anda masukkan ke sistem? \n> ");
    scanf("%d", &book);                         // Definisi batasan array 1
    printf("Berapa item tas yang ingin anda masukkan ke sistem? \n> ");
    scanf("%d%*c", &backpack);                  // Definisi batasan array 2

    Shop Book[book], Backpack[backpack];        // Inisialisasi array beserta batasan"nya

    /*
     * Sebuah seri loop yang berfungsi untuk memasukkan dan 
     * mencetak data ke dalam array struct yang telah diinisialisasi.
     */

    printf("\n.: Book input section :.\n");
    for (int i = 0; i < book; i++){
        printf("Input buku ke %d\n", (i+1));
        shopcpy(&Book[i], 1);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    }
    printf("\n.: Backpack input section :.\n");
    for (int i = 0; i < backpack; i++){
        printf("Input tas ke %d\n", (i+1));
        shopcpy(&Backpack[i], 0);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    }

    printf(".: Book output section :.\n");
    for (int i = 0; i < book; i++){
        printf("Data buku ke %d: \n", (i+1));
        shopPrint(&Book[i], 1);
        printf("====================================\n");
    }
    printf(".: Backpack output section :.\n");
    for (int i = 0; i < backpack; i++){
        printf("Data buku ke %d: \n", (i+1));
        shopPrint(&Backpack[i], 0);
        printf("====================================\n");
    }
}