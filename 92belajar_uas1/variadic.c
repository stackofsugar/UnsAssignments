#include <stdio.h>
#include <stdarg.h>

int intSum(int argc, ...) {
    int sum_ret = 0;
    va_list args;
    va_start(args, argc);

    for (int i = 0; i < argc; i++) {
        sum_ret += va_arg(args, int);
    }

    va_end(args);
    return sum_ret;
}

void simplePrintf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '0') {
        if (*format == 'd') {
            printf("%d ", va_arg(args, int));
        }
        else if (*format == 'c') {
            printf("%c ", va_arg(args, int));
        }
        else if (*format == 'f') {
            printf("%lf ", va_arg(args, double));
        }
        else if (*format == 's') {
            printf("%s ", va_arg(args, const char *));
        }
        else if (*format == 'n') {
            printf("%c", '\n');
        }
        format++;
    }

    va_end(args);
}

int main() {
    printf("%d\n", intSum(5, 1, 3, 4, 7, 8));
    simplePrintf("dcfsfn", 5, 'A', 69.69, "helo", 7.09);
}
