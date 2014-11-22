#include <stdio.h>

//异或相同的数2次，返回原值
#define SWAPVAL(a, b) a = a ^ b; \
                      b = a ^ b; \
                      a = a ^ b;

//char *a 可以表示一个字符串也可以表示一个字符，a是指针，*a是内容
void swapFun(char *a, char *b)
{
    char m = *a;
    *a = *b;
    *b = m;
}

void reverse(char str[])
{
    int i = 0;
    //strlen 是实际字符串的长度，但如果用sizeof会包含\0, 同时又因为下标从0开始，所以长度减2
    int j = (sizeof(str) / sizeof(char)) - 2;

    //不能放在while循环中的i++,j--,因为下面在访问为变化后的下标
    while (i <= j)
    {
        swapFun(&str[i], &str[j]);
        i++;
        j--;
    }
}

int main()
{
    char a[] = "abcdefg";
    reverse(a);
    printf("%s\n", a);

    char m = 'm';
    char n = 'n';
    SWAPVAL(m, n);
    printf("%c, %c\n", m, n);
}
