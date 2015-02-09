//2.1 统计二进制数中1的个数
//get_count1为普通的算法。O(log2V)，即最高位1的位置，get_count2为较优算法，复杂度取决于1的个数。

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
    get_count2(a);

    return 0;
}
