#include <stdio.h>

typedef char uint8;

uint8 get_count1(uint8 a)
{
    int count = 0;

    while (a)
    {
        count += a & 0x01;
        a >>= 1;
    }

    printf("%u",count);
}

uint8 get_count2(uint8 a)
{
    int count = 0;

    while (a)
    {
        a &= (a-1);
        count++;
    }

    printf("%u",count);
}

int main()
{
    uint8 a = 65;

    get_count1(a);

    return 0;
}
