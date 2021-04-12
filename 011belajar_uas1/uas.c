// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdarg.h>
// #define sqr(i) i*i

// // void func(int n, ...) {
// //     int number, i = 0;
// //     int stopper = 3;
// //     va_list start;
// //     va_start(start, n);

// //     while (i != stopper) {
// //         number = va_arg(start, int);
// //         i++;
// //     }

// //     printf("%d", number);
// // }

// int main() {
//     // char str[5];
//     // FILE *fp = fopen("testfiles/file.txt", "r");

//     // if (fgets(str, 5, fp)) {
//     //     puts(str);
//     // }
//     // func(4, 7, 9, 11, 14, 18);
//     printf("%d %d %d", sqr(5), sqr(4 + 1), sqr(3 + 2));
// }

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr, jumlah = 0;

    printf("Masukkan ");
    scanf("%d", &n);

    ptr = calloc(n, sizeof(int));

    if (ptr == NULL) exit(0);

    printf("Mauskkan %d a ", n);

    for (i = 0; i < n; ++i) {
        scanf("%d", ptr + i);
        jumlah += *(ptr + i);
    }
    printf("%d", jumlah);
    return 0;
}