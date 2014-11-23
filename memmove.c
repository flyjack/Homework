#include <stdio.h>

//需判断src和dst的内存拷贝存在重叠的情况
//对于copy操作的时候，一般是将参数重新进行赋值到另一变量空间上，便于指针移动操作
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
