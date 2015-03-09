/*
动态给二维数组申请空间
1. 二维指针(空间不连续) 2. 指针数组 3. 数组指针
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//一个m行n列的二维数组
int ** getMem(int m, int n)
{
    int **p = (int **)malloc(sizeof(int *) * m);

    int i = 0;
    int j = 0;

    for (;i<m;i++)
    {
        *(p+i) = (int *)malloc(sizeof(int) * n);
    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            *(*(p+i)+j) = i*n+j;
            printf("%d ", *(*(p+i)+j));
        }

        printf("\n");
    }

    return p;
}

int main()
{
    int ** arr = getMem(3, 4);
    
    int m = 3;
    int n = 4;
    int i,j;

    printf("main func print\n");

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", *(*(arr+i)+j));
        }

        free(*(arr+i));

        printf("\n");
    }

    return 0;
}
