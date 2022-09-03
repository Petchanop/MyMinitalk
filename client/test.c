#include "../minitalk.h"

int main(void)
{
    unsigned char   c;
    unsigned char   d;
    unsigned char   e;

    c = 0;
    e = 0;
    d = 1;
    
    //printf("%d, %d\n", c += 0 << 8, 0);
    printf("%d, %d\n", c += 1 << 7, 1);
    printf("%d, %d\n", c += 1 << 6, 1);
    printf("%d, %d\n", c += 1 << 5, 1);
    printf("%d, %d\n", c += 0 << 4, 0);
    printf("%d, %d\n", c += 1 << 3, 1);
    printf("%d, %d\n", c += 0 << 2, 0);
    printf("%d, %d\n", c += 0 << 1, e);
    printf("%d, %d\n", c += 0 << 0, e);
}