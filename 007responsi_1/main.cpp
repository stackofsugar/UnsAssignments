#include <stdio.h>

typedef struct {
    char nama[100];
    int ISBN;
} Book;

typedef struct {

} Backpack;

typedef union {
    Book book;
    Backpack backpack;
} Shop;

void masukkanBuku(Book &x){
    printf("Masukkan judul buku: ");
    scanf("%s", x.nama);
    printf("Masukkan angka ISBN: ");
    scanf("%d", &x.ISBN);
    printf("\n");
}

void printBuku(Book &x){
    printf("Judul: %s\n", x.nama);
    printf("ISBN: %d\n", x.ISBN);
}

int main() {
    // int tas, buku;
    // printf("Masukkan jumlah buku yang ingin anda input: ");
    // scanf("%d", &buku); // -> buku = 2
    // printf("\nMasukkan jumlah tas yang ingin anda input: ");
    // scanf("%d", &tas);  // -> tas = 2
    // printf("\n");

    Shop buku1, buku2;
    printf("Input Buku\n");
    masukkanBuku(buku1.book);
    masukkanBuku(buku2.book);
    printBuku(buku1.book);
    printBuku(buku2.book);
}