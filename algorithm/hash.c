#include <stdio.h>

//Times33的hash算法
unsigned int hash(const char *s)
{
    register unsigned int hash = 5381;
    char *m = s;

    while (*m)
    {
        hash += (hash << 5) + (*m++);
    }

    return (hash & 0x7FFFFFFF);
}

int main()
{
    
    const char *a[3] = {
        "baidu",
        "baido",
        "baiou"
    };

    int i = 0;
    for (; i<3; i++)
    {
        unsigned int h = hash(a[i]);
        printf("%u\n", h);
    }

    return 0;
}
