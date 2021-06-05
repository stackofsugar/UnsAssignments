#include <stdio.h>
void tukar(int p, int r);
main()
{
    int a = 100, b = 200;
    printf("a = %d b = %d\n", a, b);
    tukar(a, b);
    printf("a = %d b = %d\n", a, b);
    return 0;
}
void tukar(int p, int r)
{
    int sementara;
    sementara = p;
    p = r;
    r = sementara;
}