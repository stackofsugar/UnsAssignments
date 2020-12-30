# FileCompare
## Tugas Individu KP 2020 Semester I

### 1. Cara Compile
Building dari project ini dibangun diatas build system [CMake](https://cmake.org/). Cara compile/build project yang paling disarankan adalah menggunakan CMake.

1. Menggunakan CMake
	- Membuat sebuah direktori build/ yang berada dalam root project (misal /10tgs_ak/build/) dengan `mkdir build` atau `md build`.
	- Memindahkan cwd ke direktori tersebut menggunakan `cd build`.
	- Memulai building project dengan menuliskan `cmake ..`.
	- Hasil build (executable) akan berada di `../build`.
	- Beberapa kasus membutuhkan spesifikasi tertentu, semisal pen.definisian kit dan compiler secara spesifik.
2. Menggunakan gcc Command Line
	- Step 1 dan 2 pada poin 1 di atas.
	- Memulai building dengan mengetikkan `gcc ../src/*.c`.
	- Hasil build (executable) akan berada di `../build`.
3. Menggunakan IDE
	- IDE dan architecture specific, sehingga tidak bisa dituliskan.


### 2. Fitur Program
1. Membandingkan 2 data
	- Program dapat membandingkan 2 data yang didefinisikan oleh pengguna, dengan ekstensi apapun.
	- Program menyeleksi baris-demi-baris akan adanya kesamaan.
	- Program dibatasi untuk membaca direktori `contoh_textfile/` saja, sehingga filesystem menjadi sangat rapih.
	- Program memiliki error-handling yang cukup ekstensif.
2. Mengolah data perbandingan 2 data
	- Program memasukkan semua bandingan data ke dalam sebuah Linked List.
	- Program menawarkan pilihan untuk melihat data, serta menghapus, mengganti, dan menambahkan sebuah instance data pada Linked List.
	- Program memiliki error-handling yang ekstensif sehingga keraguan tentang error dapat diminimalisir,
3. Mengekspor hasil olahan data ke dalam text file
	- Program dapat mengekspor data ke dalam text file.
	- Program menawarkan kemudahan seperti nama file yang dapat dicustom oleh pengguna dan beberapa error-handling. 
	- Selain itu, formatting dari teks yang diekspor diperhatikan kerapihannya.


### 3. Screenshot Runtime Program

Dapatkan sampel STDOUT dan STDIN [di sini](https://pastebin.com/ij0efmuz)

![1](https://cdn.discordapp.com/attachments/758566679289790464/789557533794107477/unknown.png)

![2](https://cdn.discordapp.com/attachments/758566679289790464/789557581730283570/unknown.png)

![3](https://cdn.discordapp.com/attachments/758566679289790464/789557630129012736/unknown.png)

![4](https://cdn.discordapp.com/attachments/758566679289790464/789557682154504212/unknown.png)

![5](https://cdn.discordapp.com/attachments/758566679289790464/789557904809394226/unknown.png)

