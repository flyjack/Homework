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

char const * my_strstr(char const *str, char const *s)
{
    if (s == NULL)
        return str;

    if (str == NULL)
        return NULL;

    char const *s2 = s;

    //字符串的查找需要原字符串从开头一个字符一个字的添加查找开始
    while (*str++ != '\0')
    {
        char *s1 = strchr(str, *s2);

        if (s1 == NULL)
            return NULL;

        int m = 0;

        while (*s2 != '\0')
        {
            if (*s1 != *s2)
                break;

            s2++;
            s1++;
            m++;
        }

        if (*s2 == '\0')
            return s1 - m;

        //重新赋值g
        s2 = s;
    }

    if (*str == '\0')
        return NULL;
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
