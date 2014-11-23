#include <stdio.h>

//需判断src和dst的内存拷贝存在重叠的情况
//对于copy很多时候是将变量重新分配到一个变量上进行
//另外copy n个长度的内容，实际上移动的数目是n-1
void * memmove(void *dst1, const void *src1, size_t n)
{
    char *dst = dst1;
    const char *src = src1;

    if (dst == src)
        return dst;

    if (dst < src)
    {
        while (n--)
            *dst++ = *src++;
    }

    if (dst > src)
    {
        dst = dst1 + n;
        src = src1 + n;

        while (n--)
            *--dst = *--src;
    }

    return dst1;
}

int main()
{
    char a[] = "abcdefg";
    char *m = memmove(a+2, a, 3);
    printf("%s\n", m);
    printf("%s\n", a);

    return 0;
}
