/**********************************************************
**** 位图的操作不仅可排重而且还可对排重的内容排序，能使得时间和空间最优化，而不用空间换时间
**** @0: 位操作符基础: m << n , m >> n 表示m左(右)移n位； 
*****     m & n, m | n, m ^ n  只有当比较的二进制位都为1(有一个为1，两者相异时)时结果才为1
**** @1: m mod n, 当n为2^k时，m mod n等于m & (2^k -1), 且一般使用的是字节，所以2^k-1为31，即0x1F
**** @2: 判断数num的某一个位是否为1
     bitmap[num>>5] & (1 << (m & (2 ^k -1))
**** @3: 设置 数num的某位为1
     bitmap[num>>5] |= (1 << (m & 0x1f))
     
     @4: 判断某数的shiftlen位是1还是0： 
        int temp = (result[index] >> shiftlen) & 1;
        if ((temp % 2) == 1)
***********************************************************/

1. 一个字符串，如“ab8iopbyuapo”，输出排重后的结果，且需要按照asicc排序。
#include <stdio.h>

int main()
{
    char src_str[] = "ab8iopbyuapo";
    char dst_str[20] = {'\0'};
    char *p = dst_str;

    printf("Src is %s\n", src_str);

    int i = 0;
    int len = sizeof(src_str) / sizeof(char);
    int bitmap[256/32] = {0};

    for (; i<len-1; i++)
    {
        char s = src_str[i];
        int a = (int)s;

        int index = a/32;

        if ((bitmap[index] & (1 << (a & 31))) == 0)
            bitmap[index] |= (1 << (a & 31));
    }

    for (i=0; i<8; i++)
    {
        if (bitmap[i] != 0)
        {
            int k = -1;

            while (k++ < 32)
            {
                if ((bitmap[i] & (1 << k)))
                {
                    char cx = (char)(i*32 + k);
                    *p++ = cx;
                }
            }
        }
    }

    printf("Result is %s\n", dst_str);
}

2. 100亿的数据，但排重后为12亿多，内存有限的情况下(200M)解决此问题。
3. 两个数组求其交集
